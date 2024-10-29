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
     * @return A shared pointer to the created network unit.
     */
    std::shared_ptr<INetworkUnit> createClient();

    /**
     * @brief Connect a client to a server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param ipServer The IP address of the server to connect to.
     * @param tcp_port The port number of the server to connect to by tcp.
     *
     * @return False if connection failed.
     */
    bool connectToServer(std::shared_ptr<INetworkUnit> client, std::string ipServer, int tcp_port);

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
     * @brief Sends a init packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketInit(std::shared_ptr<INetworkUnit> networkUnit);

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
     * @param roomName Name of the room to join.
     * @param password Password of the room if private.
     */
    void sendPacketJoinRoom(std::shared_ptr<INetworkUnit> networkUnit, std::string roomName, std::string password = "");

    /**
     * @brief Leaves a room on the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketLeaveRoom(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Deletes a room from the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void deleteRoom(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Get the Entity Creation Info From Packet object.
     *
     * @param packet Packet received from the server.
     * @return std::tuple<std::string, int> With EntityComponent and idxEntity.
     */
    std::pair<std::string, int> getEntityCreationInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Update Component Info From Packet object.
     *
     * @param packet Packet received from the server.
     * @return std::pair<std::string, std::vector<std::variant<int, float, std::string>>>
     */
    std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> getUpdateComponentInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Created Room Info From Packet object
     *
     * @param packet Packet received from the server.
     * @return std::tuple<std::string, int, int> With roomName, tcpPort and udpPort.
     */
    std::tuple<std::string, int, int> getCreatedRoomInfoFromPacket(UDPPacket packet);

    /**
     * @brief Get the Login Allowed Info From Packet object.
     *
     * @param packet Packet received from the server.
     * @return true Client allowed to login.
     * @return false Client not allowed to login.
     */
    bool getLoginAllowedInfoFromPacket(UDPPacket packet);

    /**
     * @brief Set the Client Login object.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @param loginState The value to set.
     */
    void setClientLogin(std::shared_ptr<INetworkUnit> networkUnit, INetworkUnit::LoginState loginState);

    /**
     * @brief Get the Client Login object
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     * @return LoginState The actual state of the client login.
     */
    INetworkUnit::LoginState getClientLogin(std::shared_ptr<INetworkUnit> networkUnit);

}
