/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** UpdateComponentMessage
*/

#include "UpdateComponent.hpp"

namespace ABINetwork
{

    Payload& UpdateComponentMessage::createUpdateComponentPayload(std::string componentType, std::size_t numArgs,
    std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args)
    {
        _payload.clear();


        _payload.push_back(static_cast<uint8_t>(componentType.size()));
        _payload.insert(_payload.end(), componentType.begin(), componentType.end());

        _payload.push_back(static_cast<uint8_t>(numArgs));

        for (size_t i = 0; i < numArgs; i++) {
            int type = args[i].first;
            std::cout << "type encoded: [" << type << "]" << std::endl;
            _payload.push_back(static_cast<uint8_t>((type >> 24) & 0xFF));
            _payload.push_back(static_cast<uint8_t>((type >> 16) & 0xFF));
            _payload.push_back(static_cast<uint8_t>((type >> 8) & 0xFF));
            _payload.push_back(static_cast<uint8_t>(type & 0xFF));

            const auto& value = args[i].second;
            if (type == Type::Int) {
                int intValue = std::get<int>(value);
                _payload.push_back(static_cast<uint8_t>((intValue >> 24) & 0xFF));
                _payload.push_back(static_cast<uint8_t>((intValue >> 16) & 0xFF));
                _payload.push_back(static_cast<uint8_t>((intValue >> 8) & 0xFF));
                _payload.push_back(static_cast<uint8_t>(intValue & 0xFF));
            } else if (type == Type::Float) {
                float floatValue = std::get<float>(value);
                uint8_t* bytePtr = reinterpret_cast<uint8_t*>(&floatValue);
                _payload.insert(_payload.end(), bytePtr, bytePtr + sizeof(float));
            } else if (type == Type::String) {
                std::string stringValue = std::get<std::string>(value);
                _payload.push_back(static_cast<uint8_t>(stringValue.size()));
                _payload.insert(_payload.end(), stringValue.begin(), stringValue.end());
            } else if (type == Type::Bool) {
                bool boolValue = std::get<bool>(value);
                _payload.push_back(static_cast<uint8_t>(boolValue));
            } else {
                continue;
            }
        }

        return _payload;
    }

    std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> UpdateComponentMessage::getUpdateComponentPayload(UDPPacket packet)
    {
        std::cout << std::endl << "In getUpdateComponentPayload" << std::endl;
        size_t index = 0;

        uint8_t componentTypeSize = packet.getPayload()[index++];
        std::string componentType(packet.getPayload().begin() + index, packet.getPayload().begin() + index + componentTypeSize);
        index += componentTypeSize;

        std::size_t numArgs = static_cast<std::size_t>(packet.getPayload()[index++]);
        std::cout << "numArgs: [" << numArgs << "]" << std::endl;
        std::vector<std::variant<int, float, std::string, bool>> arguments;

        for (size_t i = 0; i < numArgs; i++) {
            // std::size_t type = static_cast<std::size_t>(packet.getPayload()[index++]);
            int type = (packet.getPayload()[index] << 24) | (packet.getPayload()[index + 1] << 16) | (packet.getPayload()[index + 2] << 8) | packet.getPayload()[index + 3];
            index += 4;
            std::cout << "type: [" << type << "]" << std::endl;

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
