/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** IMessage
*/

#pragma once

#include <vector>
#include <cstdint>
#include <asio.hpp>

#define VERSION 0x01
typedef std::vector<uint8_t> Payload;

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
         * @brief Enum for message Type.
         * The message type will be sent in the payload.
         */
        enum class MessageType : uint8_t {
            LOGIN               = 0x00,
            REGISTER            = 0x01,
            LOGOUT              = 0x02,
            CHAT_BOX_MESSAGE    = 0x03,
            CREATE_ENTITY       = 0x04,
            UPDATE_COMPONENT    = 0x05,
            DELETE_ENTITY       = 0x06,
            CREATE_ROOM         = 0x07,
            DELETE_ROOM         = 0x08,
            JOIN_ROOM           = 0x09,
            GET_ROOM            = 0x0A,
            LEAVE_ROOM          = 0x0B,
            KEY                 = 0x0C,
            WRONG_ROOM_PASSWORD = 0x0D,
            FULL_ROOM           = 0x0E,
            INIT                = 0x0F,
            ASSIGNTOKEN         = 0x10,
        };

        /**
         * @brief Virtual destructor.
         *
         * Ensures that derived classes are properly cleaned up when an object of this
         * interface is deleted.
         */
        virtual ~IMessage() = default;

        /**
         * @brief Create a packet for a message.
         *
         * @param messageType Type of the message using the enum MessageType
         * @param payload Payload related to the Message type.
         * @param messageId Id of Message.
         * @param token Token's User who send the message to.
         * @return std::vector<uint8_t> Packet to send.
         */
        virtual std::vector<uint8_t> _createPacket(uint8_t messageType, const std::vector<uint8_t>& payload, uint32_t &messageId, uint32_t token) = 0;
};

}
