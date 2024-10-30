/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#include <fstream>

#include "ClientSceneManager.hpp"
#include "AEvent.hpp"

SceneManager::ClientSceneManager::ClientSceneManager(std::shared_ptr<ECS::Registry> registries, std::shared_ptr<EventListener> eventListener)
    : ASceneManager(registries, eventListener)
{
    _loadScene(FIRST_SCENE, CURRENT);
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

void SceneManager::ClientSceneManager::_loadSceneMusic(Json::Value root, std::size_t index)
{
    const Json::Value& music = root["music"];

    std::string path = music.asString();
    std::vector<std::any> musicPath = {path};
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("PlayMusic", musicPath);
    _registry->addEvent(event);

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
    loadSceneMusic(root, index);
}
