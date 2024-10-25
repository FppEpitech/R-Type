/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** RoomMessage
*/

#pragma once

#include <vector>
#include <cstdint>
#include <string>

#include "AMessage/AMessage.hpp"
#include "UDPPacket/UDPPacket.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

    /**
     * @brief Contain the data of a Room.
     *
     */
    typedef struct roomInfo_s {
        std::string name;
        bool isPrivate;
        std::string password;
        bool cheats;
        int playerMax;
        int tcpPort = 0;
        int udpPort = 0;
    } roomInfo_t;

/**
 * @class RoomMessage
 * @brief Messages that can be sent over a network for rooms.
 */
class RoomMessage : public AMessage
{
    public:

        /**
         * @brief Construct a new Room Message object.
         *
         */
        RoomMessage() = default;

        /**
         * @brief Destroy the Room Message object.
         *
         */
        ~RoomMessage() = default;

        /**
         * @brief Create a getRoom Payload object.
         *
         * @return Payload for getRoom.
         */
        Payload &createGetRoomPayload();

        /**
         * @brief Create a Create Room Payload object
         *
         * @param roomName Name of the room.
         * @param privateRoom True if the server is private.
         * @param roomPassword Room password, empty if not private.
         * @param cheatsRoom Allow or not cheats in the room.
         * @param playerMaxRoom Set the number of player allowed in the room.
         * @return Payload& for createRoom.
         */
        Payload &createCreateRoomPayload(std::string roomName, bool privateRoom, std::string roomPassword, bool cheatsRoom, int playerMaxRoom);

        /**
         * @brief Get the Create Room Info From Packet object
         *
         * @param packet Packet to get infos.
         * @return roomInfo_t Structure of Create room infos.
         */
        roomInfo_t getCreateRoomInfoFromPacket(UDPPacket packet);

        /**
         * @brief Create a Create Room Payload object.
         *
         * @param infos Infos about the room created.
         * @return Payload&
         */
        Payload &createCreatedRoomPayload(roomInfo_t infos);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}
