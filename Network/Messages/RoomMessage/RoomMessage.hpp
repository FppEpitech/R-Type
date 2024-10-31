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

#include "../AMessage/AMessage.hpp"
#include "../UDPPacket/UDPPacket.hpp"

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
        std::string name = "";
        bool isPrivate = false;
        std::string password = "";
        bool cheats = false;
        int playerMax = 0;
        int tcpPort = 0;
        int udpPort = 0;
        int nbPlayers = 0;
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
         * @brief Create a Create Room Payload object.
         *
         * @param roomName Name of the room.
         * @param privateRoom True if the server is private.
         * @param roomPassword Room password, empty if not private.
         * @param cheatsRoom Allow or not cheats in the room.
         * @param playerMaxRoom Set the number of player allowed in the room.
         * @return Payload& for get Room.
         */
        Payload &createCreateRoomPayload(std::string roomName, bool privateRoom, std::string roomPassword, bool cheatsRoom, int playerMaxRoom);

        /**
         * @brief Get the Create Room Info From Packet object.
         *
         * @param packet Packet to get infos.
         * @return roomInfo_t Structure of Create room infos.
         */
        roomInfo_t getCreateRoomInfoFromPacket(UDPPacket packet);

        /**
         * @brief Create a Create Room Payload object.
         *
         * @param infos Infos about the room created.
         * @return Payload& for create room.
         */
        Payload &createCreatedRoomPayload(roomInfo_t infos);

        /**
         * @brief Create a Join Room Payload object.
         *
         * @param roomName Name of the room to join.
         * @param password Password of the room, empty if no password needed.
         * @return Payload& for join room.
         */
        Payload &createJoinRoomPayload(std::string roomName, std::string password);

        /**
         * @brief Create a Leave Room Payload object.
         *
         * @return Payload& for leaving room.
         */
        Payload & createLeaveRoomPayload();

        /**
         * @brief Get the Created Room Info From Packet object.
         *
         * @param packet Packet to get infos.
         * @return std::tuple<std::string, int, int> Infos of created room.
         */
        std::tuple<std::string, int, int> getCreatedRoomInfoFromPacket(UDPPacket packet);

        /**
         * @brief Get the Join Room Info From Packet object.
         *
         * @param packet Packet to get infos.
         * @return std::pair<std::string, std::string> With roomName and roomPassword.
         */
        std::pair<std::string, std::string> getJoinRoomInfoFromPacket(UDPPacket packet);

        /**
         * @brief Create a Wrong Room Password Payload object.
         *
         * @return Payload& for wrong password.
         */
        Payload &createWrongRoomPasswordPayload();

        /**
         * @brief Create a Full Room Payload object.
         *
         * @return Payload& for full room.
         */
        Payload &createFullRoomPayload();

        /**
         * @brief Create a Allowed To Join Room Payload object.
         *
         * @param tcpPort Port tcp of the room to join.
         * @return Payload& for authorization to join room.
         */
        Payload &createAllowedToJoinRoomPayload(int tcpPort);

        /**
         * @brief Create a Rooms Payload object.
         *
         * @param rooms Vector of rooms informations.
         * @return Payload& for all rooms informations.
         */
        Payload &createRoomsPayload(std::vector<ABINetwork::roomInfo_t> rooms);

        /**
         * @brief Get the Rooms Info From Packet object.
         *
         * @param packet Packet to get infos.
         * @return std::vector<ABINetwork::roomInfo_t> List of room infos.
         */
        std::vector<ABINetwork::roomInfo_t> getRoomsInfoFromPacket(UDPPacket packet);

        /**
         * @brief Get the Allowed Join Room Info From Packet object.
         *
         * @param packet Packet to get infos.
         * @return int Port tcp.
         */
        int getAllowedJoinRoomInfoFromPacket(UDPPacket packet);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}
