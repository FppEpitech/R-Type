/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** IMessage
*/

#pragma once

#include <vector>
#include <cstdint>

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
/**
 * @class IMessage
 * @brief Interface for messages that can be sent over a network.
 *
 * This class defines the structure for network messages and requires derived classes
 * to implement the method to retrieve the message in packet format.
 */
class IMessage
{
    public:

        /**
         * @brief Virtual destructor.
         *
         * Ensures that derived classes are properly cleaned up when an object of this
         * interface is deleted.
         */
        virtual ~IMessage() = default;

        /**
         * @brief Retrieves the message in packet format.
         *
         * This method must be implemented by any class that inherits from `IMessage`.
         * It should return the message as a vector of bytes, ready to be sent over a network.
         *
         * @return A vector of bytes representing the message packet.
         */
        virtual std::vector<uint8_t> getMessagePacket() = 0;
};

}
