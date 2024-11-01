/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
*/

#pragma once

#include "ABINetwork.hpp"

#include "../Messages/RoomMessage/RoomMessage.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
    /**
     * @brief Creates a server network unit.
     * This function initializes and returns a network unit that acts as a server.
     *
     * @param numberMaxPlayer Number of player max.
     * @return A shared pointer to the created network unit representing the server.
     */
    std::shared_ptr<INetworkUnit> createServer(std::size_t numberMaxPlayer);

    /**
     * @brief Get the Login Info From Packet object.
     *
     * @return std::pair<std::string, std::string> With userName and password.
     */
    std::pair<std::string, std::string> getLoginInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Register Info From Packet object.
     *
     * @return std::pair<std::string, std::string> With userName and password.
     */
    std::pair<std::string, std::string> getRegisterInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Logout Info From Packet object.
     *
     * @return uint32_t Token of the Client.
     */
    uint32_t getLogoutInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Init Info From Packet object.
     *
     * @return int Init info.
     */
    int getInitInfoFromPacket(UDPPacket packet);

    /**
     * @brief Sends a idxEntity packet to the client.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param idxEntity idxEntity to send.
     * @param token token where send the idxEntity
     */
    void sendPacketAssignToken(std::shared_ptr<INetworkUnit> networkUnit, int idxEntity, uint32_t token);

    /**
     * @brief Get the keyPressed Info From Packet object.
     *
     * @return int KeyPressed.
     */
    int getKeyPressedInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the ChatBox Info From Packet object.
     *
     * @return std::pair<std::string, std::string> With userName and chat.
     */
    std::pair<std::string, std::string> getChatBoxInfoFromPacket(UDPPacket packet);

    /**
     * @brief Send the information of to client to create new entity.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param componentType COmponent type used to call system associeted.
     * @param idxEntity Entity who want to create the new entity.
     */
    void sendPacketCreateEntity(std::shared_ptr<INetworkUnit> networkUnit, std::string componentType, int idxEntity);

    /**
     * @brief Send Update Component Information.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param componentType COmponent type used to call system associeted.
     * @param nbArgs Number of args in variadic list.
     * @param vector<std::pair<int, std::variant<int, float, std::string, bool>>> Variadic List.
     */
    void sendUpdateComponent(std::shared_ptr<INetworkUnit> networkUnit, std::string componentType, int nbArgs, std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args);

    /**
     * @brief Get the CreateRoom Info From Packet object
     *
     * @param packet Packet received by the client.
     * @return roomInfo_t
     */
    roomInfo_t getCreateRoomInfoFromPacket(UDPPacket packet);

    /**
     * @brief Send Room created informations.
     *
     * @param infos Informations about the room created.
     */
    void sendPacketRoomCreated(std::shared_ptr<INetworkUnit> networkUnit, roomInfo_t infos, uint32_t token=0);

    /**
     * @brief Get the Join Room Info From Packet object.
     *
     * @param packet Packet received by the client.
     * @return std::pair<std::string, std::string> With roomName and roomPassword.
     */
    std::pair<std::string, std::string> getJoinRoomInfoFromPacket(UDPPacket packet);

    /**
     * @brief Send wrong room password message.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketWrongRoomPassword(std::shared_ptr<INetworkUnit> networkUnit, uint32_t token=0);

    /**
     * @brief Send Full room message.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketFullRoom(std::shared_ptr<INetworkUnit> networkUnit, uint32_t token=0);

    /**
     * @brief Send authorization to join room.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param tcpPort Port tcp of the room to join.
     */
    void sendPacketAllowedToJoinRoom(std::shared_ptr<INetworkUnit> networkUnit, int tcpPort, uint32_t token=0);

    /**
     * @brief Send message with all server's rooms.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param rooms Vector of room's informations
     */
    void sendPacketRooms(std::shared_ptr<INetworkUnit> networkUnit, std::vector<ABINetwork::roomInfo_t> rooms, uint32_t token=0);

    /**
     * @brief Send message to know if client allowed to login.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param isAllowed True if client allowed to login.
     */
    void sendPacketLoginAllowed(std::shared_ptr<INetworkUnit> networkUnit, bool isAllowed, uint32_t token=0);

    /**
     * @brief Get the Queue of Connection.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    std::vector<std::pair<uint32_t, bool>>& getQueueConnection(std::shared_ptr<INetworkUnit> networkUnit);
}
