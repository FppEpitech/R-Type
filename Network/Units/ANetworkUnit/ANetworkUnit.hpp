/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ANetworkUnit
*/

#pragma once

#include <list>
#include <vector>
#include <cstdint>

#include "INetworkUnit.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

/**
 * @class ANetworkUnit
 * @brief Abstract base class for network units.
 *
 * This class inherits from `INetworkUnit` and can be used as a base for network entities
 * like clients and servers. It provides a common structure for derived classes.
 */
class ANetworkUnit : public INetworkUnit
{
    public:

        /**
         * @brief Construct a new ANetworkUnit object.
         *
         */
        ANetworkUnit();

        /**
         * @brief Destructor.
         *
         * Default destructor for `ANetworkUnit`, which is automatically called when
         * an object of this class is destroyed.
         */
        ~ANetworkUnit() = default;

        /**
         * @brief Get the Message To Send Queue object
         *
         * @return std::list<std::vector<uint8_t>>.
         */
        std::list<std::vector<uint8_t>>& getMessageToSendQueue() override;

        /**
         * @brief Set the Message To Send Queue object.
         *
         * @param message Message to send.
         */
        void setMessageToSendQueue(std::vector<uint8_t> message) override;

        /**
         * @brief Get the Message In Queue object.
         *
         * @return std::vector<uint8_t> Message.
         */
        std::vector<uint8_t> getMessageInQueue() override;

        /**
         * @brief Get the Received Messages.
         *
         * @return std::vector<UDPPacket> List of messages Received.
         */
        std::vector<UDPPacket> getReceivedMessages() override;

        /**
         * @brief Get the Token object.
         *
         * @return uint32_t
         */
        uint32_t getToken() override;

        /**
         * @brief Get the Id Message object.
         *
         * @return uint32_t
         */
        uint32_t &getIdMessage() override;

        /**
         * @brief Send all messages of the queue.
         *
         * @param message Message to send.
         */
        virtual void sendMessage(std::vector<uint8_t> message) = 0;

        /**
         * @brief Get the Mutex object.
         *
         * @return std::mutex Mutex to lock inter thread data.
         */
        std::mutex &getMutex() override;

    protected:

        uint32_t                                _token;                      // Token of client (used to be identify on server)
        uint32_t                                _messageId;                  // Current Message ID (auto-incremente every send of message)
        std::list<std::vector<uint8_t>>         _queueMessageToSend;         // Message to send queue
        std::vector<UDPPacket>                  _queueMessage;               // Message queue
        std::mutex                              _mutex;                      // Mutex to lock inter threads data.
};

}
