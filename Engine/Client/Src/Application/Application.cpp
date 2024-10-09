/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"

void Application::_packetHandler(Network::UDPPacket packet, ECS::Registry& reg)
{
    uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

    if (packet.getPayload().size() < 1 + componentTypeLength) {
        std::cerr << "Payload is too small." << std::endl;
        return;
    }
    std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

    _sceneManager->processUpdate(componentType, packet);
}

Application::Application()
{
    _registry = std::make_shared<ECS::Registry>();
    _sceneManager = std::make_shared<SceneManager::ClientSceneManager>(_registry);

    _initDefaultGraphicSystems();

    _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445);
    _client->connect([this](Network::UDPPacket packet, ECS::Registry& reg) {
        this->_packetHandler(std::move(packet), *_registry);
    }, *_registry);
}

void Application::_initDefaultGraphicSystems()
{
    _defaultSystems.push_back(DrawOBJSystem().getFunction());
    _defaultSystems.push_back(DrawTextureSystem().getFunction());
    _defaultSystems.push_back(DrawTextureRectSystem().getFunction());
    _defaultSystems.push_back(DrawTextSystem().getFunction());
    _defaultSystems.push_back(SpriteSheetAnimationSystem().getFunction());
}

void Application::_keyboardHandler(std::size_t key)
{
    try {
        if (key == KEY_NULL)
            return;
        _sceneManager->processInput(KEY_MAP(key), this->_client->getIdxPlayerComponent());
        _client->sendKeyPacket(KEY_MAP(key));
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Application::run()
{
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
    if (!libGraphic)
        throw ClientError("Failed to load graphic library");
    libGraphic->init(WINDOW_TITLE);
    InitShader InitShader(libGraphic);

    while (libGraphic->windowIsOpen()) {
        _keyboardHandler(libGraphic->getKeyDownInput());
        libGraphic->startDraw();
        libGraphic->clear();
        _registry->run_systems(-1);
        for (auto defaultSystem : _defaultSystems)
            defaultSystem(*_registry, -1);
        libGraphic->endDraw();
    }
}
