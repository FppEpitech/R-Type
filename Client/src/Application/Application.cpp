/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"
#include "ClientSceneManager.hpp"
#include "GraphicalLoad.hpp"
#include "ClientErrors.hpp"

Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    SceneManager::ClientSceneManager sceneManager(_registries);
    // Initialize the network and the first scene
}

void Application::run()
{
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
    if (!libGraphic)
        throw ClientError("Failed to load graphic library");
    libGraphic->Init("From noware");

    while (libGraphic->windowIsOpen()) {
        libGraphic->clear();
    }
}
