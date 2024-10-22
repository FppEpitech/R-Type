/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** CreateEntity
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
 * @class CreateEntity
 * @brief Messages that can be sent over a network for chatBox.
 */
class CreateEntityMessage : public AMessage
{
    public:

        /**
         * @brief Construct a new chatBox Message object.
         *
         */
        CreateEntityMessage() = default;

        /**
         * @brief Destroy the chatBox Message object.
         *
         */
        ~CreateEntityMessage() = default;

        /**
         * @brief Create a Entity Payload object
         *
         * @param componentType Component Type for call system
         * @param posX Position X of entity.
         * @param posY Position Y of entity.
         * @return Payload& The payload.
         */
        Payload &createEntityPayload(std::string componentType, float posX, float posY);

        /**
         * @brief Create a Entity Message::get Entity Payload object.
         *
         * @param packet Packet receive.
         * @return std::tuple<std::string, float, float> Data receive in packet payload.
         */
        std::tuple<std::string, float, float> getEntityPayload(UDPPacket packet);

        private:

            Payload _payload;     // Content of the message in the packet.
};

}