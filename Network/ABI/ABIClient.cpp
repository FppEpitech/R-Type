/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIClient
*/

#include "ABINetwork.hpp"
#include "Client.hpp"
#include "Auth/Auth.hpp"
#include "KeyPressed/KeyPressed.hpp"
#include "CreateEntity/CreateEntity.hpp"
#include "ChatBox/ChatBox.hpp"

namespace ABINetwork
{

std::shared_ptr<INetworkUnit> createClient(std::string ipServer, int tcp_port, int udp_port)
{
    return std::make_shared<Client>(ipServer, tcp_port, udp_port);
}

void sendPacketLogin(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string password)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::LOGIN), message->createLoginPayload(userName, password), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketRegister(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string password)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::REGISTER), message->createRegisterPayload(userName, password), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketLogout(std::shared_ptr<INetworkUnit> networkUnit)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::LOGOUT), message->createLogoutPayload(), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketKey(std::shared_ptr<INetworkUnit> networkUnit, int key)
{
    std::shared_ptr<KeyPressedMessage> message = std::make_shared<KeyPressedMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::KEY), message->createKeyPressedPayload(key), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketChatbox(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string chat)
{
    std::shared_ptr<ChatBoxMessage> message = std::make_shared<ChatBoxMessage>();

    if (!message)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::CHAT_BOX_MESSAGE), message->createChatBoxPayload(userName, chat), networkUnit->getIdMessage(), networkUnit->getToken()));
}

std::tuple<std::string, float, float> getEntityCreationInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<CreateEntityMessage> message = std::make_shared<CreateEntityMessage>();

    if (!message)
        throw ABIError("Failed to create CreateEntityMessage class");
    return message->getEntityPayload(packet);
}

}
