/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** KeyPressedMessage
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
 * @class KeyPressedMessage
 * @brief Messages that can be sent over a network for keys pressed.
 */
class KeyPressedMessage : public AMessage
{
    public:

        /**
         * @brief Construct a new KeyPressed Message object.
         *
         */
        KeyPressedMessage() = default;

        /**
         * @brief Destroy the KeyPressed Message object.
         *
         */
        ~KeyPressedMessage() = default;

        /**
         * @brief Create a Key Payload object.
         *
         * @param key Client's key pressed.
         * @return Payload for key.
         */

        Payload &createKeyPressedPayload(int key);

        /**
         * @brief Get the Key Info From Packet object.
         *
         * @return int Key pressed.
         */
        int getKeyPressedInfoFromPacket(UDPPacket packet);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}
