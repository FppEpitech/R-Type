/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#include "ServerSceneManager.hpp"

SceneManager::ServerSceneManager::ServerSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries) : ASceneManager(registries)
{
    _loadScene(FIRST_SCENE, CURRENT);
}

std::string SceneManager::ServerSceneManager::_getComponentLibPath() const {
    return LIB_COMPONENTS_PATH;
}

std::string SceneManager::ServerSceneManager::_getSystemLibPath() const {
    return LIB_SYSTEMS_PATH;
}

std::string SceneManager::ServerSceneManager::_getScenesPath() const {
    return SCENE_PATH;
}

