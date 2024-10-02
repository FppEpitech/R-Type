/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#include "Application.hpp"

void Application::_packetHandler(Network::UDPPacket packet)
{
    std::cout << "Messages received from server: [...]" << std::endl;
}

Application::Application()
{
    _registries = std::make_shared<std::vector<ECS::Registry>>();
    _sceneManager = std::make_shared<SceneManager::ClientSceneManager>(_registries);

    _initDefaultGraphicSystems();

    _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445);
    _client->connect([this](Network::UDPPacket packet) {
        this->_packetHandler(std::move(packet));
    }, _registries->at(SceneManager::RegisterIndex::CURRENT));
}

void Application::_initDefaultGraphicSystems()
{
    DrawOBJSystem drawOBJSystem;
    _defaultSystems.push_back(drawOBJSystem.getFunction());
}

void Application::_keyboardHandler(std::size_t key)
{

    try {
        if (key == KEY_NULL)
            return;
        int idxPlayerPacket = -1;

        ECS::SparseArray<IComponent> PlayerComponentArray = _registries->at(SceneManager::RegisterIndex::CURRENT).get_components<IComponent>("PlayerComponent");
        for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
            PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
            if (player->token == this->_client->getToken()) {
                idxPlayerPacket = index;
                break;
            }
        }
        if (idxPlayerPacket == -1)
            return;
        _sceneManager->processInput(KEY_MAP(key), idxPlayerPacket);
        _client->sendKeyPacket(KEY_MAP(key));
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Application::run()
{
    // uint16_t messageID = 0x0001;
    // uint32_t token = 0x00000000;
    // uint32_t payloadLength = 1;
 
    // std::vector<uint8_t> packet;
 
    // packet.push_back(0x01);
    // packet.push_back(0x02);
 
    // packet.push_back(static_cast<uint8_t>(messageID >> 8));
    // packet.push_back(static_cast<uint8_t>(messageID & 0xFF));
 
    // packet.push_back(static_cast<uint8_t>(token >> 24));
    // packet.push_back(static_cast<uint8_t>(token >> 16));
    // packet.push_back(static_cast<uint8_t>(token >> 8));
    // packet.push_back(static_cast<uint8_t>(token & 0xFF));
 
    // packet.push_back(static_cast<uint8_t>(payloadLength >> 24));
    // packet.push_back(static_cast<uint8_t>(payloadLength >> 16));
    // packet.push_back(static_cast<uint8_t>(payloadLength >> 8));
    // packet.push_back(static_cast<uint8_t>(payloadLength & 0xFF));
 
    // packet.push_back(0x04);
 
    // uint16_t checksum = 0;
    // for (const auto& byte : packet) {
    //     checksum += byte;
    // }
 
    // packet.push_back(static_cast<uint8_t>(checksum >> 8));
    // packet.push_back(static_cast<uint8_t>(checksum & 0xFF));
    // std::cout << "size: " << packet.size() << std::endl;
    // _client->sendMessage(packet);
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
    if (!libGraphic)
        throw ClientError("Failed to load graphic library");
    libGraphic->init(WINDOW_TITLE);

    while (libGraphic->windowIsOpen()) {
        _keyboardHandler(libGraphic->getKeyInput());
        libGraphic->startDraw();
        libGraphic->clear();
        _registries->at(SceneManager::RegisterIndex::CURRENT).run_systems(-1);
        for (auto defaultSystem : _defaultSystems)
            defaultSystem(_registries->at(SceneManager::RegisterIndex::CURRENT), -1);
        libGraphic->endDraw();
    }
}
