/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AssignToken
*/

#include "AssignToken.hpp"

namespace ABINetwork
{

    Payload& AssignTokenMessage::createAssignTokenPayload(int idxEntity)
    {
        _payload.clear();

        uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&idxEntity);
        _payload.insert(_payload.end(), userNameBytes, userNameBytes + sizeof(int));

        return _payload;
    }

    int AssignTokenMessage::getAssignTokenPayload(UDPPacket packet)
    {
        int idxEntity;
        std::memcpy(&idxEntity, &packet.getPayload()[0], sizeof(int));

        return idxEntity;
    }

}
