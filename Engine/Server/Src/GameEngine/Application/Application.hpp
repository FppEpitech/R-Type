/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#pragma once

#include "Room.hpp"
#include "ABIServer.hpp"
#include "ServerSceneManager.hpp"

#include <queue>
#include <unordered_map>
#include <functional>

#ifdef _WIN32
        #define SLEEP(x) Sleep(x)
#else
        #define SLEEP(x) sleep(x)
#endif

#define MAX_NUMBER_ROOMS 4

/**
 * @brief GameEngine namespace handle all
 * classes of the GameEngine part of the server.
 *
 */
namespace GameEngine {

/**
 * @brief Main application of the GameEngine.
 * It handle network and ECS to run a game.
 *
 */
class Application {

    public:

        /**
         * @brief Construct a new Application object.
         *
         */
        Application();

        /**
         * @brief Destroy the Application object.
         *
         */
        ~Application() = default;

        /**
         * @brief Run the Application.
         * It use the SceneManager and registry.
         *
         */
        void run();

    private:

        void _waitingForRoomCreation();

        /**
         * @brief Function who handle the packets received.
         *
         */
        void _packetHandler();

        /**
         * @brief Handle the packet GET_ROOM.
         *
         * @param packet Packet to handle.
         */
        void _handleGetRoom(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle the packet CREATE_ROOM.
         *
         * @param packet Packet to handle.
         */
        void _handleCreateRoom(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle the packet JOIN_ROOM.
         *
         * @param packet Packet to handle.
         */
        void _handleJoinRoom(ABINetwork::UDPPacket packet);

        std::shared_ptr<ABINetwork::INetworkUnit>                   _server;            // Network class for server.

        std::size_t                                                             _nbRoom;            // Number of current rooms in the server.
        std::unordered_map<std::string, std::shared_ptr<GameEngine::Room>>      _rooms;             // List of rooms.
        std::vector<std::shared_ptr<std::thread>>                               _threads;           // Vector of threads
        std::vector<std::tuple<std::string, int, int>>                          _interProcessQueues;
        std::unordered_map<std::string, std::pair<uint32_t, ABINetwork::roomInfo_t>>    _playerWaitingRoomCreation;
        std::mutex                                                              _roomCreationMutex; // Mutex for room creation.

        std::unordered_map<ABINetwork::IMessage::MessageType, std::function<void(ABINetwork::UDPPacket)>> _handlePacketsMap = {
            {ABINetwork::IMessage::MessageType::GET_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleGetRoom(packet); }},
            {ABINetwork::IMessage::MessageType::CREATE_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleCreateRoom(packet); }},
            {ABINetwork::IMessage::MessageType::JOIN_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleJoinRoom(packet); }}
        };
};

} // namespace GameEngine
