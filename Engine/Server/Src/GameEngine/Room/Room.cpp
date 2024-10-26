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
    _registries = std::make_shared<ECS::Registry>();

    // TODO: Add the network unit to the event listener
    _eventListener = std::make_shared<EventListener>(_registries, nullptr, nullptr, nullptr);
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
        _registries->run_systems(-1);
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
            player->token = 0;
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
