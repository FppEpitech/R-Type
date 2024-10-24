/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#include <fstream>

#include "ServerSceneManager.hpp"

SceneManager::ServerSceneManager::ServerSceneManager(std::shared_ptr<ECS::Registry> registries, std::shared_ptr<EventListener> eventListener)
    : ASceneManager(registries, eventListener)
{
    _loadScene(FIRST_SCENE, CURRENT);
}

std::string SceneManager::ServerSceneManager::_getComponentLibPath() const {
    return LIB_COMPONENTS_PATH;
}

std::string SceneManager::ServerSceneManager::_getSystemLibPath() const {
    return LIB_SYSTEMS_PATH;
}

std::string SceneManager::ServerSceneManager::_getEventHandlerLibPath() const {
    return LIB_EVENT_HANDLERS_PATH;
}

std::string SceneManager::ServerSceneManager::_getScenesPath() const {
    return SCENE_PATH;
}

void SceneManager::ServerSceneManager::_loadScene(const std::string &path, std::size_t index)
{
    std::ifstream file(_getScenesPath() + path);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(file, root, false))
        throw SceneManagerErrors("Error while parsing the scene file: " + path);
    _loadSceneEntities(root, index);
    _loadSceneSystems(root, index);
    _loadSceneKeys(root, index);
    _loadSceneEventHandlers(root, index);
}
