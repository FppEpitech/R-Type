/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AssignToken
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
#include "ABINetwork.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
/**
 * @class AssignToken
 * @brief Messages that can be sent to assign the token on client.
 */
class AssignTokenMessage : public AMessage
{

    public:

        /**
         * @brief Construct a new chatBox Message object.
         *
         */
        AssignTokenMessage() = default;

        /**
         * @brief Destroy the chatBox Message object.
         *
         */
        ~AssignTokenMessage() = default;

        /**
         * @brief Create a Update Component Payload object
         *
         * @param idxEntity idxEntity
         * @return Payload& Payload created.
         */
        Payload &createAssignTokenPayload(int idxEntity);

        /**
         * @brief Create a Entity Message::get Entity Payload object.
         *
         * @param packet Packet receive.
         * @return int indexEntity
         */
        int getAssignTokenPayload(UDPPacket packet);

        private:
            Payload _payload;     // Content of the message in the packet.
};

}
