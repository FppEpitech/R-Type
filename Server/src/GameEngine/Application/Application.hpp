/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#pragma once

#include "Registry.hpp"
#include "SceneManager/SceneManager.hpp"

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

        //TODO: Network class

        std::shared_ptr<std::vector<ECS::Registry>>     _registries;        // vector of registries class for ECS management.
        std::shared_ptr<GameEngine::SceneManager>       _sceneManager;      // load and handle scene in the ECS.
};

} // namespace GameEngine
