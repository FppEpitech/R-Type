/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ASceneManager.cpp
*/

#include <fstream>
#include <algorithm>

#include "ASceneManager.hpp"
#include "../DLLoader/DLLoader.hpp"

#include "ISystemNetworkUpdate.hpp"

SceneManager::ASceneManager::ASceneManager(std::shared_ptr<ECS::Registry> registry)
{
    _registry = registry;
    _initialiseDefaultComponents();
}

bool SceneManager::ASceneManager::processInput(KEY_MAP key, int idxPacketEntities)
{
    if (_keysSystems.find(key) != _keysSystems.end()) {
        _keysSystems.at(key)->getFunction()(*_registry, idxPacketEntities);
        return true;
    }
    if (_keysScenes.find(key) != _keysScenes.end()) {
        _changeScene(_keysScenes.at(key));
        return true;
    }
    return false;
}

bool SceneManager::ASceneManager::processUpdate(std::string componentType, Network::UDPPacket packet)
{
    if (_updateNetworkSystems.find(componentType) != _updateNetworkSystems.end()) {
        _updateNetworkSystems.at(componentType)(packet, *_registry);
        return true;
    }
    return false;
}

void SceneManager::ASceneManager::_loadScene(const std::string &path, std::size_t index)
{
    std::ifstream file(_getScenesPath() + path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerErrors("Error while parsing the scene file: " + path);
    _loadSceneEntities(root, index);
    _loadSceneSystems(root, index);
    _loadSceneKeys(root, index);

    //TODO: Uncomment this part when the Pr #120 will be merge main
    //////
    // _loadUpdatesNetworkSystems(root);

    const Json::Value& networkUpdates = root["networkUpdate"];

    for (auto updates : networkUpdates) {
        const Json::Value& component = updates["component"];
        const Json::Value& path = updates["path"];

        if (component and path) {
            std::shared_ptr<ISystemNetworkUpdate> system = DLLoader<ISystemNetworkUpdate>::load(_getSystemLibPath() + path.asString(), "loadUpdateInstance");
            if (system) {
                _updateNetworkSystems[component.asString()] = system->getFunction();
            } else
                throw SceneManagerJsonErrors("Error while loading the system: " + path.asString());
        } else
            throw SceneManagerJsonErrors("Error while loading the networkUpdate: " + updates.asString());
    }
    //////
}

void SceneManager::ASceneManager::_loadSceneEntities(Json::Value root, std::size_t index)
{
    const Json::Value& entities = root["entities"];

    for (unsigned int i = 0; i < entities.size(); ++i) {
        std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(_getSystemLibPath() + entities[i].asString(), "loadSystemInstance");
        if (system) {
            ECS::entity_t entity = _registry->spawn_entity();
            system->getFunction()(*_registry, entity);
        } else
            throw SceneManagerErrors("Error while loading the system: " + entities[i].asString());
    }
}

void SceneManager::ASceneManager::_loadSceneSystems(Json::Value root, std::size_t index)
{
    const Json::Value& systems = root["systems"];

    for (unsigned int i = 0; i < systems.size(); ++i) {
        std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(_getSystemLibPath() + systems[i].asString(), "loadSystemInstance");
        if (system)
            _registry->add_system(system->getFunction());
        else
            throw SceneManagerErrors("Error while loading the system: " + systems[i].asString());
    }
}

void SceneManager::ASceneManager::_loadSceneKeys(Json::Value root, std::size_t index)
{
    const Json::Value& keyBinds = root["keyBinds"];

    for (auto keys : keyBinds) {
        const Json::Value& key = keys["key"];
        const Json::Value& path = keys["path"];

        if (key and path) {
            if (path.asString().find(CONFIG_SUFFIX) != std::string::npos)
                _loadSceneKeysJson(key.asString(), path.asString(), index);
            else if (path.asString().find(LIB_SUFFIX) != std::string::npos)
                _loadSceneKeysSystem(key.asString(), path.asString(), index);
        } else
            throw SceneManagerJsonErrors("Error while loading the key: " + key.asString());
    }
}

void SceneManager::ASceneManager::_loadSceneKeysJson(std::string key, std::string path, std::size_t index)
{
    _keysScenes[stringKeyMap.at(key)] = std::make_pair(_nextIndex, path);
}

void SceneManager::ASceneManager::_loadSceneKeysSystem(std::string key, std::string path, std::size_t index)
{
    std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(_getSystemLibPath() + path, "loadSystemInstance");
    if (system) {
        if (stringKeyMap.find(key) == stringKeyMap.end())
            throw SceneManagerJsonErrors("Error while loading the key: " + key);
        _keysSystems[stringKeyMap.at(key)] = system;
    } else
        throw SceneManagerJsonErrors("Error while loading the key: " + key);
}

void SceneManager::ASceneManager::_changeScene(std::pair<std::size_t, std::string> scene)
{
    _keysScenes.clear();
    _keysSystems.clear();
    _registry->clearSystems();
    _registry->clearComponentsArray();
    _initialiseDefaultComponents();
    _loadScene(scene.second, CURRENT);
}

void SceneManager::ASceneManager::_initialiseDefaultComponents()
{
    _registry->register_component<IComponent>(ColourComponent().getType());
    _registry->register_component<IComponent>(FontPathComponent().getType());
    _registry->register_component<IComponent>(MaterialMapComponent().getType());
    _registry->register_component<IComponent>(MusicPathComponent().getType());
    _registry->register_component<IComponent>(MusicPitchComponent().getType());
    _registry->register_component<IComponent>(MusicVolumeComponent().getType());
    _registry->register_component<IComponent>(ObjPathComponent().getType());
    _registry->register_component<IComponent>(Position2DComponent().getType());
    _registry->register_component<IComponent>(Position3DComponent().getType());
    _registry->register_component<IComponent>(ScaleComponent().getType());
    _registry->register_component<IComponent>(Size1DComponent().getType());
    _registry->register_component<IComponent>(SoundPathComponent().getType());
    _registry->register_component<IComponent>(SoundPitchComponent().getType());
    _registry->register_component<IComponent>(SoundVolumeComponent().getType());
    _registry->register_component<IComponent>(TextComponent().getType());
    _registry->register_component<IComponent>(TexturePathComponent().getType());
    _registry->register_component<IComponent>(TextureRectComponent().getType());
    _registry->register_component<IComponent>(SpriteSheetAnimationComponent().getType());
    _registry->register_component<IComponent>(PlayerComponent().getType());
}
