/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#pragma once

#include "ASceneManager.hpp"

#define FIRST_SCENE "firstScene.json"

#define LIB_COMPONENTS_PATH "Server/lib/components/"
#define LIB_SYSTEMS_PATH "Server/lib/systems/"
#define SCENE_PATH "Server/config/scenes/"

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
            ServerSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries);

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
             * @brief Get the Scenes Path.
             * @return The path to the scenes.
             */
            std::string _getScenesPath() const override;
    };
}
