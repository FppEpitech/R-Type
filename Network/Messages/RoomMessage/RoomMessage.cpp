/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** RoomMessage
*/

#include "RoomMessage/RoomMessage.hpp"

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
    _payload.clear();

    uint32_t roomNameLength = roomName.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomNameLength), reinterpret_cast<uint8_t*>(&roomNameLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), roomName.begin(), roomName.end());

    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&privateRoom), reinterpret_cast<uint8_t*>(&privateRoom) + sizeof(bool));

    uint32_t roomPasswordLength = roomPassword.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomPasswordLength), reinterpret_cast<uint8_t*>(&roomPasswordLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), roomPassword.begin(), roomPassword.end());

    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&cheatsRoom), reinterpret_cast<uint8_t*>(&cheatsRoom) + sizeof(bool));

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

Payload &RoomMessage::createCreatedRoomPayload(roomInfo_t infos)
{
    _payload.clear();

    uint32_t roomNameLength = infos.name.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomNameLength), reinterpret_cast<uint8_t*>(&roomNameLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), infos.name.begin(), infos.name.end());

    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&infos.tcpPort), reinterpret_cast<uint8_t*>(&infos.tcpPort) + sizeof(int));

    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&infos.udpPort), reinterpret_cast<uint8_t*>(&infos.udpPort) + sizeof(int));

    return _payload;
}

Payload &RoomMessage::createJoinRoomPayload(std::string roomName, std::string password)
{
    _payload.clear();

    uint32_t roomNameLength = roomName.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomNameLength), reinterpret_cast<uint8_t*>(&roomNameLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), roomName.begin(), roomName.end());

    uint32_t passwordLength = password.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&passwordLength), reinterpret_cast<uint8_t*>(&passwordLength) + sizeof(uint32_t));
    _payload.insert(_payload.end(), password.begin(), password.end());

    return _payload;
}

Payload &RoomMessage::createLeaveRoomPayload()
{
    _payload.clear();
    return _payload;
}

std::tuple<std::string, int, int> RoomMessage::getCreatedRoomInfoFromPacket(UDPPacket packet)
{
    size_t offset = 0;

    uint32_t roomNameLength;
    std::memcpy(&roomNameLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string roomName;
    roomName.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), roomNameLength);
    offset += roomNameLength;

    int tcpPort;
    std::memcpy(&tcpPort, &packet.getPayload()[offset], sizeof(int));
    offset += sizeof(int);

    int udpPort;
    std::memcpy(&udpPort, &packet.getPayload()[offset], sizeof(int));
    offset += sizeof(int);

    return {roomName, tcpPort, udpPort};
}

std::pair<std::string, std::string> RoomMessage::getJoinRoomInfoFromPacket(UDPPacket packet)
{
    size_t offset = 0;

    uint32_t roomNameLength;
    std::memcpy(&roomNameLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string roomName;
    roomName.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), roomNameLength);
    offset += roomNameLength;

    uint32_t roomPasswordLength;
    std::memcpy(&roomPasswordLength, &packet.getPayload()[offset], sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::string roomPassword;
    roomPassword.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), roomPasswordLength);
    offset += roomPasswordLength;

    return {roomName, roomPassword};
}

Payload &RoomMessage::createWrongRoomPasswordPayload()
{
    _payload.clear();
    return _payload;
}

Payload &RoomMessage::createFullRoomPayload()
{
    _payload.clear();
    return _payload;
}

Payload &RoomMessage::createAllowedToJoinRoomPayload()
{
    _payload.clear();
    return _payload;
}

}
