/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIClient
*/

#include "ABINetwork.hpp"
#include "Client.hpp"

namespace ABINetwork
{

std::shared_ptr<INetworkUnit> createClient(std::string ipServer, int tcp_port, int udp_port)
{
    return std::make_shared<Client>(ipServer, tcp_port, udp_port);
}

}
