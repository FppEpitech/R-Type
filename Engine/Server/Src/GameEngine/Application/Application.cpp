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
        uint8_t keyCode = packet.getPayload()[0];

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
            _sceneManager->processInput(KEY_MAP(keyCode), idxPlayerPacket);
        }
    }
}

void GameEngine::Application::_connectionHandler()
{
    std::shared_ptr<ABINetwork::Server> serverPtr = std::dynamic_pointer_cast<ABINetwork::Server>(_server);

    std::vector<uint32_t>& queueConnection = serverPtr->getqueueConnection();

    while (!queueConnection.empty()) {
        uint32_t tokenConnection = queueConnection.front();
        queueConnection.erase(queueConnection.begin());
        std::cout << "Player with token: 0x" << std::hex << std::setw(8) << std::setfill('0') << tokenConnection << std::dec << " want to connect" << std::endl;



        ECS::SparseArray<IComponent> PlayerComponentArray = this->_registries->get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> DrawComponentArray = this->_registries->get_components<IComponent>("DrawComponent");

        for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
            PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
            if (player && player->token == 0) {
                player->token = tokenConnection;

                if (index < DrawComponentArray.size()) {
                    DrawComponent* draw = dynamic_cast<DrawComponent*>(DrawComponentArray[index].get());
                    if (draw)
                        draw->draw = true;

                    // reg->messageType = 0x01;
                    // reg->payload.clear();
                    // std::string componentType = "DrawComponent";
                    // reg->payload.push_back(static_cast<uint8_t>(componentType.size()));
                    // reg->payload.insert(reg->payload.end(), componentType.begin(), componentType.end());
                    // reg->payload.push_back(static_cast<uint8_t>(index >> 24) & 0xFF);
                    // reg->payload.push_back(static_cast<uint8_t>((index >> 16) & 0xFF));
                    // reg->payload.push_back(static_cast<uint8_t>((index >> 8) & 0xFF));
                    // reg->payload.push_back(static_cast<uint8_t>((index) & 0xFF));
                    // bool drawable = true;
                    // uint8_t* xBytes = reinterpret_cast<uint8_t*>(&drawable);
                    // reg->payload.insert(reg->payload.end(), xBytes, xBytes + sizeof(bool));
                    // std::vector<uint8_t> packet = createPacket(reg->messageType, reg->payload);
                    // for (auto it = getClientsList().begin(); it != getClientsList().end(); ++it) {
                    //     asio::ip::udp::endpoint& endpoint = it->second;
                    //     sendMessage(packet, endpoint);
                    // }

                    ABINetwork::sendUpdateComponent(_server, "DrawComponent", 4, ABINetwork::Type::Int, index, ABINetwork::Type::Bool, true);
                }
                break;
            }
        }
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

        _connectionHandler();
        _packetHandler();
        ABINetwork::sendMessages(_server);
        // if (!noPlayerConnected())
            _registries->run_systems(-1);
        // else
            // SLEEP(0.5);
    //     // TODO : put this in a thread for better optimization
    //     if (!_registries->_queue_payload.empty()) {
    //         for (std::size_t index = 0; index < _registries->_queue_payload.size() && index < _registries->_queue_messageType.size(); index++) {
    //             std::vector<uint8_t> packet = this->_server->createPacket(_registries->_queue_messageType[index], this->_registries->_queue_payload[index]);
    //             for (auto it = this->_server->getClientsList().begin(); it != this->_server->getClientsList().end(); ++it) {
    //                 asio::ip::udp::endpoint& endpoint = it->second;
    //                 this->_server->sendMessage(packet, endpoint);
    //             }
    //             _registries->_queue_messageType.erase(_registries->_queue_messageType.begin() + index);
    //             _registries->_queue_payload.erase(_registries->_queue_payload.begin() + index);
    //         }
        // }
    }
}
