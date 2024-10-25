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

    _nameRoom = roomInfo.name;
    _private = roomInfo.isPrivate;
    _passwordRoom = roomInfo.password;
    _maxPlayers = roomInfo.playerMax;
    _cheats = roomInfo.cheats;

    _roomServer = ABINetwork::createServer(_maxPlayers);
    _registries = std::make_shared<ECS::Registry>();
    _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries);
    _isRoomOpen = true;
    _numberPlayers = 0;
}

void GameEngine::Room::_packetHandler()
{
    std::lock_guard<std::mutex> lock(_roomServer->getMutex());

    std::vector<ABINetwork::UDPPacket> messages = _roomServer->getReceivedMessages();

    for (auto packet : messages) {

        auto messageType = static_cast<ABINetwork::IMessage::MessageType>(packet.getMessageType());

        if (ABINetwork::IMessage::MessageType(messageType) == ABINetwork::IMessage::MessageType::KEY) {

            int idxPlayerPacket = -1;
            ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
            for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
                PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
                if (player && player->token == packet.getToken()) {
                    idxPlayerPacket = index;
                    break;
                }
            }
            uint8_t keyCode = packet.getPayload()[0];
            _sceneManager->processInput(KEY_MAP(keyCode), idxPlayerPacket);
            continue;
        }
    }
}

void GameEngine::Room::run()
{
    while (_isRoomOpen) {
        _packetHandler();
        _registries->run_systems(-1);
    }
}

const std::string GameEngine::Room::getPassword()
{
    return _passwordRoom;
}

const int GameEngine::Room::getNumberOfPlayers()
{
    return _numberPlayers;
}

const int GameEngine::Room::getMaxPlayers()
{
    return _maxPlayers;
}
