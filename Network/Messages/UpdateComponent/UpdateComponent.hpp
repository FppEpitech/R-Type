/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** UpdateComponent
*/

#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <tuple>


#include "AMessage/AMessage.hpp"
#include "UDPPacket/UDPPacket.hpp"
#include "UDPPacket/UDPPacket.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
/**
 * @class UpdateComponent
 * @brief Messages that can be sent over a network for chatBox.
 */
class UpdateComponentMessage : public AMessage
{

    enum Type {
        Int = 1,
        Float,
        String
    };

    public:

        /**
         * @brief Construct a new chatBox Message object.
         *
         */
        UpdateComponentMessage() = default;

        /**
         * @brief Destroy the chatBox Message object.
         *
         */
        ~UpdateComponentMessage() = default;

        /**
         * @brief Create a Update Component Payload object
         *
         * @param componentType Component type to update
         * @param numArgs Number of Args in variadic.
         * @param ... Variadic args.
         * @return Payload& Payload created.
         */
        Payload &createUpdateComponentPayload(std::string componentType, std::size_t numArgs, ...);

        /**
         * @brief Create a Entity Message::get Entity Payload object.
         *
         * @param packet Packet receive.
         * @return std::pair<std::string, std::vector<std::variant<int, float, std::string>>> Data receive in packet payload.
         */
        std::pair<std::string, std::vector<std::variant<int, float, std::string>>> getUpdateComponentPayload(UDPPacket packet);

        private:
            Payload _payload;     // Content of the message in the packet.
};

}
