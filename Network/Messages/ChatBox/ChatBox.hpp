/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ChatBoxMessage
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
 * @class ChatBoxMessage
 * @brief Messages that can be sent over a network for chatBox.
 */
class ChatBoxMessage : public AMessage
{
    public:

        /**
         * @brief Construct a new chatBox Message object.
         *
         */
        ChatBoxMessage() = default;

        /**
         * @brief Destroy the chatBox Message object.
         *
         */
        ~ChatBoxMessage() = default;

        /**
         * @brief Create a Login Payload object.
         *
         * @param userName Client who send a message.
         * @param message Client message.
         * @return Payload for chatBox.
         */
        Payload &createChatBoxPayload(std::string userName, std::string message);

        /**
         * @brief Get the ChatBox Info From Packet object.
         *
         * @return std::pair<std::string, std::string> UserName and message.
         */
        std::pair<std::string, std::string> getChatBoxInfoFromPacket(UDPPacket packet);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}
