/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#include "Application.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

GameEngine::Application::Application()
{
    _server = ABINetwork::createServer(100);
    _nbRoom = 0;
}

void GameEngine::Application::run()
{
    while (true) {
        _packetHandler();
    }
}

void GameEngine::Application::_packetHandler()
{
    std::lock_guard<std::mutex> lock(_server->getMutex());
    std::vector<ABINetwork::UDPPacket> messages = _server->getReceivedMessages();

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

void GameEngine::Application::_handleGetRoom(ABINetwork::UDPPacket packet)
{
    std::vector<ABINetwork::roomInfo_t> roomInfos;
    for (auto room : _rooms)
        roomInfos.push_back(room.second->getRoomInfo());
    ABINetwork::sendPacketRooms(_server, roomInfos);
}

void GameEngine::Application::_handleCreateRoom(ABINetwork::UDPPacket packet)
{
    if (_nbRoom >= MAX_NUMBER_ROOMS) {
        // sendErrorRoomPacket();
        return;
    }
    else {
        ABINetwork::roomInfo_t roomInfo = ABINetwork::getCreateRoomInfoFromPacket(packet);
        try {
            std::shared_ptr<GameEngine::Room> newRoom = std::make_shared<GameEngine::Room>(roomInfo);
            if (!newRoom) {
                // sendErrorRoomPacket();
                return;
            }
            _rooms[roomInfo.name] = newRoom;
            _nbRoom++;
            _threads.push_back(std::make_shared<std::thread>([newRoom, this]() { newRoom->run(_roomCreationMutex); }));
            ABINetwork::sendPacketRoomCreated(_server, newRoom->getRoomInfo());
        } catch (const std::exception& e) {
            // sendErrorRoomPacket();
            std::cerr << e.what() << std::endl;
            return;
        }
    }
}

void GameEngine::Application::_handleJoinRoom(ABINetwork::UDPPacket packet)
{
    std::pair<std::string, std::string> joinRoomInfos = ABINetwork::getJoinRoomInfoFromPacket(packet);

    if (_rooms[joinRoomInfos.first]->getRoomInfo().password != joinRoomInfos.second) {
        ABINetwork::sendPacketWrongRoomPassword(_server);
        return;
    }
    if (_rooms[joinRoomInfos.first]->getRoomInfo().playerMax <= _rooms[joinRoomInfos.first]->getNumberOfPlayers()) {
        ABINetwork::sendPacketFullRoom(_server);
        return;
    }
    ABINetwork::sendPacketAllowedToJoinRoom(_server);
}

//     _registries = std::make_shared<ECS::Registry>();

//     // TODO: Add the network unit to the event listener
//     _eventListener = std::make_shared<EventListener>(_registries, nullptr, nullptr, nullptr);

//     _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries, _eventListener);

//     _eventListener->setSceneManager(_sceneManager);

//     _server = std::make_shared<Network::Server>(4444, 4445);
//     _server->start([this](Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint, std::shared_ptr<ECS::Registry> reg) {
//         this->_packetHandler(std::move(packet), endpoint, reg);
//     }, _registries);
// }
