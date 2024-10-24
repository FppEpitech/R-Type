/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** RoomMessage
*/

#include "Room/Room.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

Payload & RoomMessage::createGetRoomPayload()
{
    _payload.clear();

    return _payload;
}

Payload &RoomMessage::createCreateRoomPayload(std::string roomName, bool privateRoom, std::string roomPassword, bool cheatsRoom, int playerMaxRoom)
{
    // _payload.clear();

    // uint8_t* NameBytes = reinterpret_cast<uint8_t*>(&roomName);
    // _payload.insert(_payload.end(), NameBytes, NameBytes + sizeof(std::string));

    // uint8_t* privateBytes = reinterpret_cast<uint8_t*>(&privateRoom);
    // _payload.insert(_payload.end(), privateBytes, privateBytes + sizeof(bool));

    // uint8_t* passwordBytes = reinterpret_cast<uint8_t*>(&roomPassword);
    // _payload.insert(_payload.end(), passwordBytes, passwordBytes + sizeof(std::string));

    // uint8_t* cheatsBytes = reinterpret_cast<uint8_t*>(&cheatsRoom);
    // _payload.insert(_payload.end(), cheatsBytes, cheatsBytes + sizeof(bool));

    // uint8_t* playerMaxBytes = reinterpret_cast<uint8_t*>(&playerMaxRoom);
    // _payload.insert(_payload.end(), playerMaxBytes, playerMaxBytes + sizeof(int));

    // return _payload;

    _payload.clear();

    // Serialize room name: first the size, then the actual characters
    uint32_t roomNameLength = roomName.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomNameLength), reinterpret_cast<uint8_t*>(&roomNameLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), roomName.begin(), roomName.end());

    // Serialize privateRoom (bool)
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&privateRoom), reinterpret_cast<uint8_t*>(&privateRoom) + sizeof(bool));

    // Serialize room password: first the size, then the actual characters
    uint32_t roomPasswordLength = roomPassword.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomPasswordLength), reinterpret_cast<uint8_t*>(&roomPasswordLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), roomPassword.begin(), roomPassword.end());

    // Serialize cheatsRoom (bool)
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&cheatsRoom), reinterpret_cast<uint8_t*>(&cheatsRoom) + sizeof(bool));

    // Serialize playerMaxRoom (int)
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&playerMaxRoom), reinterpret_cast<uint8_t*>(&playerMaxRoom) + sizeof(int));

    return _payload;
}

roomInfo_t RoomMessage::getCreateRoomInfoFromPacket(UDPPacket packet)
{
    size_t offset = 0;

    uint32_t roomNameLength;
    std::memcpy(&roomNameLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string roomName;
    roomName.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), roomNameLength);
    offset += roomNameLength;

    bool privateRoom;
    std::memcpy(&privateRoom, &packet.getPayload()[offset], sizeof(bool));
    offset += sizeof(bool);

    uint32_t roomPasswordLength;
    std::memcpy(&roomPasswordLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string roomPassword;
    roomPassword.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), roomPasswordLength);
    offset += roomPasswordLength;

    bool cheatsRoom;
    std::memcpy(&cheatsRoom, &packet.getPayload()[offset], sizeof(bool));
    offset += sizeof(bool);

    int playerMaxRoom;
    std::memcpy(&playerMaxRoom, &packet.getPayload()[offset], sizeof(int));
    offset += sizeof(int);

    roomInfo_t infos = {roomName, privateRoom, roomPassword, cheatsRoom, playerMaxRoom};

    return infos;
}

}
