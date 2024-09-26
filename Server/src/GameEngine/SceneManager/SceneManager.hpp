/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#pragma once

#define DEFAULT_SCENE_PATH      "config/scenes/games/default.json"
#define LIB_COMPONENTS_PATH     "Server/lib/components/"
#define LIB_SYSTEMS_PATH        "Server/lib/systems/"

#include "Registry.hpp"

#include <string>
#include <unordered_map>
#include "json/json.h"

/**
 * @brief GameEngine namespace handle all
 * classes of the GameEngine part of the server.
 *
 */
namespace GameEngine {

class SceneManager {

    public:

        SceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries);
        ~SceneManager();

        void processInput(const std::string &input);

    protected:

    private:

        std::unordered_map<std::string, std::string> _sceneKeys; // The second string will be a system
        // std::unordered_map<std::string, std::string> _sceneComponents; // The second string will be a component

        void _loadScene(const std::string &path, int idxRegister);
        void _loadSceneKeys(Json::Value root, int idxRegister);
        void _loadSceneComponents(Json::Value root, int idxRegister);
        void _loadSceneSystems(Json::Value root, int idxRegister);
        void _changeScene(const std::string &sceneName);

        std::shared_ptr<std::vector<ECS::Registry>>     _registries;
        std::size_t                                     _indexRegister;
};

}
