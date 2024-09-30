/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#include "Application.hpp"

void GameEngine::Application::_packetHandler(Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint)
{
    this->_registries->
    std::cout << "Messages received from " << endpoint << ": [" << "..." << "]" << std::endl;
}

GameEngine::Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries);

    _server = std::make_shared<Network::Server>(4444, 4445);
    _server->start([this](Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint) {
        this->_packetHandler(std::move(packet), endpoint);
    });
}

void GameEngine::Application::run()
{
    // TODO: Start sceneManager
    // _sceneManager->processInput("ok");
    _sceneManager->processInput(KEY_D);
    //_sceneManager->processInput(KEY_D);
    while (true) {
        // TODO: Game loop
    }
}
