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

void GameEngine::Application::_packetHandler()
{
    std::lock_guard<std::mutex> lock(_server->getMutex());

    std::vector<ABINetwork::UDPPacket> messages = _server->getReceivedMessages();

    for (auto packet : messages) {

        auto messageType = static_cast<ABINetwork::IMessage::MessageType>(packet.getMessageType());

        // if (ABINetwork::IMessage::MessageType(messageType) == ABINetwork::IMessage::MessageType::KEY) {

        //     int idxPlayerPacket = -1;
        //     ECS::SparseArray<IComponent> PlayerComponentArray = _registries->get_components<IComponent>("PlayerComponent");
        //     for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
        //         PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
        //         if (player && player->token == packet.getToken()) {
        //             idxPlayerPacket = index;
        //             break;
        //         }
        //     }
        //     uint8_t keyCode = packet.getPayload()[0];
        //     _sceneManager->processInput(KEY_MAP(keyCode), idxPlayerPacket);
        //     continue;
        // }

        // _handlePacketsRooms(packet);

        if (ABINetwork::IMessage::MessageType(messageType) == ABINetwork::IMessage::MessageType::GET_ROOM) {
            // Send all infos for rooms.
        }

        if (ABINetwork::IMessage::MessageType(messageType) == ABINetwork::IMessage::MessageType::CREATE_ROOM) {

            if (_nbRoom >= MAX_NUMBER_ROOMS) {
                // sendErrorRoomPacket();
                return;
            }
            else {
                ABINetwork::roomInfo_t roomInfo = ABINetwork::getCreateRoomInfoFromPacket(packet);
                try {
                    GameEngine::Room newRoom(roomInfo);
                    _rooms.push_back(newRoom);
                    _nbRoom++;
                    _threads.push_back(std::make_shared<std::thread>(newRoom.run));
                } catch (const std::exception& e) {
                //     sendErrorRoomPacket();
                    std::cerr << e.what() << std::endl;
                    return;
                }
            }
        }
    }
}

GameEngine::Application::Application()
{
    // _registries = std::make_shared<ECS::Registry>();
    // _sceneManager = std::make_shared<SceneManager::ServerSceneManager>(_registries);
    _server = ABINetwork::createServer(100);
    _nbRoom = 0;
}

void GameEngine::Application::run()
{
    while (true) {
        _packetHandler();
    }
}
