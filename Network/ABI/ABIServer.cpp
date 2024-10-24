/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
*/

#include "Auth/Auth.hpp"
#include "KeyPressed/KeyPressed.hpp"
#include "ChatBox/ChatBox.hpp"
#include "CreateEntity/CreateEntity.hpp"
#include "UpdateComponent/UpdateComponent.hpp"
#include "ABIError.hpp"
#include "Server.hpp"
#include "ABINetwork.hpp"
#include "Room/Room.hpp"

namespace ABINetwork
{

std::pair<std::string, std::string> getLoginInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        throw ABIError("Failed to create AuthMessage class");
    return message->getLoginInfoFromPacket(packet);
}

std::pair<std::string, std::string> getRegisterInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        throw ABIError("Failed to create AuthMessage class");
    return message->getRegisterInfoFromPacket(packet);
}

uint32_t getLogoutInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        throw ABIError("Failed to create AuthMessage class");
    return message->getLogoutInfoFromPacket(packet);
}

std::shared_ptr<INetworkUnit> createServer(std::size_t numberMaxPlayer)
{
    return std::make_shared<Server>(numberMaxPlayer);
}

int getKeyPressedInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<KeyPressedMessage> message = std::make_shared<KeyPressedMessage>();

    if (!message)
        throw ABIError("Failed to create KeyPressedMessage class");
    return message->getKeyPressedInfoFromPacket(packet);
}

std::pair<std::string, std::string> getChatBoxInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<ChatBoxMessage> message = std::make_shared<ChatBoxMessage>();

    if (!message)
        throw ABIError("Failed to create ChatBoxMessage class");
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

void sendUpdateComponent(std::shared_ptr<INetworkUnit> networkUnit, std::string componentType, int nbArgs, ...)
{
    std::shared_ptr<UpdateComponentMessage> message = std::make_shared<UpdateComponentMessage>();

    if (!message)
        return;

    va_list args;
    va_start(args, nbArgs);

    Payload payload = message->createUpdateComponentPayload(componentType, nbArgs, args);

    va_end(args);

    setMessageInQueue(networkUnit,  message->_createPacket(uint8_t(IMessage::MessageType::UPDATE_COMPONENT),
                                    payload,
                                    networkUnit->getIdMessage(),
                                    networkUnit->getToken()));
}

roomInfo_t getCreateRoomInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        throw ABIError("Failed to create RoomMessage class");
    return message->getCreateRoomInfoFromPacket(packet);
}

}
