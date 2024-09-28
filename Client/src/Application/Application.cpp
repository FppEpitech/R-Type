/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"
#include "ClientSceneManager.hpp"

void Application::_packetHandler(std::string message)
{
    std::cout << "Messages received from server: [" << message << "]" << std::endl;
}


Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    ECS::Registry reg;
    _registries.get()->push_back(reg);
    SceneManager::ClientSceneManager sceneManager(_registries);

    _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445);
    _client->connect([this](std::string message) {
        this->_packetHandler(std::move(message));
    });
}

void Application::run()
{
    // Main loop
    while (true) {
        // Update the network
        // Update the current scene
        // Render the current scene
    }
}
