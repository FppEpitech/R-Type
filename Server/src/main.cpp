/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** main
*/

#include <iostream>

#include "Network/Server/NetworkServer.hpp"

void handle_message_server(Network::UDPPacket packet, const asio::ip::udp::endpoint& endpoint)
{
    std::cout << "Messages received from " << endpoint << ": [" << "..." << "]" << std::endl;
}

int main()
{
    try {
        Network::Server server(4444, 4445);
        server.start(handle_message_server);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
