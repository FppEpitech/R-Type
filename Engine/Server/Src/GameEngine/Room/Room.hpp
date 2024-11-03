/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Room
*/

#pragma once

#include <unordered_map>

#include "Registry.hpp"
#include "ABIServer.hpp"
#include "ServerErrors.hpp"
#include "EventListener.hpp"
#include "ServerSceneManager.hpp"

/**
 * @brief GameEngine namespace handle all
 * classes of the GameEngine part of the server.
 *
 */
namespace GameEngine {

/**
 * @brief Room of the GameEngine.
 * It handle rooms in the server. Rooms run games.
 *
 */
class Room {

    public:

        /**
         * @brief Construct a new Room object.
         *
         */
        Room(ABINetwork::roomInfo_t roomInfo);

        /**
         * @brief Destroy the Room object
         *
         */
        ~Room() = default;

        /**
         * @brief Run the room.
         *
         */
        void run(std::mutex &mutex);

        /**
         * @brief Get the Number Of Players in the room.
         *
         * @return const int Number of players.
         */
        const int getNumberOfPlayers();

        /**
         * @brief Get the Room Info object.
         *
         * @return const ABINetwork::roomInfo_t Informations of the room.
         */
        const ABINetwork::roomInfo_t getRoomInfo();

    private:

        /**
         * @brief Function who handle the packets received.
         *
         */
        void _packetHandler();

        /**
         * @brief Function who handle the connection received.
         *
         */
        void _connectionHandler();

        /**
         * @brief Handle the packet KEY.
         *
         * @param packet Packet to handle.
         */
        void _handleKey(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle the packet Init.
         *
         * @param packet Packet to handle.
         */
        void _handleInit(ABINetwork::UDPPacket packet);

        /**
         * @brief Handle the packet LEAVE_ROOM.
         *
         * @param packet Packet to handle.
         */
        void _handleLeaveRoom(ABINetwork::UDPPacket packet);

        /**
         * @brief Send messages in queue to client.
         *
         */
        void _sendMessages();

        /**
         * @brief Run all systems of the registry.
         * This method is clocked to be frame rate dependent.
         */
        void _runSystems();

        ABINetwork::roomInfo_t  _roomInfos;         // Infos of the room.
        bool                    _isRoomOpen;        // False if the room should close.
        int                     _numberPlayers;     // Number of players in the room.

        std::shared_ptr<ABINetwork::INetworkUnit>               _roomServer;        // Network Unit of the Room.
        std::shared_ptr<ECS::Registry>                          _registries;        // vector of registries class for ECS management.
        std::shared_ptr<SceneManager::ServerSceneManager>       _sceneManager;      // load and handle scene in the ECS.
        std::shared_ptr<EventListener>                          _eventListener;     // Event listener for the server.
        std::vector<std::shared_ptr<std::thread>>               _threads;           // Vector of threads

        std::unordered_map<ABINetwork::IMessage::MessageType, std::function<void(ABINetwork::UDPPacket)>> _handlePacketsMap = {
            {ABINetwork::IMessage::MessageType::INIT, [this](ABINetwork::UDPPacket packet) { this->_handleInit(packet); }},
            {ABINetwork::IMessage::MessageType::KEY, [this](ABINetwork::UDPPacket packet) { this->_handleKey(packet); }},
            {ABINetwork::IMessage::MessageType::LEAVE_ROOM, [this](ABINetwork::UDPPacket packet) { this->_handleLeaveRoom(packet); }}
        };
};

} // namespace GameEngine
