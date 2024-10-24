/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#pragma once

#include "ASceneManager.hpp"

#define FIRST_SCENE "firstScene.json"

#define LIB_COMPONENTS_PATH "Engine/"
#define LIB_SYSTEMS_PATH "Engine/"
#define LIB_EVENT_HANDLERS_PATH "Engine/"
#define SCENE_PATH "GameData/Scenes/"

/**
 * @brief Namespace for the scene manager.
 * This namespace contains all the classes or enums that are related to the scene management.
 */
namespace SceneManager {

    /**
     * @brief Server ServerSceneManager class.
     * It manages the scenes of the game and the transitions between them.
     */
    class ServerSceneManager : public ASceneManager {

        public:

            /**
             * @brief Construct a new ServerSceneManager object.
             * @param registries Registries for each scene.
             */
            ServerSceneManager(std::shared_ptr<ECS::Registry> registries, std::shared_ptr<EventListener> eventListener);

            /**
             * @brief Destroy the ServerSceneManager object.
             *
             */
            ~ServerSceneManager() = default;

        private:

            /**
             * @brief Get the Component Lib Path.
             * @return The path to the component libraries.
             */
            std::string _getComponentLibPath() const override;

            /**
             * @brief Get the System Lib Path.
             * @return The path to the system libraries.
             */
            std::string _getSystemLibPath() const override;

            /**
             * @brief Get the Event Handler Lib Path.
             * @return The path to the event handler libraries.
             */
            std::string _getEventHandlerLibPath() const override;

            /**
             * @brief Get the Scenes Path.
             * @return The path to the scenes.
             */
            std::string _getScenesPath() const override;

            /**
             * @brief Load the scene.
             * @param path Path to the scene.
             * @param index Index of the scene.
             */
            void _loadScene(const std::string &path, std::size_t index) override;
    };
}
