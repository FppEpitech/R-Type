/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** UpdateComponentMessage
*/

#include "UpdateComponent.hpp"

namespace ABINetwork
{

    Payload& UpdateComponentMessage::createUpdateComponentPayload(std::string componentType, std::size_t numArgs, ...)
    {
        _payload.clear();


        _payload.push_back(static_cast<uint8_t>(componentType.size()));
        _payload.insert(_payload.end(), componentType.begin(), componentType.end());

        _payload.push_back(static_cast<uint8_t>(numArgs));

        va_list args;
        va_start(args, numArgs);

        for (size_t i = 0; i < numArgs; i++) {
            int type = va_arg(args, int);

            if (type == Type::Int) {
                int value = va_arg(args, int);
                _payload.push_back(static_cast<uint8_t>((value >> 24) & 0xFF));
                _payload.push_back(static_cast<uint8_t>((value >> 16) & 0xFF));
                _payload.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
                _payload.push_back(static_cast<uint8_t>(value & 0xFF));
            } else if (type == Type::Float) {
                float value = static_cast<float>(va_arg(args, double));
                uint8_t* bytePtr = reinterpret_cast<uint8_t*>(&value);
                _payload.insert(_payload.end(), bytePtr, bytePtr + sizeof(float));
            } else if (type == Type::String) {
                std::string value = std::string(va_arg(args, char *));
                _payload.push_back(static_cast<uint8_t>(value.size()));
                _payload.insert(_payload.end(), value.begin(), value.end());
            } else if (type == Type::Bool) {
                int value = va_arg(args, int);
                _payload.push_back(static_cast<uint8_t>(value));
            } else {
                continue;
            }
        }

        va_end(args);

        return _payload;
    }

    std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> UpdateComponentMessage::getUpdateComponentPayload(UDPPacket packet)
    {

        size_t index = 0;

        uint8_t componentTypeSize = packet.getPayload()[index++];
        std::string componentType(packet.getPayload().begin() + index, packet.getPayload().begin() + index + componentTypeSize);
        index += componentTypeSize;

        uint8_t numArgs = packet.getPayload()[index++];
        std::vector<std::variant<int, float, std::string>> arguments;

        for (size_t i = 0; i < numArgs; ++i)
        {
            int type = packet.getPayload()[index++];

            if (type == Type::Int) {
                int value = (packet.getPayload()[index] << 24) | (packet.getPayload()[index + 1] << 16) | (packet.getPayload()[index + 2] << 8) | packet.getPayload()[index + 3];
                arguments.push_back(value);
                index += 4;
            } else if (type == Type::Float) {
                float value;
                std::memcpy(&value, &packet.getPayload()[index], sizeof(float));
                arguments.push_back(value);
                index += sizeof(float);
            } else if (type == Type::String) {
                uint8_t stringSize = packet.getPayload()[index++];
                std::string value(reinterpret_cast<const char*>(&packet.getPayload()[index]), stringSize);
                arguments.push_back(value);
                index += stringSize;
            } else if (type == Type::Bool) {
                bool value = static_cast<bool>(packet.getPayload()[index++]);
                arguments.push_back(value);
            } else {
                continue;
            }
        }
        return std::make_pair(componentType, arguments);
    }

}
