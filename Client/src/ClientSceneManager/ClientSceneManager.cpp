/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#include <fstream>
#include <algorithm>

#include "ClientSceneManager.hpp"
#include "ClientErrors.hpp"
#include "DLLoader/DLLoader.hpp"
#include "interfaces/ISceneManager.hpp"
#include "IComponent.hpp"
#include "ISystem.hpp"

SceneManager::ClientSceneManager::ClientSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries)
{
    _registries = registries;
    _nextIndex = SceneManager::RegisterIndex::NEXT;

    for (std::size_t i = CURRENT; i < NEXT; i++) {
        _registries->push_back(ECS::Registry());
        _keysSystems.push_back(std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>());
        _keysScenes.push_back(std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>());
    }
    _loadScene(FIRST_SCENE, CURRENT);
}

void SceneManager::ClientSceneManager::_loadScene(const std::string &path, std::size_t registerIndex)
{
    std::ifstream file(SCENE_PATH + path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerError("Error while parsing the scene file: " + path);
    _loadSceneComponents(root, registerIndex);
    _loadSceneSystems(root, registerIndex);
    _loadSceneKeys(root, registerIndex);
}

void SceneManager::ClientSceneManager::_loadNextScenes(const std::string &path, std::size_t index)
{
    std::ifstream file(SCENE_PATH + path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerError("Error while parsing the scene file: " + path);
    _loadSceneKeys(root, index);
}

void SceneManager::ClientSceneManager::_loadSceneComponents(Json::Value root, std::size_t index)
{
    const Json::Value& entities = root["entities"];

    for (unsigned int i = 0; i < entities.size(); ++i) {
        const Json::Value& componentList = entities[i];
        ECS::entity_t entity = _registries->at(index).spawn_entity();
        for (unsigned int j = 0; j < componentList.size(); ++j) {
            std::shared_ptr<IComponent> component = DLLoader<IComponent>::load(LIB_COMPONENTS_PATH + componentList[j].asString(), "loadComponentInstance");
            if (component) {
                _registries->at(index).register_component<IComponent>(component->getType());
                _registries->at(index).set_component(entity, component, component->getType());
            } else {
                throw SceneManagerError("Error while loading the component: " + componentList[j].asString());
            }
        }
    }
}

void SceneManager::ClientSceneManager::_loadSceneSystems(Json::Value root, std::size_t index)
{
    const Json::Value& systems = root["systems"];

    for (unsigned int i = 0; i < systems.size(); ++i) {
        std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(LIB_SYSTEMS_PATH + systems[i].asString(), "loadSystemInstance");
        if (system)
            _registries->at(index).add_system(system->getFunction());
        else
            throw SceneManagerError("Error while loading the system: " + systems[i].asString());
    }
}

void SceneManager::ClientSceneManager::_loadSceneKeys(Json::Value root, std::size_t index)
{
    const Json::Value& keyBinds = root["keyBinds"];

    for (auto keys : keyBinds) {
        const Json::Value &key = keys["key"];
        const Json::Value &path = keys["path"];

        if (key and path) {
            if (index == SceneManager::RegisterIndex::CURRENT && path.asString().find(CONFIG_SUFFIX) != std::string::npos) {
                _registries->push_back(ECS::Registry());
                _keysSystems.push_back(std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>());
                _keysScenes.push_back(std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>());
                _keysScenes[index][stringKeyMap.at(key.asString())] = std::make_pair(_nextIndex, path.asString());
                _loadScene(path.asString(), _nextIndex);
                _nextIndex++;
            }
            if (path.asString().find(LIB_SUFFIX) != std::string::npos) {
                std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(LIB_SYSTEMS_PATH + path.asString(), "loadSystemInstance");
                if (system) {
                    if (stringKeyMap.find(key.asString()) == stringKeyMap.end())
                        throw SceneManagerError("Error while loading the key: " + key.asString());
                    _keysSystems[index][stringKeyMap.at(key.asString())] = system;
                } else {
                    throw SceneManagerError("Error while loading the key: " + key.asString());
                }
            }
        } else {
            throw SceneManagerError("Error while loading the key: " + key.asString());
        }
    }
}

void SceneManager::ClientSceneManager::_changeScene(std::pair <std::size_t, std::string> scene, KEY_MAP key)
{
    // Swap the previous scene (deprecated) with the new scene
    iter_swap(_registries->begin() + PREVIOUS, _registries->begin() + scene.first);
    iter_swap(_keysSystems.begin() + PREVIOUS, _keysSystems.begin() + scene.first);
    iter_swap(_keysScenes.begin() + PREVIOUS, _keysScenes.begin() + scene.first);

    // Set the new scene as the current scene and the current scene as the previous scene
    iter_swap(_registries->begin() + CURRENT, _registries->begin() + PREVIOUS);
    iter_swap(_keysSystems.begin() + CURRENT, _keysSystems.begin() + PREVIOUS);
    iter_swap(_keysScenes.begin() + CURRENT, _keysScenes.begin() + PREVIOUS);

    // Erase the deprecated scenes
    _registries->erase(_registries->begin() + NEXT, _registries->end());
    _keysSystems.erase(_keysSystems.begin() + NEXT, _keysSystems.end());
    _keysScenes.erase(_keysScenes.begin() + NEXT, _keysScenes.end());

    _nextIndex = NEXT;
    _loadScene(scene.second, CURRENT);
}
