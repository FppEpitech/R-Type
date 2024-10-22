/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AuthMessage
*/

#include "Auth/Auth.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

Payload & AuthMessage::createLoginPayload(std::string userName, std::string password)
{
    _payload.clear();

    uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&userName);
    _payload.insert(_payload.end(), userNameBytes, userNameBytes + sizeof(std::string));

    uint8_t* passwordBytes = reinterpret_cast<uint8_t*>(&password);
    _payload.insert(_payload.end(), passwordBytes, passwordBytes + sizeof(std::string));

    return _payload;
}

Payload & AuthMessage::createRegisterPayload(std::string userName, std::string password)
{
    return createLoginPayload(userName, password);
}

Payload & AuthMessage::createLogoutPayload()
{
    _payload.clear();

    return _payload;
}

std::pair<std::string, std::string> AuthMessage::getLoginInfoFromPacket(UDPPacket packet)
{

    // TODO: Verify if it works :)

    std::string userName;
    std::memcpy(&userName, &packet.getPayload()[0], sizeof(std::string));

    std::string password;
    std::memcpy(&password, &packet.getPayload()[0 + sizeof(std::string)], sizeof(std::string));

    std::pair<std::string, std::string> infos(userName, password);
    return infos;
}

std::pair<std::string, std::string> AuthMessage::getRegisterInfoFromPacket(UDPPacket packet)
{
    return getLoginInfoFromPacket(packet);
}

uint32_t AuthMessage::getLogoutInfoFromPacket(UDPPacket packet)
{
    return packet.getToken();
}

}
