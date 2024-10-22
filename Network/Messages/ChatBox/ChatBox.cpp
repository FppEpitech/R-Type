/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ChatBox
*/

#include "ChatBox/ChatBox.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

Payload & ChatBoxMessage::createChatBoxPayload(std::string userName, std::string message)
{
    _payload.clear();

    uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&userName);
    _payload.insert(_payload.end(), userNameBytes, userNameBytes + sizeof(std::string));

    uint8_t* passwordBytes = reinterpret_cast<uint8_t*>(&message);
    _payload.insert(_payload.end(), passwordBytes, passwordBytes + sizeof(std::string));

    return _payload;
}

std::pair<std::string, std::string> ChatBoxMessage::getChatBoxInfoFromPacket(UDPPacket packet)
{

    // TODO: Verify if it works :)

    std::string userName;
    uint32_t userNameLength;
    std::memcpy(&userName, &packet.getPayload()[0], sizeof(std::string));

    std::string message;
    std::memcpy(&message, &packet.getPayload()[0 + sizeof(std::string)], sizeof(std::string));

    std::pair<std::string, std::string> infos(userName, message);
    return infos;
}

}
