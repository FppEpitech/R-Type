/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#include "ClientSceneManager.hpp"

SceneManager::ClientSceneManager::ClientSceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries) : ASceneManager(registries)
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

std::string SceneManager::ClientSceneManager::_getScenesPath() const
{
    return SCENE_PATH;
}
