/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries)
{
    _registries = registries;
}
