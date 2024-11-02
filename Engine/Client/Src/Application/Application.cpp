/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"

Application::Application()
{
    _idxEntityPlayer = -1;
    _registry = std::make_shared<ECS::Registry>();
    _registry->identity = ECS::Registry::Identity::Client;

    try {
        _libGraphic = getGraphicalLibrary();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    _client = ABINetwork::createClient();
    if (!_client)
        throw ClientError("Failed to create Client Network");

    _eventListener = std::make_shared<EventListener>(_registry, nullptr, _client, _libGraphic);

    _sceneManager = std::make_shared<SceneManager::ClientSceneManager>(_registry, _eventListener);

    _eventListener->setSceneManager(_sceneManager);
    _initDefaultGraphicSystems();
}

Application::~Application()
{
    for (auto thread : _threads)
        if (thread)
            thread->join();
}

void Application::run()
{
    InitWindow InitWindow(_libGraphic);
    InitShader InitShader(_libGraphic);
    _threads.push_back(std::make_shared<std::thread>([this]() { this->_sendMessages(); }));

    while (_libGraphic->windowIsOpen()) {
        _packetHandler();
        _keyboardHandler(_libGraphic->getKeyDownInput());
        _libGraphic->updateMusic();
        _libGraphic->startDraw();
        _libGraphic->clear();
        _registry->run_systems(CLIENT);
        for (auto defaultSystem : _defaultSystems)
            defaultSystem(*_registry, -1);
        _eventListener->listen();
        _libGraphic->endDraw();
    }
}

void Application::_sendMessages()
{
    while(_libGraphic->windowIsOpen())
        ABINetwork::sendMessages(_client);
}

void Application::_initDefaultGraphicSystems()
{
    _defaultSystems.push_back(DrawOBJSystem().getFunction());
    _defaultSystems.push_back(DrawTextureSystem().getFunction());
    _defaultSystems.push_back(DrawTextureRectSystem().getFunction());
    _defaultSystems.push_back(DrawTextSystem().getFunction());
    _defaultSystems.push_back(SpriteSheetAnimationSystem().getFunction());
}

void Application::_handleAssignTokenPacket(ABINetwork::UDPPacket packet)
{
    _sceneManager->setIndexPlayer(ABINetwork::getAssignTokenInfoFromPacket(packet));
}

void Application::_keyboardHandler(std::size_t key)
{
    try {
        if (key == KEY_NULL)
            return;
        if (!_sceneManager->processInput(KEY_MAP(key), _sceneManager->getIndexPlayer()))
            return;
        if (_client->getToken() == 0)
            return;
        ABINetwork::sendPacketKey(_client, key);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Application::_packetHandler()
{
    if (_client->getToken() == 0)
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
    ABINetwork::sendPacketJoinRoom(_client, std::get<0>(roomCreated), ABINetwork::getCurrentRoomPassword(_client));
}

void Application::_handleGetRoomPacket(ABINetwork::UDPPacket packet)
{
    std::vector<ABINetwork::roomInfo_t> roomInfos = ABINetwork::getRoomsInfos(packet);

    ABINetwork::setListOfRooms(_client, roomInfos);
    ABINetwork::setGetRoomState(_client, ABINetwork::INetworkUnit::GetRoomState::RECEIVED);
}

void Application::_handleJoinRoomPacket(ABINetwork::UDPPacket packet)
{

    _roomInfos.tcpPort = ABINetwork::getAllowedJoindRoomInfoFromPacket(packet);

    if (_roomInfos.tcpPort <= 0)
        return;
    std::shared_ptr<ABINetwork::INetworkUnit> room = nullptr;
    try {
        room = ABINetwork::createClient();
        if (!room || !ABINetwork::connectToServer(room, ABINetwork::getServerIp(_client), _roomInfos.tcpPort))
            throw ClientError("Error while joining room");
        _sceneManager->changeScene(std::make_pair<std::size_t, std::string>(0, FIRST_GAME_SCENE));
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    _client = room;
    ABINetwork::sendPacketInit(_client);
    ABINetwork::sendPacketInit(_client);
    ABINetwork::sendMessages(_client);
}

void Application::_handleWrongRoomPasswordPacket(ABINetwork::UDPPacket packet)
{
    // TODO: display the wrong password menu.
}

void Application::_handleFullRoomPacket(ABINetwork::UDPPacket packet)
{
    // TODO: display the full room menu.
}

void Application::_handleLoginPacket(ABINetwork::UDPPacket packet)
{
    bool isAllowed = ABINetwork::getLoginAllowedInfoFromPacket(packet);

    if (isAllowed)
        ABINetwork::setClientLogin(_client, ABINetwork::INetworkUnit::LoginState::LOGIN);
    else
        ABINetwork::setClientLogin(_client, ABINetwork::INetworkUnit::LoginState::JUST_FAILED);
}

void Application::_handleUpdateComponentPacket(ABINetwork::UDPPacket packet)
{
    uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

    if (packet.getPayload().size() < 1 + componentTypeLength) {
        std::cerr << "Payload is too small." << std::endl;
        return;
    }
    std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

    _sceneManager->processUpdate(componentType, packet);
}
