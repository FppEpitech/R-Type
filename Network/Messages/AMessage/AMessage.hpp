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
         * @brief Retrieves the message in packet format.
         */
        virtual std::vector<uint8_t> getMessagePacket() = 0;

    protected:

        std::vector<uint8_t> _creatPacket(uint8_t messageType, const std::vector<uint8_t>& payload, uint32_t messageId, uint32_t token);
};

}
