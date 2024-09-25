/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Errors/ServerErrors.hpp"

#include <fstream>
#include "json/json.h"

SceneManager::SceneManager()
{
    try {
        _loadScene(DEFAULT_SCENE_PATH);
    } catch (const SceneManagerError &e) {
        throw SceneManagerError(e.what());
    }
}

SceneManager::~SceneManager()
{
}

void SceneManager::processInput(const std::string &input)
{
    // for (auto &scene : _sceneKeys) {
    //     if (scene.first == input) {
    //         // Call the system
    //     }
    // }
}

void SceneManager::_loadSceneKeys(const std::string &path)
{
    // std::ifstream file(path);
    // Json::Reader reader;
    // Json::Value root;

    // if (!reader.parse(file, root, false))
    //     throw SceneManagerError("Error while parsing the scene file" + path);
    // for (auto &keybind : root["keyBinds"]) {
    //     if (keybind["usage"].asString().find('/') != std::string::npos)
    //         _sceneKeys[keybind["key"].asString()] = keybind["usage"].asString();
    //     _changeScene(keybind["usage"].asString());
    // }
    // for (auto &component : root["components"]) {
    //     _sceneComponents[component["name"].asString()] = component["path"].asString();
    //     // Create a component, and add it to the scene
    // }
}

void SceneManager::_loadScene(const std::string &path)
{
    std::ifstream file(path);
    Json::Reader reader;
}

void SceneManager::_loadSceneSystems()
{

}

void SceneManager::_loadSceneComponents()
{

}

void SceneManager::_changeScene(const std::string &sceneName)
{
    // Clear the register of the scene (need to think about it)
    //
}
