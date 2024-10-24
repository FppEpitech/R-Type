/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIClient
*/

#pragma once

#include "ABINetwork.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
    /**
     * @brief Creates a client network unit to connect to a server.
     *
     * @param ipServer The IP address of the server to connect to.
     * @param tcp_port The port number of the server to connect to by tcp.
     * @param udp_port The port number of the server to connect to by udp.
     * @return A shared pointer to the created network unit.
     */
    std::shared_ptr<INetworkUnit> createClient(std::string ipServer, int tcp_port, int udp_port);

    /**
     * @brief Sends a registration packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param userName Client UserName to log with.
     * @param password Client Password to log with.
     */
    void sendPacketRegister(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string password);

    /**
     * @brief Sends a login packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param userName Client UserName to log with.
     * @param password Client Password to log with.
     */
    void sendPacketLogin(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string password);

    /**
     * @brief Sends a key packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param key Client's key pressed.
     */
    void sendPacketKey(std::shared_ptr<INetworkUnit> networkUnit, int key);

    /**
     * @brief Sends a logout packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketLogout(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Sends a Chatbox packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketChatbox(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string chat);

    /**
     * @brief Send a packet to the server to know all rooms.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketGetRooms(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Creates a new room on the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */

    /**
     * @brief Creates a new room on the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param roomName Name of the room.
     * @param privateRoom True if the server is private.
     * @param roomPassword Room password, empty if not private.
     * @param cheatsRoom Allow or not cheats in the room.
     * @param playerMaxRoom Set the number of player allowed in the room.
     */
    void sendPacketCreateRoom(std::shared_ptr<INetworkUnit> networkUnit, std::string roomName, bool privateRoom, std::string roomPassword, bool cheatsRoom, int playerMaxRoom);

    /**
     * @brief Joins an existing room on the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void joinRoom(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Leaves a room on the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void leaveRoom(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Deletes a room from the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void deleteRoom(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Get the Entity Creation Info From Packet object.
     *
     * @return std::tuple<std::string, int> With EntityComponent and idxEntity.
     */
    std::pair<std::string, int> getEntityCreationInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Update Component Info From Packet object.
     *
     * @return std::tuple<std::string, int> With EntityComponent and idxEntity.
     */
    std::pair<std::string, std::vector<std::variant<int, float, std::string>>> getUpdateComponentInfoFromPacket(UDPPacket packet);

}
