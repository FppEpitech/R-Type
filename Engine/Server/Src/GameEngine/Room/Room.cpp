/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Room
*/

#include "Room.hpp"

GameEngine::Room::Room(ABINetwork::roomInfo_t roomInfo)
{
    if (roomInfo.name.empty())
        throw RoomError("A room must has a name");
    if (roomInfo.isPrivate && roomInfo.password.empty())
        throw RoomError("A private room must has a password");

    _nameRoom = roomInfo.name;
    _private = roomInfo.isPrivate;
    _passwordRoom = roomInfo.password;
    _maxPlayers = roomInfo.playerMax;
    _cheats = roomInfo.cheats;
}

void GameEngine::Room::run()
{

}
