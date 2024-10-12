/*
** EPITECH PROJECT, 2024
** NetworkConnectionComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class NetworkConnectionComponent
 * @brief Component for handling the connection to the server.
 *
 */
class NetworkConnectionComponent : public AComponent {

    public:

        bool connect; //< The status of connection.
        std::string serverIp; //< The IP of Server.
        std::string serverPort; //< The Port of Server.

        /**
         * @brief Construct a new NetworkConnectionComponent object
         *
         * @param press Initial status of button.
         */
        NetworkConnectionComponent(bool connect = false, std::string serverIp = "", std::string serverPort = "");
};
