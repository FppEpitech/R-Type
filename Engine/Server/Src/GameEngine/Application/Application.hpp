/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#pragma once

#include "Registry.hpp"
#include "ABIServer.hpp"
#include "ServerSceneManager.hpp"

#ifdef _WIN32
        #define SLEEP(x) Sleep(x)
#else
        #define SLEEP(x) sleep(x)
#endif

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

        std::shared_ptr<ECS::Registry>                              _registries;        // vector of registries class for ECS management.
        std::shared_ptr<SceneManager::ServerSceneManager>           _sceneManager;      // load and handle scene in the ECS.
        std::shared_ptr<ABINetwork::INetworkUnit>                   _server;            // Network class for server.
};

} // namespace GameEngine
