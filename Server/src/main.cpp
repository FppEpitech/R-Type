/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** main
*/

#include <iostream>
#include <thread>
#include "network/network.hpp"

void handle_message(const std::string& message, const asio::ip::udp::endpoint& endpoint)
{
    std::cout << "Messages received from " << endpoint << ": " << message << std::endl;
}

int main() {
    try {
        asio::io_context io_context;

        Network::Server server(io_context, 4444, 4445);

        std::cout << "Server running on TCP port 4444 and UDP port 4445..." << std::endl;

        server.setMessageHandler(handle_message);
        server.start();

        std::thread server_thread([&io_context]() { io_context.run(); });

        server_thread.join();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
