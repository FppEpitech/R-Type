/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#include "Application.hpp"

void GameEngine::Application::_packetHandler(Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint, ECS::Registry& reg)
{
    int idxPlayerPacket = -1;

    ECS::SparseArray<IComponent> PlayerComponentArray = reg.get_components<IComponent>("PlayerComponent");
    for (int index = 0; index < PlayerComponentArray.size(); index++) {
        PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
        if (player->token == packet.getToken()) {
            idxPlayerPacket = index;
            break;
        }
    }
    if (idxPlayerPacket == -1) {
        std::cout << "Message receive from a client no registered" << std::endl;
        return;
    }

    if (packet.getMessageType() == static_cast<uint8_t>(MessageType::ArrowKey)) {
        // TODO: ArrowKey Handler
    } else if (packet.getMessageType() == static_cast<uint8_t>(MessageType::AlphaKey)) {
        if (packet.getPayload()[0] == static_cast<uint8_t>(0x04))
            _sceneManager->processInput(KEY_D, idxPlayerPacket);
        if (packet.getPayload()[0] == static_cast<uint8_t>(0x11))
            _sceneManager->processInput(KEY_Q, idxPlayerPacket);
        if (packet.getPayload()[0] == static_cast<uint8_t>(0x1A))
            _sceneManager->processInput(KEY_Z, idxPlayerPacket);
        if (packet.getPayload()[0] == static_cast<uint8_t>(0x13))
            _sceneManager->processInput(KEY_S, idxPlayerPacket);
    } else if (packet.getMessageType() == static_cast<uint8_t>(MessageType::NumberKey)) {
        // TODO: NumberKey Handler
    } else if (packet.getMessageType() == static_cast<uint8_t>(MessageType::SpecialKey)) {
        // TODO: SpecialKey Handler
    } else {
        std::cout << "Bad MessageType" << std::endl;
    }
}

GameEngine::Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries);

    _server = std::make_shared<Network::Server>(4444, 4445);
    _server->start([this](Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint, ECS::Registry& reg) {
        this->_packetHandler(std::move(packet), endpoint, _registries->at(SceneManager::RegisterIndex::CURRENT));
    }, _registries->at(SceneManager::RegisterIndex::CURRENT));
}

void GameEngine::Application::run()
{
    // TODO: Start sceneManager
    // _sceneManager->processInput("ok");
    while (true) {
        // TODO: Game loop
    }
}
