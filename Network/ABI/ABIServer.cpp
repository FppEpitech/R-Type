/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
*/

// #include "ABINetwork.hpp"
#include "Auth/Auth.hpp"
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

}
