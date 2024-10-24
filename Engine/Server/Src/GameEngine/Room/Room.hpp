/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Room
*/

#pragma once

#include "Registry.hpp"
#include "ABIServer.hpp"
#include "ServerErrors.hpp"
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
        void run();

    private:

        std::string         _nameRoom;          // Room name.
        std::string         _passwordRoom;      // Room password if private.
        bool                _cheats;            // True if cheats are allowed.
        bool                _private;           // True if it's a private room.
        int                 _maxPlayers;        // Max number of player in the room.

        bool                _isRoomOpen;        // False if the room should close.

        std::shared_ptr<ABINetwork::INetworkUnit>               _roomServer;        // Network Unit of the Room.
        std::shared_ptr<ECS::Registry>                          _registries;        // vector of registries class for ECS management.
        std::shared_ptr<SceneManager::ServerSceneManager>       _sceneManager;      // load and handle scene in the ECS.

        /**
         * @brief Function who handle the packets received.
         *
         */
        void _packetHandler();
};

} // namespace GameEngine
