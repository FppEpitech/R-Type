/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** InitMessage
*/

#include "InitMessage/InitMessage.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

Payload & InitMessage::createInitPayload()
{
    int initInfo = 999;
    _payload.clear();

    uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&initInfo);
    _payload.insert(_payload.end(), userNameBytes, userNameBytes + sizeof(int));

    return _payload;
}

int InitMessage::getInitInfoFromPacket(UDPPacket packet)
{
    int initInfo;
    std::memcpy(&initInfo, &packet.getPayload()[0], sizeof(int));

    return initInfo;
}

}
