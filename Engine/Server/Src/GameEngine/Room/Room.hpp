/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Room
*/

#pragma once

#include "ABIServer.hpp"
#include "ServerErrors.hpp"

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
        static void run();

    private:

        std::string         _nameRoom;
        std::string         _passwordRoom;
        bool                _cheats;
        bool                _private;
        int                 _maxPlayers;
};

} // namespace GameEngine
