/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
*/

#include "Auth/Auth.hpp"
#include "KeyPressed/KeyPressed.hpp"
#include "ChatBox/ChatBox.hpp"
#include "ABIError.hpp"
#include "Server.hpp"

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

}
