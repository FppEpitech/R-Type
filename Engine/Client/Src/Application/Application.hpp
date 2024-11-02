/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#pragma once

#include <iostream>
#include <unordered_map>

#include "ABIClient.hpp"
#include "Registry.hpp"
#include "InitShader.hpp"
#include "InitWindow.hpp"
#include "ClientErrors.hpp"
#include "../GetGraphicalLibrary/IGraphic.hpp"
#include "EventListener.hpp"
#include "ClientSceneManager.hpp"
#include "GetGraphicalLibrary.hpp"
#include "DrawOBJ/DrawOBJSystem.hpp"
#include "DrawText/DrawTextSystem.hpp"
#include "DrawTexture/DrawTextureSystem.hpp"
#include "../GetGraphicalLibrary/IGraphic.hpp"
#include "DrawHitBoxes/DrawHitBoxesSystem.hpp"
#include "DrawTextureRect/DrawTextureRectSystem.hpp"
#include "NetworkConnection/NetworkConnectionComponent.hpp"
#include "SpriteSheetAnimation/SpriteSheetAnimationSystem.hpp"

typedef struct networkInstance_s {
    int tcpPort = 0;
    int udpPort = 0;
    std::string password = "";
} networkInstance_t;

/**
 * @brief Application class
 * It's the main class of the client application
 */
class Application {

    public:

        /**
         * @brief Construct a new Application object
         *
         */
        Application();

        /**
         * @brief Destroy the Application object
         *
         */
        ~Application();

        /**
         * @brief Run the application
         *
         */
        void run();

    private:

        /**
         * @brief Callback function who handle the packet receive.
         *
         */
        void _packetHandler();

        /**
         * @brief Handle packet received by the server after room creation.
         *
         * @param packet Packet receive by the server.
         */
        void _handleCreateRoomPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server after send join room request.
         *
         * @param packet Packet receive by the server.
         */
        void _handleJoinRoomPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server after wrong password room request.
         *
         * @param packet Packet receive by the server.
         */
        void _handleWrongRoomPasswordPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server for full room.
         *
         * @param packet Packet receive by the server.
         */
        void _handleFullRoomPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server for login.
         *
         * @param packet
         */
        void _handleLoginPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server for update component.
         *
         * @param packet
         */
        void _handleUpdateComponentPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server for assign token.
         *
         * @param packet
         */
        void _handleAssignTokenPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle packet received by the server for get room.
         *
         * @param packet
         */
        void _handleGetRoomPacket(ABINetwork::UDPPacket packet);

        /**
         * @brief Function who handle keyboard signal.
         *
         * @param key Key entered.
         */
        void _keyboardHandler(std::size_t key);

        /**
         * @brief Initialize default graphics systems.
         *
         */
        void _initDefaultGraphicSystems();

        /**
         * @brief Send Messages to the server.
         * This method is multi-threaded.
         * It take all messages in the client queue and send them.
         *
         */
        void _sendMessages();


        std::shared_ptr<ECS::Registry>                                              _registry;          // Registries for each scene.
        std::vector<std::function<void(ECS::Registry& reg, int idxPacketEntities)>> _defaultSystems;    // Default system.
        std::shared_ptr<ABINetwork::INetworkUnit>                                   _client;            // Client Network unit.
        std::shared_ptr<SceneManager::ClientSceneManager>                           _sceneManager;      // load and handle scene in the ECS.
        std::shared_ptr<EventListener>                                              _eventListener;     // Event listener for the client.
        std::shared_ptr<IGraphic>                                                   _libGraphic;        // Graphic library.
        std::vector<std::shared_ptr<std::thread>>                                   _threads;           // Vector of threads

        std::unordered_map<ABINetwork::IMessage::MessageType, std::function<void(ABINetwork::UDPPacket)>> _handlePacketsMap = {
            {ABINetwork::IMessage::MessageType::CREATE_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleCreateRoomPacket(packet); }},
            {ABINetwork::IMessage::MessageType::JOIN_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleJoinRoomPacket(packet); }},
            {ABINetwork::IMessage::MessageType::WRONG_ROOM_PASSWORD, [this](ABINetwork::UDPPacket packet) { this->_handleWrongRoomPasswordPacket(packet); }},
            {ABINetwork::IMessage::MessageType::FULL_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleFullRoomPacket(packet); }},
            {ABINetwork::IMessage::MessageType::LOGIN, [this](ABINetwork::UDPPacket packet) { this->_handleLoginPacket(packet); }},
            {ABINetwork::IMessage::MessageType::UPDATE_COMPONENT, [this](ABINetwork::UDPPacket packet) { this->_handleUpdateComponentPacket(packet); }},
            {ABINetwork::IMessage::MessageType::ASSIGNTOKEN, [this](ABINetwork::UDPPacket packet) { this->_handleAssignTokenPacket(packet); }},
            {ABINetwork::IMessage::MessageType::GET_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleGetRoomPacket(packet); }}
        };

        networkInstance_t _serverInfos; // Informations about the server.
        networkInstance_t _roomInfos;   // Informations about the room.
        int               _idxEntityPlayer;   // IdxEntity
};
