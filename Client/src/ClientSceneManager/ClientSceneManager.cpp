/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#include <fstream>

#include "ClientSceneManager.hpp"
#include "ClientErrors.hpp"
#include "DLLoader/DLLoader.hpp"
#include "interfaces/ISceneManager.hpp"
#include "IComponent.hpp"
#include "ISystem.hpp"

SceneManager::ClientSceneManager::ClientSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries)
{
    _registries = registries;
    _registerIndex = SceneManager::RegisterIndex::CURRENT;

    _keysRegistry.push_back(std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>());

    _loadScene(DEFAULT_SCENE, _registerIndex);
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
            if (index == 1 && path.asString().find(CONFIG_SUFFIX) != std::string::npos) {
                _registerIndex++;
                ECS::Registry reg;
                _registries->push_back(reg);
                _loadScene(path.asString(), _registerIndex);
            }
            if (path.asString().find(LIB_SUFFIX) != std::string::npos) {
                std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(LIB_SYSTEMS_PATH + path.asString(), "loadSystemInstance");
                if (system) {
                    if (stringKeyMap.find(key.asString()) == stringKeyMap.end())
                        throw SceneManagerError("Error while loading the key: " + key.asString());
                    _keysRegistry[index][stringKeyMap.at(key.asString())] = system;
                } else {
                    throw SceneManagerError("Error while loading the key: " + key.asString());
                }
            }
        } else {
            throw SceneManagerError("Error while loading the key: " + key.asString());
        }
    }
}
