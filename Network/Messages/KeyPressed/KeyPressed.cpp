/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** KeyPressedMessage
*/

#include "KeyPressed/KeyPressed.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

Payload & KeyPressedMessage::createKeyPressedPayload(int key)
{
    _payload.clear();

    uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&key);
    _payload.insert(_payload.end(), userNameBytes, userNameBytes + sizeof(int));

    return _payload;
}

int KeyPressedMessage::getKeyPressedInfoFromPacket(UDPPacket packet)
{

    // TODO: Verify if it works :)

    int key;
    std::memcpy(&key, &packet.getPayload()[0], sizeof(int));

    return key;
}

}
