/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"
#include "ConsumptionCompute.hpp"

Application::Application()
{
    _registry = std::make_shared<ECS::Registry>();

    try {
        _libGraphic = getGraphicalLibrary();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // TODO: Add the network unit to the event listener
    _eventListener = std::make_shared<EventListener>(_registry, nullptr, nullptr, _libGraphic);

    _sceneManager = std::make_shared<SceneManager::ClientSceneManager>(_registry, _eventListener);

    _eventListener->setSceneManager(_sceneManager);
    _initDefaultGraphicSystems();

    _client = nullptr;
}

void Application::run()
{
    InitWindow InitWindow(_libGraphic);
    InitShader InitShader(_libGraphic);
    ConsumptionCompute consumptionCompute;

    while (_libGraphic->windowIsOpen()) {
        _connectServer();
        _keyboardHandler(_libGraphic->getKeyDownInput());
        _libGraphic->startDraw();
        _libGraphic->clear();
        _registry->run_systems(-1);
        for (auto defaultSystem : _defaultSystems)
            defaultSystem(*_registry, -1);
        _eventListener->listen();
        _libGraphic->endDraw();
    }
}

void Application::_packetHandler(Network::UDPPacket packet, ECS::Registry& reg)
{
    uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

    if (packet.getPayload().size() < 1 + componentTypeLength) {
        std::cerr << "Payload is too small." << std::endl;
        return;
    }
    std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

    int idxPacketEntities = (packet.getPayload()[1 + componentTypeLength] << 24) |
                            (packet.getPayload()[2 + componentTypeLength] << 16) |
                            (packet.getPayload()[3 + componentTypeLength] << 8)  |
                            packet.getPayload()[4 + componentTypeLength];

    // if (idxPacketEntities == this->_client->getIdxPlayerServer())
    //     return;

    _sceneManager->processUpdate(componentType, packet);
}

void Application::_connectServer()
{
    std::lock_guard<std::mutex> lock(this->_registry->_myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> players = this->_registry->get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> buttonNetworkConnection = this->_registry->get_components<IComponent>("NetworkConnectionComponent");

        for (int index = 0; index < buttonNetworkConnection.size(); index++) {
            std::shared_ptr<NetworkConnectionComponent> networkInfo = std::dynamic_pointer_cast<NetworkConnectionComponent>(buttonNetworkConnection[index]);
            if (!networkInfo)
                continue;
            if (networkInfo->connect == true) {
                networkInfo->connect = false;
                _sceneManager->_changeScene(std::make_pair<size_t, std::string>(0, "firstScene.json"));
                 _client = std::make_shared<Network::Client>(networkInfo->serverIp, std::atoi(networkInfo->serverPort.c_str()), 4445);
                _client->connect([this](Network::UDPPacket packet, ECS::Registry& reg) {
                    this->_packetHandler(std::move(packet), *_registry);
                }, *_registry);
            }
        }
        if (_client == nullptr)
            return;
        if (_client->getIdxPlayerComponent() != -1 && _client->getIdxPlayerComponent() < players.size()) {
            std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(players[_client->getIdxPlayerComponent()]);

            if (player && !player->isAlive) {
                player->isAlive = true;
                _sceneManager->_changeScene(std::make_pair<size_t, std::string>(0, "endScene.json"));
            }
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Application::_keyboardHandler(std::size_t key)
{
    try {
        if (key == KEY_NULL || _client == nullptr)
            return;
        if (!_sceneManager->processInput(KEY_MAP(key), this->_client->getIdxPlayerComponent()))
            return;
        _client->sendKeyPacket(KEY_MAP(key));
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Application::_initDefaultGraphicSystems()
{
    _defaultSystems.push_back(DrawOBJSystem().getFunction());
    _defaultSystems.push_back(DrawTextureSystem().getFunction());
    _defaultSystems.push_back(DrawTextureRectSystem().getFunction());
    _defaultSystems.push_back(DrawTextSystem().getFunction());
    _defaultSystems.push_back(SpriteSheetAnimationSystem().getFunction());
}
