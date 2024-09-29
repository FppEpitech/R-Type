/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"
#include "../ClientSceneManager/ClientSceneManager.hpp"

void Application::_packetHandler(Network::UDPPacket packet)
{
    std::cout << "Messages received from server: [...]" << std::endl;
}


Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    SceneManager::ClientSceneManager sceneManager(_registries);

    _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445);
    _client->connect([this](Network::UDPPacket packet) {
        this->_packetHandler(std::move(packet));
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
