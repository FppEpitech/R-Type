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

        /**
         * @brief Function who handle the packets received.
         *
         */
        void _packetHandler();

        /**
         * @brief Check if no player are connected.
         *
         * @return true No player connected.
         * @return false One or more players connected.
         */
        bool noPlayerConnected();

        void _handleGetRoom(ABINetwork::UDPPacket packet);
        void _handleCreateRoom(ABINetwork::UDPPacket packet);

        std::shared_ptr<ABINetwork::INetworkUnit>                   _server;            // Network class for server.

        std::size_t                                                 _nbRoom;            // Number of current rooms in the server.
        std::vector<GameEngine::Room>                               _rooms;             // List of rooms.
        std::vector<std::shared_ptr<std::thread>>                   _threads;           // Vector of threads
        std::vector<std::pair<std::shared_ptr<std::queue<std::string>>, std::shared_ptr<std::queue<std::string>>>> _interProcessQueues;

        std::unordered_map<ABINetwork::IMessage::MessageType, std::function<void(ABINetwork::UDPPacket)>> _handlePacketsMap = {
            {ABINetwork::IMessage::MessageType::GET_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleGetRoom(packet); }},
            {ABINetwork::IMessage::MessageType::CREATE_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleCreateRoom(packet); }}
        };
};

} // namespace GameEngine
