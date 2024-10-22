/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** CreateEntity
*/

#include "CreateEntity.hpp"

namespace ABINetwork
{

    Payload& CreateEntityMessage::createEntityPayload(std::string componentType, int idxEntity)
    {
        _payload.clear();
        _payload.push_back(static_cast<uint8_t>(componentType.size()));
        _payload.insert(_payload.end(), componentType.begin(), componentType.end());

        _payload.push_back(static_cast<uint8_t>(idxEntity >> 24) & 0xFF);
        _payload.push_back(static_cast<uint8_t>((idxEntity >> 16) & 0xFF));
        _payload.push_back(static_cast<uint8_t>((idxEntity >> 8) & 0xFF));
        _payload.push_back(static_cast<uint8_t>((idxEntity) & 0xFF));

        return _payload;
    }

    std::pair<std::string, int> CreateEntityMessage::getEntityPayload(UDPPacket packet)
    {

        size_t currentIndex = 0;

        uint8_t componentTypeSize = packet.getPayload()[currentIndex];
        currentIndex += sizeof(uint8_t);

        std::string componentType(packet.getPayload().begin() + currentIndex, packet.getPayload().begin() + currentIndex + componentTypeSize);
        currentIndex += componentTypeSize;

        int idxEntity = (packet.getPayload()[currentIndex] << 24) |
                            (packet.getPayload()[1 + currentIndex] << 16) |
                            (packet.getPayload()[2 + currentIndex] << 8)  |
                            packet.getPayload()[3 + currentIndex];
        currentIndex += 4;

        return std::make_pair(componentType, idxEntity);
    }

}
