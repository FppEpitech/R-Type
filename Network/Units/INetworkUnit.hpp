/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** INetworkUnit
*/

#pragma once

#include <list>
#include <cstdint>

#include "../Messages/UDPPacket/UDPPacket.hpp"

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

        enum LoginState {
            NONE = 0,
            LOGIN,
            JUST_FAILED         // Just failed is set only on one tick, after the tick it will be NONE.
        };

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
         * @brief Pure virtual function to set a message in the queue.
         *
         * @param message Message to send.
         */
        virtual void setMessageToSendQueue(std::vector<uint8_t> message) = 0;

        /**
         * @brief Get the Message In Queue object.
         *
         * @return std::vector<uint8_t> Message.
         */
        virtual std::vector<uint8_t> getMessageInQueue() = 0;

        /**
         * @brief Get the Received Messages.
         *
         * @return std::vector<UDPPacket> List of messages Received.
         */
        virtual std::vector<UDPPacket> getReceivedMessages() = 0;

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

        /**
         * @brief Get the Mutex object.
         *
         * @return std::mutex Mutex to lock inter thread datas.
         */
        virtual std::mutex &getMutex() = 0;

        /**
         * @brief Get the Number Client connected.
         *
         * @return int Number of client connected.
         * @throw Error if getNumberClient of a Client Unit.
         */
        virtual int getNumberClient() = 0;

        /**
         * @brief Get tcp and udp port of a server.
         * For a client, it return the tcp and udp port
         * of the server to which it is connected.
         *
         * @return std::pair<int, int> Tcp and udp ports.
         */
        virtual std::pair<int, int> getPorts() = 0;
};

}
