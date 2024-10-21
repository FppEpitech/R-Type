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
         * @return std::vector<asio::detail::buffered_stream_storage::byte_type>& Payload for Login.
         */
        std::vector<asio::detail::buffered_stream_storage::byte_type> &createLoginPayload(std::string userName, std::string password);

        /**
         * @brief Get the Login Info From Packet object.
         *
         * @return std::pair<std::string, std::string> UserName and Password.
         */
        std::pair<std::string, std::string> getLoginInfoFromPacket();

        /**
         * @brief Create a Register Payload object.
         *
         * @param userName Client username to register with.
         * @param password Client password to register log with.
         * @return std::vector<asio::detail::buffered_stream_storage::byte_type>& Payload for Register.
         */
        std::vector<asio::detail::buffered_stream_storage::byte_type> &createRegisterPayload(std::string userName, std::string password);

        /**
         * @brief Get the Register Info From Packet object.
         *
         * @return std::pair<std::string, std::string> UserName and PAssword.
         */
        std::pair<std::string, std::string> getRegisterInfoFromPacket();

        /**
         * @brief Create a Logout Payload object.
         *
         * @return std::vector<asio::detail::buffered_stream_storage::byte_type>& Payload for logout.
         */
        std::vector<asio::detail::buffered_stream_storage::byte_type> &createLogoutPayload();

        /**
         * @brief Get the Logout Info From Packet object.
         *
         * @return uint32_t Token of the player logout.
         */
        uint32_t getLogoutInfoFromPacket();

        private:

            std::vector<asio::detail::buffered_stream_storage::byte_type> _payload;     // Content of the message in the packet.
};

}
