/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** main
*/

#include <iostream>

#include "Network/Client/NetworkClient.hpp"

void handle_message_client(std::string message)
{
    std::cout << "Messages received from server: [" << message << "]" << std::endl;
}

int main()
{
    try {
        Network::Client client("127.0.0.1", 4444, 4445);
        client.connect(handle_message_client);
        // Loop Game
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

