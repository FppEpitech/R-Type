/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIClient
*/

#include "ABINetwork.hpp"
#include "Client.hpp"
#include "Auth/Auth.hpp"

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

}
