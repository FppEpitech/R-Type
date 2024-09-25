/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Errors/ServerErrors.hpp"
#include "DLLoader/DLLoader.hpp"
#include "IComponent.hpp"

#include <fstream>
#include <iostream>

GameEngine::SceneManager::SceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries)
{
    _registries = registries;

    ECS::Registry reg;
    _registries->push_back(reg);


    _loadScene(DEFAULT_SCENE_PATH);
}

GameEngine::SceneManager::~SceneManager()
{
}

void GameEngine::SceneManager::processInput(const std::string &input)
{
    // for (auto &scene : _sceneKeys) {
    //     if (scene.first == input) {
    //         // Call the system
    //     }
    // }
}

void GameEngine::SceneManager::_loadSceneKeys(const std::string &path)
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

void GameEngine::SceneManager::_loadScene(const std::string &path)
{
    std::ifstream file(path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerError("Error while parsing the scene file" + path);
    _loadSceneComponents(root);
}

void GameEngine::SceneManager::_loadSceneSystems()
{

}

void GameEngine::SceneManager::_loadSceneComponents(Json::Value root)
{
    const Json::Value& entities = root["entity"];

    for (unsigned int i = 0; i < entities.size(); ++i) {
        const Json::Value& componentList = entities[i];
        ECS::entity_t entity = (*_registries)[0].spawn_entity();
        for (unsigned int j = 0; j < componentList.size(); ++j) {
            auto component = GameEngine::DLLoader<IComponent>::load(LIB_COMPONENTS_PATH + componentList[j].asString(), "loadComponentInstance");
            (*_registries)[0].register_component<IComponent>(component->getType());
            (*_registries)[0].set_component(entity, component, component->getType());
        }
    }
}

void GameEngine::SceneManager::_changeScene(const std::string &sceneName)
{
    // Clear the register of the scene (need to think about it)
    //
}
