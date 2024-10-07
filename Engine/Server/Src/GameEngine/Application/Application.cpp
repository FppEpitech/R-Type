/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#include "Application.hpp"


void GameEngine::Application::_handleArrowKey(uint8_t keyCode, int idxPlayerPacket)
{
    std::unordered_map<uint8_t, KEY_MAP> arrowKeyMap = {
        {0x01, KEY_UP},
        {0x02, KEY_RIGHT},
        {0x03, KEY_DOWN},
        {0x04, KEY_LEFT}
    };

    if (arrowKeyMap.find(keyCode) != arrowKeyMap.end())
        _sceneManager->processInput(arrowKeyMap[keyCode], idxPlayerPacket);
}

void GameEngine::Application::_handleAlphaKey(uint8_t keyCode, int idxPlayerPacket)
{
    std::unordered_map<uint8_t, KEY_MAP> alphaKeyMap = {
        {0x01, KEY_A}, {0x02, KEY_B}, {0x03, KEY_C}, {0x04, KEY_D},
        {0x05, KEY_E}, {0x06, KEY_F}, {0x07, KEY_G}, {0x08, KEY_H},
        {0x09, KEY_I}, {0x0A, KEY_J}, {0x0B, KEY_K}, {0x0C, KEY_L},
        {0x0D, KEY_M}, {0x0E, KEY_N}, {0x0F, KEY_O}, {0x10, KEY_P},
        {0x11, KEY_Q}, {0x12, KEY_R}, {0x13, KEY_S}, {0x14, KEY_T},
        {0x15, KEY_U}, {0x16, KEY_V}, {0x17, KEY_W}, {0x18, KEY_X},
        {0x19, KEY_Y}, {0x1A, KEY_Z}
    };

    if (alphaKeyMap.find(keyCode) != alphaKeyMap.end())
        _sceneManager->processInput(alphaKeyMap[keyCode], idxPlayerPacket);
}

void GameEngine::Application::_handleNumberKey(uint8_t keyCode, int idxPlayerPacket)
{
    std::unordered_map<uint8_t, KEY_MAP> numberKeyMap = {
        {0x01, KEY_KP_1}, {0x02, KEY_KP_2}, {0x03, KEY_KP_3}, {0x04, KEY_KP_4},
        {0x05, KEY_KP_5}, {0x06, KEY_KP_6}, {0x07, KEY_KP_7}, {0x08, KEY_KP_8},
        {0x09, KEY_KP_9}, {0x0A, KEY_KP_0}
    };

    if (numberKeyMap.find(keyCode) != numberKeyMap.end())
        _sceneManager->processInput(numberKeyMap[keyCode], idxPlayerPacket);
}

void GameEngine::Application::_handleSpecialKey(uint8_t keyCode, int idxPlayerPacket)
{
    std::unordered_map<uint8_t, KEY_MAP> specialKeyMap = {
        {0x01, KEY_SPACE}, {0x02, KEY_ENTER}, {0x03, KEY_ESCAPE}, {0x04, KEY_BACKSPACE},
        {0x05, KEY_TAB}, {0x06, KEY_LEFT_SHIFT}, {0x07, KEY_LEFT_CONTROL}, {0x08, KEY_LEFT_ALT},
        {0x09, KEY_CAPS_LOCK}, {0x0A, KEY_F1}, {0x0B, KEY_F2}, {0x0C, KEY_F3},
        {0x0D, KEY_F4}, {0x0E, KEY_F5}, {0x0F, KEY_F6}, {0x10, KEY_F7},
        {0x11, KEY_F8}, {0x12, KEY_F9}, {0x13, KEY_F10}, {0x14, KEY_F11}
    };

    if (specialKeyMap.find(keyCode) != specialKeyMap.end())
        _sceneManager->processInput(specialKeyMap[keyCode], idxPlayerPacket);
}

void GameEngine::Application::_packetHandler(Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint, ECS::Registry& reg)
{
    int idxPlayerPacket = -1;

    ECS::SparseArray<IComponent> PlayerComponentArray = reg.get_components<IComponent>("PlayerComponent");
    for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
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

    std::unordered_map<MessageType, std::function<void(uint8_t, int)>> messageHandlers = {
        {MessageType::ArrowKey, [this](uint8_t keyCode, int idxPlayerPacket) {this->_handleArrowKey(keyCode, idxPlayerPacket);}},
        {MessageType::AlphaKey, [this](uint8_t keyCode, int idxPlayerPacket) {this->_handleAlphaKey(keyCode, idxPlayerPacket);}},
        {MessageType::NumberKey, [this](uint8_t keyCode, int idxPlayerPacket) {this->_handleNumberKey(keyCode, idxPlayerPacket);}},
        {MessageType::SpecialKey, [this](uint8_t keyCode, int idxPlayerPacket) {this->_handleSpecialKey(keyCode, idxPlayerPacket);}}
    };

    auto messageType = static_cast<MessageType>(packet.getMessageType());
    uint8_t keyCode = packet.getPayload()[0];

    if (messageHandlers.find(messageType) != messageHandlers.end())
        messageHandlers[messageType](keyCode, idxPlayerPacket);
    else
        std::cout << "Bad MessageType" << std::endl;
}

GameEngine::Application::Application()
{
    _registries = std::make_shared<ECS::Registry>();
    _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries);

    _server = std::make_shared<Network::Server>(4444, 4445);
    _server->start([this](Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint, ECS::Registry& reg) {
        this->_packetHandler(std::move(packet), endpoint, *_registries);
    }, *_registries);
}

void GameEngine::Application::run()
{
    while (true)
        _registries->run_systems(-1);
}
