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
        _waitingForRoomCreation();
    }
}

void GameEngine::Application::_waitingForRoomCreation()
{
    // std::lock_guard<std::mutex> lock(_server->getMutex());
    // for (auto queue : _interProcessQueues) {
    //     if (_playerWaitingRoomCreation.find(std::get<0>(queue)) == _playerWaitingRoomCreation.end())
    //         continue;
    //     std::cout << "YAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
    //     _playerWaitingRoomCreation[std::get<0>(queue)].second.tcpPort = std::get<1>(queue);
    //     _playerWaitingRoomCreation[std::get<0>(queue)].second.udpPort = std::get<2>(queue);
    //     ABINetwork::sendPacketRoomCreated(_server, _playerWaitingRoomCreation[std::get<0>(queue)].second);
    //     _playerWaitingRoomCreation.erase(std::get<0>(queue));
    // }
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
            std::shared_ptr<GameEngine::Room> newRoom = std::make_shared<GameEngine::Room>(roomInfo, _interProcessQueues, _roomCreationMutex);
            // _rooms[roomInfo.name] = newRoom;
            // _nbRoom++;
            _threads.push_back(std::make_shared<std::thread>([&newRoom]() { newRoom->run(); }));
            // std::cout << "haha" << std::endl;
            // _playerWaitingRoomCreation[roomInfo.name] = {packet.getToken(), roomInfo};
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

    if (_rooms[joinRoomInfos.first]->getPassword() != joinRoomInfos.second) {
        ABINetwork::sendPacketWrongRoomPassword(_server);
        return;
    }
    if (_rooms[joinRoomInfos.first]->getMaxPlayers() <= _rooms[joinRoomInfos.first]->getNumberOfPlayers()) {
        ABINetwork::sendPacketFullRoom(_server);
        return;
    }
    ABINetwork::sendPacketAllowedToJoinRoom(_server);
}
