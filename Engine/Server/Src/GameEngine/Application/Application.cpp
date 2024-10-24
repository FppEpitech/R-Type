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

void GameEngine::Application::_packetHandler()
{
    std::lock_guard<std::mutex> lock(_server->getMutex());
    std::vector<ABINetwork::UDPPacket> messages = _server->getReceivedMessages();

    for (auto packet : messages) {
        auto messageType = static_cast<ABINetwork::IMessage::MessageType>(packet.getMessageType());
        _handlePacketsMap[ABINetwork::IMessage::MessageType(messageType)](packet);
    }
}

void GameEngine::Application::_handleGetRoom(ABINetwork::UDPPacket packet)
{
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
            GameEngine::Room newRoom(roomInfo);
            _rooms.push_back(newRoom);
            _nbRoom++;
            _threads.push_back(std::make_shared<std::thread>([&newRoom]() { newRoom.run(); }));
        } catch (const std::exception& e) {
        //     sendErrorRoomPacket();
            std::cerr << e.what() << std::endl;
            return;
        }
    }
}

void GameEngine::Application::run()
{
    while (true) {
        _packetHandler();
    }
}
