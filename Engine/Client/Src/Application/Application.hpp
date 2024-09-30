/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#pragma once

#include <iostream>

#include "Registry.hpp"
#include "NetworkClient.hpp"

/**
 * @brief Application class
 * It's the main class of the client application
 */
class Application {

    public:

        /**
         * @brief Construct a new Application object
         *
         */
        Application();

        /**
         * @brief Destroy the Application object
         *
         */
        ~Application() = default;

        /**
         * @brief Run the application
         *
         */
        void run();

    private:

        /**
         * @brief Callback function who handle the packet receive.
         *
         * @param packet Packet receive by the server
         */
        void _packetHandler(Network::UDPPacket packet);

        std::shared_ptr<std::vector<ECS::Registry>> _registries; // Registries for each scene.
        std::shared_ptr<Network::Client>            _client;     // Network class for client.
};