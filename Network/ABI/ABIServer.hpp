/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
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
     * @brief Creates a server network unit.
     * This function initializes and returns a network unit that acts as a server.
     *
     * @return A shared pointer to the created network unit representing the server.
     */
    std::shared_ptr<INetworkUnit> createServer();

    /**
     * @brief Get the Login Info From Packet object.
     *
     * @return std::pair<std::string, std::string> With userName and password.
     */
    std::pair<std::string, std::string> getLoginInfoFromPacket();

    /**
     * @brief Get the Register Info From Packet object.
     *
     * @return std::pair<std::string, std::string> With userName and password.
     */
    std::pair<std::string, std::string> getRegisterInfoFromPacket();

    /**
     * @brief Get the Logout Info From Packet object.
     *
     * @return uint32_t Token of the Client.
     */
    uint32_t getLogoutInfoFromPacket();
}
