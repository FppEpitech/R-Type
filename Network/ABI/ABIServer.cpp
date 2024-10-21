/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIServer
*/

#include "Server.hpp"
#include "ABINetwork.hpp"

namespace ABINetwork
{
    std::shared_ptr<INetworkUnit> createServer(std::size_t numberMaxPlayer)
    {
        return std::make_shared<Server>(numberMaxPlayer);
    }
}
