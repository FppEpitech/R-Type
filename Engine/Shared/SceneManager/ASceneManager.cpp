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

SceneManager::ASceneManager::ASceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries)
{
    _registries = registries;
    _nextIndex = SceneManager::RegisterIndex::NEXT;

    _initialiseDefaultComponents();
    for (std::size_t i = CURRENT; i < NEXT; i++) {
        _registries->push_back(ECS::Registry());
        _registries->at(i).cloneComponentsArray(_defaultRegistry);
        _keysSystems.push_back(std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>());
        _keysScenes.push_back(std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>());
    }
}

bool SceneManager::ASceneManager::processInput(KEY_MAP key, int idxPacketEntities)
{
    if (_keysSystems[CURRENT].find(key) != _keysSystems[CURRENT].end()) {
        _keysSystems[CURRENT].at(key)->getFunction()(_registries->at(CURRENT), idxPacketEntities);
        return true;
    }
    if (_keysScenes[CURRENT].find(key) != _keysScenes[CURRENT].end()) {
        _changeScene(_keysScenes[CURRENT].at(key));
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
}

void SceneManager::ASceneManager::_loadNextScenes(const std::string &path, std::size_t index)
{
    std::ifstream file(_getScenesPath() + path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerErrors("Error while parsing the scene file: " + path);
    _loadSceneKeys(root, index);
}

void SceneManager::ASceneManager::_loadSceneEntities(Json::Value root, std::size_t index)
{
    const Json::Value& entities = root["entities"];

    for (unsigned int i = 0; i < entities.size(); ++i) {
        std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(_getSystemLibPath() + entities[i].asString(), "loadSystemInstance");
        if (system) {
            ECS::entity_t entity = _registries->at(index).spawn_entity();
            system->getFunction()(_registries->at(index), entity);
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
            _registries->at(index).add_system(system->getFunction());
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
            if (index == SceneManager::RegisterIndex::CURRENT && path.asString().find(CONFIG_SUFFIX) != std::string::npos)
                _loadSceneKeysJson(key.asString(), path.asString(), index);
            if (path.asString().find(LIB_SUFFIX) != std::string::npos)
                _loadSceneKeysSystem(key.asString(), path.asString(), index);
        } else
            throw SceneManagerJsonErrors("Error while loading the key: " + key.asString());
    }
}

void SceneManager::ASceneManager::_loadSceneKeysJson(std::string key, std::string path, std::size_t index)
{
    _registries->push_back(ECS::Registry());
    _registries->at(_nextIndex).cloneComponentsArray(_defaultRegistry);
    _keysSystems.push_back(std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>());
    _keysScenes.push_back(std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>());
    _keysScenes[index][stringKeyMap.at(key)] = std::make_pair(_nextIndex, path);
    _loadScene(path, _nextIndex);
    _nextIndex++;
}

void SceneManager::ASceneManager::_loadSceneKeysSystem(std::string key, std::string path, std::size_t index)
{
    std::shared_ptr<ISystem> system = DLLoader<ISystem>::load(_getSystemLibPath() + path, "loadSystemInstance");
    if (system) {
        if (stringKeyMap.find(key) == stringKeyMap.end())
            throw SceneManagerJsonErrors("Error while loading the key: " + key);
        _keysSystems[index][stringKeyMap.at(key)] = system;
    } else
        throw SceneManagerJsonErrors("Error while loading the key: " + key);
}

void SceneManager::ASceneManager::_changeScene(std::pair<std::size_t, std::string> scene)
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

void SceneManager::ASceneManager::_initialiseDefaultComponents()
{
    _defaultRegistry.register_component<IComponent>(ColourComponent().getType());
    _defaultRegistry.register_component<IComponent>(FontPathComponent().getType());
    _defaultRegistry.register_component<IComponent>(MaterialMapComponent().getType());
    _defaultRegistry.register_component<IComponent>(MusicPathComponent().getType());
    _defaultRegistry.register_component<IComponent>(MusicPitchComponent().getType());
    _defaultRegistry.register_component<IComponent>(MusicVolumeComponent().getType());
    _defaultRegistry.register_component<IComponent>(ObjPathComponent().getType());
    _defaultRegistry.register_component<IComponent>(Position2DComponent().getType());
    _defaultRegistry.register_component<IComponent>(Position3DComponent().getType());
    _defaultRegistry.register_component<IComponent>(ScaleComponent().getType());
    _defaultRegistry.register_component<IComponent>(Size1DComponent().getType());
    _defaultRegistry.register_component<IComponent>(SoundPathComponent().getType());
    _defaultRegistry.register_component<IComponent>(SoundPitchComponent().getType());
    _defaultRegistry.register_component<IComponent>(SoundVolumeComponent().getType());
    _defaultRegistry.register_component<IComponent>(TextComponent().getType());
    _defaultRegistry.register_component<IComponent>(TexturePathComponent().getType());
    _defaultRegistry.register_component<IComponent>(TextureRectComponent().getType());
    _defaultRegistry.register_component<IComponent>(SpriteSheetAnimationComponent().getType());
    _defaultRegistry.register_component<IComponent>(PlayerComponent().getType());
}
