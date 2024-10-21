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

std::pair<std::string, std::string> getLoginInfoFromPacket()
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        throw ABIError("Failed to create AuthMessage class");
    return message->getLoginInfoFromPacket();
}

std::pair<std::string, std::string> getRegisterInfoFromPacket()
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        throw ABIError("Failed to create AuthMessage class");
    return message->getRegisterInfoFromPacket();
}

uint32_t getLogoutInfoFromPacket()
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        throw ABIError("Failed to create AuthMessage class");
    return message->getLogoutInfoFromPacket();
}

std::shared_ptr<INetworkUnit> createServer(std::size_t numberMaxPlayer)
{
    return std::make_shared<Server>(numberMaxPlayer);
}

}
