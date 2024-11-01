/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
*/

#include "Auth/Auth.hpp"
#include "InitMessage/InitMessage.hpp"
#include "AssignToken/AssignToken.hpp"
#include "KeyPressed/KeyPressed.hpp"
#include "ChatBox/ChatBox.hpp"
#include "CreateEntity/CreateEntity.hpp"
#include "UpdateComponent/UpdateComponent.hpp"
#include "ABIError.hpp"
#include "Server.hpp"
#include "ABINetwork.hpp"
#include "RoomMessage/RoomMessage.hpp"

namespace ABINetwork
{

std::pair<std::string, std::string> getLoginInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return {"", ""};
    return message->getLoginInfoFromPacket(packet);
}

std::pair<std::string, std::string> getRegisterInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return {"", ""};
    return message->getRegisterInfoFromPacket(packet);
}

uint32_t getLogoutInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return 0;
    return message->getLogoutInfoFromPacket(packet);
}

std::shared_ptr<INetworkUnit> createServer(std::size_t numberMaxPlayer)
{
    return std::make_shared<Server>(numberMaxPlayer);
}

int getInitInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<InitMessage> message = std::make_shared<InitMessage>();

    if (!message)
        return 0;
    return message->getInitInfoFromPacket(packet);
}

int getKeyPressedInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<KeyPressedMessage> message = std::make_shared<KeyPressedMessage>();

    if (!message)
        return 0;
    return message->getKeyPressedInfoFromPacket(packet);
}

std::pair<std::string, std::string> getChatBoxInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<ChatBoxMessage> message = std::make_shared<ChatBoxMessage>();

    if (!message)
        return {"", ""};
    return message->getChatBoxInfoFromPacket(packet);
}

void sendPacketCreateEntity(std::shared_ptr<INetworkUnit> networkUnit, std::string componentType, int idxEntity)
{
    std::shared_ptr<CreateEntityMessage> message = std::make_shared<CreateEntityMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::CREATE_ENTITY),
                                    message->createEntityPayload(componentType, idxEntity),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()));
}

void sendUpdateComponent(std::shared_ptr<INetworkUnit> networkUnit, std::string componentType, int nbArgs,
std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args)
{
    std::shared_ptr<UpdateComponentMessage> message = std::make_shared<UpdateComponentMessage>();

    if (!message)
        return;

    Payload payload = message->createUpdateComponentPayload(componentType, nbArgs, args);

    std::vector<uint8_t> packet = message->_createPacket(uint8_t(IMessage::MessageType::UPDATE_COMPONENT),
                                    payload,
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken());

    setMessageInQueue(networkUnit, packet);
}

roomInfo_t getCreateRoomInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();
    if (!message)
        return {};
    return message->getCreateRoomInfoFromPacket(packet);
}

void sendPacketRoomCreated(std::shared_ptr<INetworkUnit> networkUnit, roomInfo_t infos, uint32_t token)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::CREATE_ROOM),
                                    message->createCreatedRoomPayload(infos),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

void sendPacketAssignToken(std::shared_ptr<INetworkUnit> networkUnit, int idxEntity, uint32_t token)
{
    std::shared_ptr<AssignTokenMessage> message = std::make_shared<AssignTokenMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::ASSIGNTOKEN),
                                    message->createAssignTokenPayload(idxEntity),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

std::pair<std::string, std::string> getJoinRoomInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return {"", ""};
    return message->getJoinRoomInfoFromPacket(packet);
}

void sendPacketWrongRoomPassword(std::shared_ptr<INetworkUnit> networkUnit, uint32_t token)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::WRONG_ROOM_PASSWORD),
                                    message->createWrongRoomPasswordPayload(),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

void sendPacketFullRoom(std::shared_ptr<INetworkUnit> networkUnit, uint32_t token)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::FULL_ROOM),
                                    message->createFullRoomPayload(),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

void sendPacketAllowedToJoinRoom(std::shared_ptr<INetworkUnit> networkUnit, int tcpPort, uint32_t token)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::JOIN_ROOM),
                                    message->createAllowedToJoinRoomPayload(tcpPort),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

void sendPacketRooms(std::shared_ptr<INetworkUnit> networkUnit, std::vector<ABINetwork::roomInfo_t> rooms, uint32_t token)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::GET_ROOM),
                                    message->createRoomsPayload(rooms),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

void sendPacketLoginAllowed(std::shared_ptr<INetworkUnit> networkUnit, bool isAllowed, uint32_t token)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::LOGIN),
                                    message->createAllowedLoginPayload(isAllowed),
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()), token);
}

std::vector<std::pair<uint32_t, bool>>& getQueueConnection(std::shared_ptr<INetworkUnit> networkUnit)
{
    static std::vector<std::pair<uint32_t, bool>> emptyQueue;
    std::shared_ptr<Server> server = std::dynamic_pointer_cast<Server>(networkUnit);
    if (!server)
        return emptyQueue;
    return server->getqueueConnection();
}

}
