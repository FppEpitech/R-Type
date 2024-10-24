/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#include "Application.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void GameEngine::Application::_handlePacketsRooms(ABINetwork::UDPPacket)
{
    // Note à moi même, faire une map qui call ce handle packet et tous les autres.
}

void GameEngine::Application::_packetHandler()
{
    std::lock_guard<std::mutex> lock(_server->getMutex());

    std::vector<ABINetwork::UDPPacket> messages = _server->getReceivedMessages();

    for (auto packet : messages) {

        auto messageType = static_cast<ABINetwork::IMessage::MessageType>(packet.getMessageType());

        if (ABINetwork::IMessage::MessageType(messageType) == ABINetwork::IMessage::MessageType::KEY) {

            int idxPlayerPacket = -1;
            ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
            for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
                PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
                if (player && player->token == packet.getToken()) {
                    idxPlayerPacket = index;
                    break;
                }
            }
            uint8_t keyCode = packet.getPayload()[0];
            _sceneManager->processInput(KEY_MAP(keyCode), idxPlayerPacket);
            continue;
        }

        _handlePacketsRooms(packet);
    }
}

GameEngine::Application::Application()
{
    _registries = std::make_shared<ECS::Registry>();
    _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries);
    _server = ABINetwork::createServer(4);
}

bool GameEngine::Application::noPlayerConnected()
{
    // std::lock_guard<std::mutex> lock(_registries->_myBeautifulMutex);
    // ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
    // for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
    //     PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
    //     if (player && player->token != 0) {
    //         return false;
    //     }
    // }
    return true;
}

void GameEngine::Application::run()
{
    while (true) {

        _packetHandler();
        // if (!noPlayerConnected())
            _registries->run_systems(-1);
        // else
            // SLEEP(0.5);
    }
}
