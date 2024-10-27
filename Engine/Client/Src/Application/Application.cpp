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
        _packetHandler();
        _keyboardHandler(_libGraphic->getKeyDownInput());
        _libGraphic->startDraw();
        _libGraphic->clear();
        _registry->run_systems(-1);
        for (auto defaultSystem : _defaultSystems)
            defaultSystem(*_registry, -1);
        _eventListener->listen();
        _libGraphic->endDraw();
        if (_client)
            ABINetwork::sendMessages(_client);
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

void Application::_keyboardHandler(std::size_t key)
{
    try {
        if (key == KEY_NULL || _client == nullptr)
            return;

        //TODO: uncomment this when the game will be able to run on the client.

        // if (!_sceneManager->processInput(KEY_MAP(key), this->_client->getIdxPlayerComponent()))
        //     return;

        ABINetwork::sendPacketKey(_client, key);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Application::_packetHandler()
{
    if (!_client)
        return;
    std::lock_guard<std::mutex> lock(_client->getMutex());
    std::vector<ABINetwork::UDPPacket> messages = _client->getReceivedMessages();

    for (auto packet : messages) {
        try {
            auto messageType = static_cast<ABINetwork::IMessage::MessageType>(packet.getMessageType());
            _handlePacketsMap[ABINetwork::IMessage::MessageType(messageType)](packet);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Application::_handleCreateRoomPacket(ABINetwork::UDPPacket packet)
{
    std::tuple<std::string, int, int> roomCreated = ABINetwork::getCreatedRoomInfoFromPacket(packet);
    _roomInfos.tcpPort = std::get<1>(roomCreated);
    _roomInfos.udpPort = std::get<2>(roomCreated);
    ABINetwork::sendPacketJoinRoom(_client, std::get<0>(roomCreated), _roomInfos.password);
}

void Application::_handleJoinRoomPacket(ABINetwork::UDPPacket packet)
{
    if (_roomInfos.tcpPort <= 0 || _roomInfos.udpPort <= 0)
        return;
    std::shared_ptr<ABINetwork::INetworkUnit> room = nullptr;
    try {
        room = ABINetwork::createClient("127.0.0.1", _roomInfos.tcpPort);
        if (!room)
            throw ClientError("Error while joining room");
        _sceneManager->changeScene(std::make_pair<std::size_t, std::string>(0, FIRST_GAME_SCENE));
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    _client = room;
}

void Application::_handleWrongRoomPasswordPacket(ABINetwork::UDPPacket packet)
{
    // TODO: display the wrong password menu.
}

void Application::_handleFullRoomPacket(ABINetwork::UDPPacket packet)
{
    // TODO: display the full room menu.
}

void Application::_connectServer()
{
    // if (!_client) {
    //     _client = ABINetwork::createClient("127.0.0.1", 4444, 4445);
    //     _serverInfos.tcpPort = 4444;
    //     _serverInfos.udpPort = 4445;
    // }

    // std::lock_guard<std::mutex> lock(this->_registry->_myBeautifulMutex);
    // try {
    //     ECS::SparseArray<IComponent> players = this->_registry->get_components<IComponent>("PlayerComponent");
    //     ECS::SparseArray<IComponent> buttonNetworkConnection = this->_registry->get_components<IComponent>("NetworkConnectionComponent");

    //     for (int index = 0; index < buttonNetworkConnection.size(); index++) {
    //         std::shared_ptr<NetworkConnectionComponent> networkInfo = std::dynamic_pointer_cast<NetworkConnectionComponent>(buttonNetworkConnection[index]);
    //         if (!networkInfo)
    //             continue;
    //         if (networkInfo->connect == true) {
    //             networkInfo->connect = false;
    //             _sceneManager->_changeScene(std::make_pair<size_t, std::string>(0, "firstScene.json"));
    //              _client = std::make_shared<Network::Client>(networkInfo->serverIp, std::atoi(networkInfo->serverPort.c_str()), 4445);
    //             _client->connect([this](Network::UDPPacket packet, ECS::Registry& reg) {
    //                 this->_packetHandler(std::move(packet), *_registry);
    //             }, *_registry);
    //         }
    //     }
    //     if (_client == nullptr)
    //         return;
    //     if (_client->getIdxPlayerComponent() != -1 && _client->getIdxPlayerComponent() < players.size()) {
    //         std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(players[_client->getIdxPlayerComponent()]);
    //         if (player && !player->isAlive) {
    //             player->isAlive = true;
    //             _sceneManager->_changeScene(std::make_pair<size_t, std::string>(0, "endScene.json"));
    //         }
    //     }
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
}
