/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Room
*/

#include "Room.hpp"

GameEngine::Room::Room(ABINetwork::roomInfo_t roomInfo)
{
    if (roomInfo.name.empty())
        throw RoomError("A room must has a name");
    if (roomInfo.isPrivate && roomInfo.password.empty())
        throw RoomError("A private room must has a password");
    _roomInfos = roomInfo;

    _roomServer = ABINetwork::createServer(_roomInfos.playerMax);
    if (!_roomServer)
        throw RoomError("Error while creating a room");
    _registries = std::make_shared<ECS::Registry>();
    _registries->identity = ECS::Registry::Identity::Serveur;

    _eventListener = std::make_shared<EventListener>(_registries, nullptr, _roomServer, nullptr);
    _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries, _eventListener);
    _eventListener->setSceneManager(_sceneManager);

    _isRoomOpen = true;
    _numberPlayers = 0;

    std::pair<int, int> roomPorts = _roomServer->getPorts();
    _roomInfos.tcpPort = roomPorts.first;
    _roomInfos.udpPort = roomPorts.second;
}

void GameEngine::Room::run(std::mutex &mutex)
{
    while (_isRoomOpen) {
        _numberPlayers = _roomServer->getNumberClient();
        _packetHandler();
        _connectionHandler();
        _runSystems();
        ABINetwork::sendMessages(_roomServer);
    }
}

void GameEngine::Room::_runSystems()
{
    static std::chrono::high_resolution_clock::time_point lastCall = std::chrono::high_resolution_clock::now();
    const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    double timeElapsed = std::chrono::duration<double, std::milli>(now - lastCall).count() / 1000;
    if (timeElapsed < 0.005)
        return;
    _eventListener->listen();
    _registries->run_systems(SERVER);
    lastCall = std::chrono::high_resolution_clock::now();
}

void GameEngine::Room::_connectionHandler()
{
    std::vector<std::pair<uint32_t, bool>>& queueConnection = ABINetwork::getQueueConnection(_roomServer);

    while (!queueConnection.empty()) {
        if (queueConnection.front().second == false)
            break;
        uint32_t tokenConnection = queueConnection.front().first;
        queueConnection.erase(queueConnection.begin());
        std::cout << "Player with token: 0x" << std::hex << std::setw(8) << std::setfill('0') << tokenConnection << std::dec << " want to connect" << std::endl;

        _roomInfos.nbPlayers++;

        ECS::SparseArray<IComponent> PlayerComponentArray = this->_registries->get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> DrawComponentArray = this->_registries->get_components<IComponent>("DrawComponent");

        for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
            std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(PlayerComponentArray[index]);
            if (player && player->token == 0) {
                player->token = tokenConnection;
                ABINetwork::sendPacketAssignToken(_roomServer, index, tokenConnection);

                if (index < DrawComponentArray.size()) {
                    std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(DrawComponentArray[index]);
                    if (draw)
                        draw->draw = true;

                    std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args;

                    args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(index)));
                    args.push_back(std::make_pair(ABINetwork::Type::Bool, true));

                    ABINetwork::sendUpdateComponent(_roomServer, "DrawComponent", 2, args);

                    for (std::size_t i = 0; i < PlayerComponentArray.size(); i++) {
                        std::shared_ptr<PlayerComponent> playerInfo = std::dynamic_pointer_cast<PlayerComponent>(PlayerComponentArray[i]);
                        if (playerInfo && playerInfo->token != 0) {
                            std::shared_ptr<DrawComponent> drawInfo = std::dynamic_pointer_cast<DrawComponent>(DrawComponentArray[i]);
                            std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> argsUpdate;
                            argsUpdate.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(i)));
                            argsUpdate.push_back(std::make_pair(ABINetwork::Type::Bool, drawInfo->draw));
                            ABINetwork::sendUpdateComponent(_roomServer, "DrawComponent", 2, argsUpdate, player->token);
                        }
                    }
                }
                break;
            }
        }
    }
}

void GameEngine::Room::_packetHandler()
{
    std::lock_guard<std::mutex> lock(_roomServer->getMutex());

    std::vector<ABINetwork::UDPPacket> messages = _roomServer->getReceivedMessages();

    for (auto packet : messages) {

        try {
            auto messageType = static_cast<ABINetwork::IMessage::MessageType>(packet.getMessageType());
            if (_handlePacketsMap.find(ABINetwork::IMessage::MessageType(messageType)) != _handlePacketsMap.end())
                _handlePacketsMap[ABINetwork::IMessage::MessageType(messageType)](packet);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void GameEngine::Room::_handleInit(ABINetwork::UDPPacket packet)
{
    int idxPlayerPacket = -1;
    ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
    for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
        std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(PlayerComponentArray[index]);
        if (player && player->token == packet.getToken()) {
            idxPlayerPacket = index;
            break;
        }
    }
    uint8_t initKey = packet.getPayload()[0];
    std::vector<std::pair<uint32_t, bool>>& queueConnection = ABINetwork::getQueueConnection(_roomServer);
    for (auto& value : queueConnection)
        if (value.first == packet.getToken())
            value.second = true;
}

void GameEngine::Room::_handleKey(ABINetwork::UDPPacket packet)
{
    int idxPlayerPacket = -1;
    ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
    for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
        std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(PlayerComponentArray[index]);
        if (player && player->token == packet.getToken()) {
            idxPlayerPacket = index;
            break;
        }
    }
    uint8_t keyCode = packet.getPayload()[0];
    _sceneManager->processInput(KEY_MAP(keyCode), idxPlayerPacket);
}

void GameEngine::Room::_handleLeaveRoom(ABINetwork::UDPPacket packet)
{
    ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
    for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
        std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(PlayerComponentArray[index]);
        if (player && player->token == packet.getToken()) {
            _roomInfos.nbPlayers--;
            break;
        }
    }
}

const int GameEngine::Room::getNumberOfPlayers()
{
    return _numberPlayers;
}

const ABINetwork::roomInfo_t GameEngine::Room::getRoomInfo()
{
    return _roomInfos;
}
