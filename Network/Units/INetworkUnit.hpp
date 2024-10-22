/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** INetworkUnit
*/

#pragma once

#include <cstdint>

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
/**
 * @class INetworkUnit
 * @brief Interface representing a network unit.
 *
 * This interface serves as the base for network entities such as clients and servers.
 * It provides a common structure for handling network-related functionality.
 */
class INetworkUnit
{
    public:

        /**
         * @brief Virtual destructor.
         *
         * Ensures that derived classes are properly cleaned up when an object of this
         * interface is deleted.
         */
        virtual ~INetworkUnit() = default;

        /**
         * @brief Pure virtual function to get the message queue to send.
         *
         * This function must be overridden by derived classes to provide the actual
         * implementation for fetching the message queue.
         *
         * @return A list of message vectors to be sent.
         */
        virtual std::list<std::vector<uint8_t>>& getMessageToSendQueue() = 0;

        /**
         * @brief Get the Token object.
         *
         * @return uint32_t
         */
        virtual uint32_t getToken() = 0;

        /**
         * @brief Get the Id Message object.
         *
         * @return uint32_t
         */
        virtual uint32_t &getIdMessage() = 0;

        /**
         * @brief Send a message of the queue.
         *
         * @param message Message to send
         */
        virtual void sendMessage(std::vector<uint8_t> message) = 0;
};

}
