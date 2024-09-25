/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#include "Application.hpp"

GameEngine::Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    _sceneManager = std::make_shared<SceneManager>(_registries);
    // TODO: init network multithreaded
}

void GameEngine::Application::run()
{
    // TODO: Start sceneManager
}
