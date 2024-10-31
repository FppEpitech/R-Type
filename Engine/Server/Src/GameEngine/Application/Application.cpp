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
    _server = ABINetwork::createServer(MAX_NUMBER_PLAYERS);
    _nbRoom = 0;
}

void GameEngine::Application::run()
{
    while (true) {
        _packetHandler();
        ABINetwork::sendMessages(_server);
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
    ABINetwork::sendPacketRooms(_server, roomInfos, packet.getToken());
}

void GameEngine::Application::_handleCreateRoom(ABINetwork::UDPPacket packet)
{
    if (_nbRoom >= MAX_NUMBER_ROOMS)
        return;
    else {
        ABINetwork::roomInfo_t roomInfo = ABINetwork::getCreateRoomInfoFromPacket(packet);
        try {
            std::shared_ptr<GameEngine::Room> newRoom = std::make_shared<GameEngine::Room>(roomInfo);
            if (!newRoom)
                return;
            _rooms[roomInfo.name] = newRoom;
            _nbRoom++;
            _threads.push_back(std::make_shared<std::thread>([newRoom, this]() { newRoom->run(_roomCreationMutex); }));
            ABINetwork::sendPacketRoomCreated(_server, newRoom->getRoomInfo(), packet.getToken());
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
}

void GameEngine::Application::_handleJoinRoom(ABINetwork::UDPPacket packet)
{
    std::pair<std::string, std::string> joinRoomInfos = ABINetwork::getJoinRoomInfoFromPacket(packet);

    if (_rooms[joinRoomInfos.first]->getRoomInfo().password != joinRoomInfos.second) {
        ABINetwork::sendPacketWrongRoomPassword(_server, packet.getToken());
        return;
    }
    if (_rooms[joinRoomInfos.first]->getRoomInfo().playerMax <= _rooms[joinRoomInfos.first]->getNumberOfPlayers()) {
        ABINetwork::sendPacketFullRoom(_server, packet.getToken());
        return;
    }
    ABINetwork::sendPacketAllowedToJoinRoom(_server, _rooms[joinRoomInfos.first]->getRoomInfo().tcpPort, packet.getToken());
}

void GameEngine::Application::_handleLogin(ABINetwork::UDPPacket packet)
{
    std::pair<std::string, std::string> loginInfos = ABINetwork::getLoginInfoFromPacket(packet);

    // TODO : Check in the dataBase if login exist
    // For the moment send always true.
    ABINetwork::sendPacketLoginAllowed(_server, true, packet.getToken());
}

void GameEngine::Application::_handleRegister(ABINetwork::UDPPacket packet)
{
    std::pair<std::string, std::string> registerInfos = ABINetwork::getRegisterInfoFromPacket(packet);

    // TODO : Register the client in the database.
}
