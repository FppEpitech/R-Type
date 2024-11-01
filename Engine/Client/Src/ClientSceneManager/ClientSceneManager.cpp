/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#include <fstream>

#include "ClientSceneManager.hpp"
#include "AEvent.hpp"
#include "../../../Shared/DefaultSystems/KeyMaps/StringKeyMap.hpp"

SceneManager::ClientSceneManager::ClientSceneManager(std::shared_ptr<ECS::Registry> registries, std::shared_ptr<EventListener> eventListener)
    : ASceneManager(registries, eventListener)
{
    _loadScene(FIRST_SCENE, CURRENT);
}

std::unordered_map<KEY_MAP, std::string> SceneManager::ClientSceneManager::getSoundMap()
{
    return _soundMap;
}

std::string SceneManager::ClientSceneManager::_getComponentLibPath() const
{
    return LIB_COMPONENTS_PATH;
}

std::string SceneManager::ClientSceneManager::_getSystemLibPath() const
{
    return LIB_SYSTEMS_PATH;
}

std::string SceneManager::ClientSceneManager::_getEventHandlerLibPath() const
{
    return LIB_EVENT_HANDLER_PATH;
}

std::string SceneManager::ClientSceneManager::_getScenesPath() const
{
    return SCENE_PATH;
}

bool SceneManager::ClientSceneManager::processInput(KEY_MAP key, int idxPacketEntities)
{
    static std::chrono::high_resolution_clock::time_point lastCall = std::chrono::high_resolution_clock::now();
    if (_keysSystems.find(key) != _keysSystems.end()) {
        const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        double timeElapsed = std::chrono::duration<double, std::milli>(now - lastCall).count() / 1000;
        if (timeElapsed > 0.005) {
            lastCall = std::chrono::high_resolution_clock::now();
            _keysSystems.at(key)->getFunction()(*_registry, idxPacketEntities);
            return true;
        }
    }
    if (_keysScenes.find(key) != _keysScenes.end()) {
        changeScene(_keysScenes.at(key));
        return true;
    }
    return false;
}

void SceneManager::ClientSceneManager::_loadSceneMusic(Json::Value root, std::size_t index)
{
    const Json::Value& music = root["music"];

    if (music.isNull())
        return;
    std::string path = music.asString();
    std::vector<std::any> musicPath = {path};
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("DefaultPlayMusic", musicPath);
    _registry->addEvent(event);

}

void SceneManager::ClientSceneManager::_loadSceneSounds(Json::Value root, std::size_t index)
{
    const Json::Value& sounds = root["sounds"];

    if (sounds.isNull())
        return;
    for (const auto& sound : sounds) {
        std::string path = sound["path"].asString();
        std::string strKey = sound["key"].asString();
        KEY_MAP key = stringKeyMap.at(strKey);
        _soundMap[key] = path;
    }
}

ConsumptionCompute SceneManager::ClientSceneManager::GetConsumptionCompute()
{
    static ConsumptionCompute consumptionCompute;
    return consumptionCompute;
}

void SceneManager::ClientSceneManager::_loadScene(const std::string &path, std::size_t index)
{
    std::ifstream file(_getScenesPath() + path);
    Json::Reader reader;
    Json::Value root;
    Json::Value menus;

    if (!reader.parse(file, root, false))
        throw SceneManagerErrors("Error while parsing the scene file: " + path);
    menus = root["menus"];
    _loadSceneEntities(root, index);
    _loadSceneSystems(root, index);
    _loadSceneKeys(root, index);
    _loadSceneKeys(menus, index);
    _loadNetworkUpdateSystem(root, index);
    _loadSceneEventHandlers(root, index);
    _loadSceneMusic(root, index);
    _loadSceneSounds(root, index);
}
