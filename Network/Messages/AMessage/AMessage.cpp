/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AMessage
*/

#include "AMessage.hpp"

namespace ABINetwork
{

std::vector<uint8_t> AMessage::_creatPacket(uint8_t messageType, const std::vector<uint8_t>& payload, uint32_t messageId, uint32_t token)
{
    std::vector<uint8_t> packet;

    uint32_t payloadLength = static_cast<uint32_t>(payload.size());

    packet.push_back(VERSION);
    packet.push_back(messageType);

    packet.push_back(static_cast<uint8_t>(messageId >> 8));
    packet.push_back(static_cast<uint8_t>(messageId & 0xFF));
    messageId = (messageId + 1) % 65536;

    packet.push_back(static_cast<uint8_t>((token >> 24) & 0xFF));
    packet.push_back(static_cast<uint8_t>((token >> 16) & 0xFF));
    packet.push_back(static_cast<uint8_t>((token >> 8) & 0xFF));
    packet.push_back(static_cast<uint8_t>(token & 0xFF));

    packet.push_back(static_cast<uint8_t>(payloadLength >> 24));
    packet.push_back(static_cast<uint8_t>(payloadLength >> 16));
    packet.push_back(static_cast<uint8_t>(payloadLength >> 8));
    packet.push_back(static_cast<uint8_t>(payloadLength & 0xFF));

    packet.insert(packet.end(), payload.begin(), payload.end());

    uint16_t checksum = 0;
    for (const auto& byte : packet)
        checksum += byte;
    packet.push_back(static_cast<uint8_t>(checksum >> 8));
    packet.push_back(static_cast<uint8_t>(checksum & 0xFF));
    return packet;
}

}
