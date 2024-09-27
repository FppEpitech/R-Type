/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#pragma once

#include <unordered_map>

#include <jsoncpp/json/json.h>

#include "ISystem.hpp"
#include "StringKeyMap.hpp"

#define FIRST_SCENE "firstScene.json"
#define SCENE_PATH "Client/config/scenes/"
#define LIB_COMPONENTS_PATH "Client/lib/components/"
#define LIB_SYSTEMS_PATH "Client/lib/systems/"

#define CONFIG_SUFFIX ".json"
#define LIB_SUFFIX ".so"

/**
 * @brief Namespace for the scene manager.
 * This namespace contains all the classes or enums that are related to the scene management.
 */
namespace SceneManager {

    /**
     * @brief Client ClientSceneManager class.
     * It manages the scenes of the game and the transitions between them.
     */
    class ClientSceneManager {

        public:

            /**
             * @brief Construct a new ClientSceneManager object.
             * @param registries Registries for each scene.
             *
             */
            ClientSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries);

            /**
             * @brief Destroy the ClientSceneManager object.
             *
             */
            ~ClientSceneManager() = default;

        private:

            std::shared_ptr<std::vector<ECS::Registry>> _registries; // Registries for each scene
            std::vector<std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>> _keysRegistry; // Keys of each scene

            std::size_t _registerIndex; // Index of the current registry

            /**
             * @brief Load a scene from a json file.
             * @param path Path to the json file.
             * @param index Index of the registry to load the scene.
             */
            void _loadScene(const std::string &path, std::size_t index);

            /**
             * @brief Load the components of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneComponents(Json::Value root, std::size_t index);

            /**
             * @brief Load the systems of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneSystems(Json::Value root, std::size_t index);

            /**
             * @brief Load the keys of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneKeys(Json::Value root, std::size_t index);

    };
}
