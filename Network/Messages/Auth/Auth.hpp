/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AuthMessage
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
 * @class AuthMessage
 * @brief Messages that can be sent over a network for auth.
 */
class AuthMessage : public AMessage
{
    public:

        /**
         * @brief Construct a new Auth Message object.
         *
         */
        AuthMessage() = default;

        /**
         * @brief Destroy the Auth Message object.
         *
         */
        ~AuthMessage() = default;

        /**
         * @brief Create a Login Payload object.
         *
         * @param userName Client username to log with.
         * @param password Client password to log with.
         * @return Payload for Login.
         */

        Payload &createLoginPayload(std::string userName, std::string password);

        /**
         * @brief Get the Login Info From Packet object.
         *
         * @return std::pair<std::string, std::string> UserName and Password.
         */
        std::pair<std::string, std::string> getLoginInfoFromPacket(UDPPacket packet);

        /**
         * @brief Create a Register Payload object.
         *
         * @param userName Client username to register with.
         * @param password Client password to register log with.
         * @return Payload for Register.
         */
        Payload &createRegisterPayload(std::string userName, std::string password);

        /**
         * @brief Get the Register Info From Packet object.
         *
         * @return std::pair<std::string, std::string> UserName and PAssword.
         */
        std::pair<std::string, std::string> getRegisterInfoFromPacket(UDPPacket packet);

        /**
         * @brief Create a Logout Payload object.
         *
         * @return Payload for logout.
         */
        Payload &createLogoutPayload();

        /**
         * @brief Get the Logout Info From Packet object.
         *
         * @return uint32_t Token of the player logout.
         */
        uint32_t getLogoutInfoFromPacket(UDPPacket packet);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}
