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

    uint32_t userNameLength = userName.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&userNameLength), reinterpret_cast<uint8_t*>(&userNameLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), userName.begin(), userName.end());

    uint32_t passwordLength = password.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&passwordLength), reinterpret_cast<uint8_t*>(&passwordLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), password.begin(), password.end());

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

    size_t offset = 0;

    uint32_t userNameLength;
    std::memcpy(&userNameLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string userName;
    userName.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), userNameLength);
    offset += userNameLength;

    uint32_t passwordLength;
    std::memcpy(&passwordLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string password;
    password.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), passwordLength);
    offset += passwordLength;

    return {userName, password};
}

std::pair<std::string, std::string> AuthMessage::getRegisterInfoFromPacket(UDPPacket packet)
{
    return getLoginInfoFromPacket(packet);
}

uint32_t AuthMessage::getLogoutInfoFromPacket(UDPPacket packet)
{
    return packet.getToken();
}

Payload &AuthMessage::createAllowedLoginPayload(bool isAllowed)
{
    _payload.clear();

    bool allowed = isAllowed;
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&allowed), reinterpret_cast<uint8_t*>(&allowed) + sizeof(bool));;

    return _payload;
}

bool AuthMessage::getLoginAllowedInfoFromPacket(UDPPacket packet)
{
    bool isAllowed;
    std::memcpy(&isAllowed, &packet.getPayload()[0], sizeof(bool));

    return isAllowed;
}

}
