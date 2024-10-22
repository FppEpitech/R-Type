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
     * @param posX Pos X of new Entity.
     * @param posY Pos Y of new Entity.
     */
    void sendPacketEntity(std::shared_ptr<INetworkUnit> networkUnit, std::string componentType, float posX, float posY);
}
