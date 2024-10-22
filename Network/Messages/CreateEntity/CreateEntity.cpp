/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** CreateEntity
*/

#include "CreateEntity.hpp"

namespace ABINetwork
{

    Payload& CreateEntityMessage::createEntityPayload(std::string componentType, float posX, float posY)
    {
        _payload.clear();
        _payload.push_back(static_cast<uint8_t>(componentType.size()));
        _payload.insert(_payload.end(), componentType.begin(), componentType.end());

        uint8_t* xBytes = reinterpret_cast<uint8_t*>(&posX);
        _payload.insert(_payload.end(), xBytes, xBytes + sizeof(float));

        uint8_t* yBytes = reinterpret_cast<uint8_t*>(&posY);
        _payload.insert(_payload.end(), yBytes, yBytes + sizeof(float));

        return _payload;
    }

    std::tuple<std::string, float, float> CreateEntityMessage::getEntityPayload(UDPPacket packet)
    {

        size_t currentIndex = 0;

        uint8_t componentTypeSize = packet.getPayload()[currentIndex];
        currentIndex += sizeof(uint8_t);

        std::string componentType(packet.getPayload().begin() + currentIndex, packet.getPayload().begin() + currentIndex + componentTypeSize);
        currentIndex += componentTypeSize;

        float posX;
        std::memcpy(&posX, &packet.getPayload()[currentIndex], sizeof(float));
        currentIndex += sizeof(float);

        float posY;
        std::memcpy(&posY, &packet.getPayload()[currentIndex], sizeof(float));

        return std::make_tuple(componentType, posX, posY);
    }

}