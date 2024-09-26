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
#include "ISystem.hpp"

#include <fstream>
#include <iostream>

GameEngine::SceneManager::SceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries)
{
    _registries = registries;
    _indexRegister = 1;

    ECS::Registry reg;
    _registries->push_back(reg);
    _registries->push_back(reg);
    _loadScene(DEFAULT_SCENE_PATH, _indexRegister);
}

GameEngine::SceneManager::~SceneManager()
{
}

void GameEngine::SceneManager::processInput(const std::string &input)
{
}

void GameEngine::SceneManager::_loadScene(const std::string &path, int idxRegister)
{
    std::cout << idxRegister << std::endl;
    std::ifstream file(path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerError("Error while parsing the scene file" + path);
    _loadSceneComponents(root, idxRegister);
    _loadSceneSystems(root, idxRegister);
    _loadSceneKeys(root, idxRegister);
}

void GameEngine::SceneManager::_loadSceneKeys(Json::Value root, int idxRegister)
{
    const Json::Value& keyBinds = root["keyBinds"];

    for (auto keys : keyBinds) {

        const Json::Value& key = keys["key"];
        const Json::Value& path = keys["path"];

        if (key and path) {
            _sceneKeys[key.asString()] = path.asString();
            const std::string suffix = ".json";
            if (idxRegister == 1 && path.asString().compare(path.asString().size() - suffix.size(), suffix.size(), ".json") == 0) {
                _indexRegister++;
                ECS::Registry reg;
                (*_registries).push_back(reg);
                _loadScene(path.asString(), _indexRegister);
            }
        }
    }
}

void GameEngine::SceneManager::_loadSceneComponents(Json::Value root, int idxRegister)
{
    const Json::Value& entities = root["entity"];

    for (unsigned int i = 0; i < entities.size(); ++i) {
        const Json::Value& componentList = entities[i];
        ECS::entity_t entity = (*_registries)[idxRegister].spawn_entity();
        for (unsigned int j = 0; j < componentList.size(); ++j) {
            auto component = GameEngine::DLLoader<IComponent>::load(LIB_COMPONENTS_PATH + componentList[j].asString(), "loadComponentInstance");
            if (component) {
                (*_registries)[idxRegister].register_component<IComponent>(component->getType());
                (*_registries)[idxRegister].set_component(entity, component, component->getType());
            }
        }
    }
}

void GameEngine::SceneManager::_loadSceneSystems(Json::Value root, int idxRegister)
{
    const Json::Value& systems = root["systems"];

    for (unsigned int i = 0; i < systems.size(); ++i) {
        auto system = GameEngine::DLLoader<ISystem>::load(LIB_SYSTEMS_PATH + systems[i].asString(), "loadSystemInstance");
        if (system)
            (*_registries)[idxRegister].add_system(system->getFunction());
    }
}

void GameEngine::SceneManager::_changeScene(const std::string &sceneName)
{
    // Clear the register of the scene (need to think about it)
    //
}
