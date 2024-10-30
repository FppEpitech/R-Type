/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** InitMessage
*/

#pragma once

#include <vector>
#include <cstdint>
#include <string>

#include "AMessage/AMessage.hpp"
#include "UDPPacket/UDPPacket.hpp"

#define INIT_INFO_DUMB_VALUE 999

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
/**
 * @class InitMessage
 * @brief Messages that can be sent at the connection with server.
 */
class InitMessage : public AMessage
{
    public:

        /**
         * @brief Construct a new Init Message object.
         *
         */
        InitMessage() = default;

        /**
         * @brief Destroy the Init Message object.
         *
         */
        ~InitMessage() = default;

        /**
         * @brief Create a Key Payload object.
         *
         * @return Payload for key.
         */

        Payload &createInitPayload();

        /**
         * @brief Get the Key Info From Packet object.
         *
         * @return int Key pressed.
         */
        int getInitInfoFromPacket(UDPPacket packet);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}
