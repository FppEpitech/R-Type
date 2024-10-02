/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#pragma once

#include "Registry.hpp"
#include "NetworkServer.hpp"
#include "ServerSceneManager.hpp"

enum class MessageType : uint8_t {
    ArrowKey    = 0x01,  // Arrow
    AlphaKey    = 0x02,  // Alpha (A-Z)
    NumberKey   = 0x03,  // Number (0-9)
    SpecialKey  = 0x04   // Special (Ctrl, Alt, etc.)
};

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
         * @brief Function to handle Arrow key.
         *
         * @param keyCode Key Code send by the client
         * @param idxPlayerPacket Index of Player who send the packet.
         */
        void _handleArrowKey(uint8_t keyCode, int idxPlayerPacket);

        /**
         * @brief Function to handle Alpha key.
         *
         * @param keyCode Key Code send by the client
         * @param idxPlayerPacket Index of Player who send the packet.
         */
        void _handleAlphaKey(uint8_t keyCode, int idxPlayerPacket);

        /**
         * @brief Function to handle Number key.
         *
         * @param keyCode Key Code send by the client
         * @param idxPlayerPacket Index of Player who send the packet.
         */
        void _handleNumberKey(uint8_t keyCode, int idxPlayerPacket);

        /**
         * @brief Function to Special key.
         *
         * @param keyCode Key Code send by the client
         * @param idxPlayerPacket Index of Player who send the packet.
         */
        void _handleSpecialKey(uint8_t keyCode, int idxPlayerPacket);

        /**
         * @brief Callback function who handle the packet receive.
         *
         * @param packet Packet to be handle in this function.
         * @param endpoint Endpoint of the client who send the packet.
         * @param reg Registry with list of Component and system.
         */
        void _packetHandler(Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint, ECS::Registry& reg);

        std::shared_ptr<std::vector<ECS::Registry>>             _registries;        // vector of registries class for ECS management.
        std::shared_ptr<SceneManager::ServerSceneManager>       _sceneManager;      // load and handle scene in the ECS.
        std::shared_ptr<Network::Server>                        _server;            // Network class for server.
};

} // namespace GameEngine
