/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#pragma once

#include "ASceneManager.hpp"

#define FIRST_SCENE "firstScene.json"

#define LIB_COMPONENTS_PATH "Engine/Client/Lib/Components/"
#define LIB_SYSTEMS_PATH "Engine/Client/Lib/Systems/"
#define SCENE_PATH "Engine/Client/Config/Scenes/"

/**
 * @brief Namespace for the scene manager.
 * This namespace contains all the classes or enums that are related to the scene management.
 */
namespace SceneManager {

    /**
     * @brief Client ClientSceneManager class.
     * It manages the scenes of the game and the transitions between them.
     */
    class ClientSceneManager : public ASceneManager {

        public:

            /**
             * @brief Construct a new ClientSceneManager object.
             * @param registries Registries for each scene.
             */
            ClientSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries);

            /**
             * @brief Destroy the ClientSceneManager object.
             */
            ~ClientSceneManager() = default;

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

