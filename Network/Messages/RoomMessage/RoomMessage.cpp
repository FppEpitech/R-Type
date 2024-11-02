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
    if (roomPasswordLength == 0)
        return {roomName, ""};
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

Payload &RoomMessage::createAllowedToJoinRoomPayload(int tcpPort)
{
    _payload.clear();

    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&tcpPort), reinterpret_cast<uint8_t*>(&tcpPort) + sizeof(int));

    return _payload;
}

Payload &RoomMessage::createRoomsPayload(std::vector<ABINetwork::roomInfo_t> rooms)
{
    _payload.clear();

    int nbRooms = rooms.size();
    _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&nbRooms), reinterpret_cast<uint8_t*>(&nbRooms) + sizeof(int));

    for (auto room : rooms) {

        uint32_t roomNameLength = room.name.size();
        _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&roomNameLength), reinterpret_cast<uint8_t*>(&roomNameLength) + sizeof(uint32_t));
        _payload.insert(_payload.end(), room.name.begin(), room.name.end());

        bool isPrivate = room.isPrivate;
        _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&isPrivate), reinterpret_cast<uint8_t*>(&isPrivate) + sizeof(bool));;

        int playerMax = room.playerMax;
        _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&playerMax), reinterpret_cast<uint8_t*>(&playerMax) + sizeof(int));

        int nbPlayers = room.nbPlayers;
        _payload.insert(_payload.end(), reinterpret_cast<uint8_t*>(&nbPlayers), reinterpret_cast<uint8_t*>(&nbPlayers) + sizeof(int));
    }
    return _payload;
}

std::vector<ABINetwork::roomInfo_t> RoomMessage::getRoomsInfoFromPacket(UDPPacket packet)
{
    std::vector<ABINetwork::roomInfo_t> infos;

    size_t offset = 0;

    int nbRooms;
    std::memcpy(&nbRooms, &packet.getPayload()[offset], sizeof(int));
    offset += sizeof(int);

    for (int i = 0; i < nbRooms; i++) {

        ABINetwork::roomInfo_t room;

        uint32_t roomNameLength;
        std::memcpy(&roomNameLength, &packet.getPayload()[offset], sizeof(uint32_t));
        offset += sizeof(uint32_t);
        room.name.assign(reinterpret_cast<const char*>(&packet.getPayload()[offset]), roomNameLength);
        offset += roomNameLength;

        std::memcpy(&room.isPrivate, &packet.getPayload()[offset], sizeof(bool));
        offset += sizeof(bool);

        std::memcpy(&room.playerMax, &packet.getPayload()[offset], sizeof(int));
        offset += sizeof(int);

        std::memcpy(&room.nbPlayers, &packet.getPayload()[offset], sizeof(int));
        offset += sizeof(int);

        infos.push_back(room);
    }

    return infos;
}

int RoomMessage::getAllowedJoinRoomInfoFromPacket(UDPPacket packet)
{
    int tcpPort;
    std::memcpy(&tcpPort, &packet.getPayload()[0], sizeof(int));
    return tcpPort;
}

}
