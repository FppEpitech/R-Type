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





    uint16_t messageID = 0x0001;
    uint32_t token = 0x00000000;
    uint32_t payloadLength = 1;

    std::vector<uint8_t> packet;

    packet.push_back(0x01);
    packet.push_back(0x02);

    packet.push_back(static_cast<uint8_t>(messageID >> 8));
    packet.push_back(static_cast<uint8_t>(messageID & 0xFF));

    packet.push_back(static_cast<uint8_t>(token >> 24));
    packet.push_back(static_cast<uint8_t>(token >> 16));
    packet.push_back(static_cast<uint8_t>(token >> 8));
    packet.push_back(static_cast<uint8_t>(token & 0xFF));

    packet.push_back(static_cast<uint8_t>(payloadLength >> 24));
    packet.push_back(static_cast<uint8_t>(payloadLength >> 16));
    packet.push_back(static_cast<uint8_t>(payloadLength >> 8));
    packet.push_back(static_cast<uint8_t>(payloadLength & 0xFF));

    packet.push_back(0x1A);

    uint16_t checksum = 0;
    for (const auto& byte : packet) {
        checksum += byte;
    }

    packet.push_back(static_cast<uint8_t>(checksum >> 8));
    packet.push_back(static_cast<uint8_t>(checksum & 0xFF));







    this->_client->sendMessage(packet);
    this->_client->sendMessage(packet);
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
    if (!libGraphic)
        throw ClientError("Failed to load graphic library");
    libGraphic->init(WINDOW_TITLE);

    while (libGraphic->windowIsOpen()) {
        libGraphic->clear();
        _registries->at(SceneManager::RegisterIndex::CURRENT).run_systems(-1);
    }
}
