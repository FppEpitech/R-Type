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
     */
    void sendPacketRegister(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Sends a login packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketLogin(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Sends a logout packet to the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void sendPacketLogout(std::shared_ptr<INetworkUnit> networkUnit);

    /**
     * @brief Creates a new room on the server.
     *
     * @param networkUnit A shared pointer to the network unit representing the client connection.
     */
    void createRoom(std::shared_ptr<INetworkUnit> networkUnit);

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

}
