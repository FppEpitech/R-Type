/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AMessage
*/

#pragma once

#include <vector>
#include <cstdint>

#include "IMessage.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
/**
 * @class AMessage
 * @brief Interface for messages that can be sent over a network.
 *
 * This class defines the structure for network messages and requires derived classes
 * to implement the method to retrieve the message in packet format.
 */
class AMessage : public IMessage
{
    public:

        /**
         * @brief Destroy the AMessage object.
         *
         */
        virtual ~AMessage() = default;

        /**
         * @brief Create a packet for a message.
         *
         * @param messageType Type of the message using the enum MessageType
         * @param payload Payload related to the Message type.
         * @param messageId Id of Message.
         * @param token Token's User who send the message to.
         * @return std::vector<uint8_t> Packet to send.
         */
        std::vector<uint8_t> _createPacket(uint8_t messageType, const std::vector<uint8_t>& payload, uint32_t &messageId, uint32_t token);

    protected:

        std::vector<uint8_t> _packet; // Packet to send.
};

}
