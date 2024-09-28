/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"
#include "ClientSceneManager.hpp"

Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    SceneManager::ClientSceneManager sceneManager(_registries);
    // Initialize the network and the first scene
}

void Application::run()
{
    // Main loop
    // while (true) {
    //     // Update the network
    //     // Update the current scene
    //     // Render the current scene
    // }
}
