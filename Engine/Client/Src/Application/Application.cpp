/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "IGraphic.hpp"
#include "Application.hpp"
#include "ClientErrors.hpp"
#include "ClientSceneManager.hpp"
#include "GetGraphicalLibrary.hpp"

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
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
    if (!libGraphic)
        throw ClientError("Failed to load graphic library");
    libGraphic->init(WINDOW_TITLE);

    while (libGraphic->windowIsOpen()) {
        libGraphic->startDraw();
        libGraphic->clear();
        _registries->at(SceneManager::RegisterIndex::CURRENT).run_systems(-1);
        libGraphic->endDraw();
    }
}
