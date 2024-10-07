/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"

void Application::_packetHandler(Network::UDPPacket packet)
{
    uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

    if (packet.getPayload().size() < 1 + componentTypeLength + 4 + 2 * sizeof(float)) {
        std::cerr << "Payload is too small." << std::endl;
        return;
    }

    std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

    // TODO: launch the updateNetworkSystem associate.
}

Application::Application()
{
    _registry = std::make_shared<ECS::Registry>();
    _sceneManager = std::make_shared<SceneManager::ClientSceneManager>(_registry);

    _initDefaultGraphicSystems();

    _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445);
    _client->connect([this](Network::UDPPacket packet) {
        this->_packetHandler(std::move(packet));
    }, *_registry);
}

void Application::_initDefaultGraphicSystems()
{
    _defaultSystems.push_back(DrawOBJSystem().getFunction());
    _defaultSystems.push_back(DrawTextureSystem().getFunction());
    _defaultSystems.push_back(DrawTextSystem().getFunction());
    _defaultSystems.push_back(DrawTextureRectSystem().getFunction());
    _defaultSystems.push_back(SpriteSheetAnimationSystem().getFunction());
}

void Application::_keyboardHandler(std::size_t key)
{
    try {
        if (key == KEY_NULL)
            return;
        int idxPlayerPacket = -1;

        ECS::SparseArray<IComponent> PlayerComponentArray = _registry->get_components<IComponent>("PlayerComponent");
        for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
            PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
            if (!player)
                continue;
            if (player->token == this->_client->getToken()) {
                idxPlayerPacket = index;
                break;
            }
        }
        // TODO: Refacto this shit with @Axel
        // if (idxPlayerPacket == -1)
        //     return;
        _sceneManager->processInput(KEY_MAP(key), idxPlayerPacket);
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
        _keyboardHandler(libGraphic->getKeyInput());
        libGraphic->startDraw();
        libGraphic->clear();
        _registry->run_systems(-1);
        for (auto defaultSystem : _defaultSystems)
            defaultSystem(*_registry, -1);
        libGraphic->endDraw();
    }
}
