/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Server
*/

#pragma once

#include "ANetworkUnit.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

/**
 * @class Server
 * @brief Represents a server in the network.
 *
 * This class inherits from `ANetworkUnit` and represents a server in the network architecture.
 */
class Server : public ANetworkUnit
{

    public:

        /**
         * @brief Destructor.
         *
         * Default destructor for `Server`, which is automatically called when an object
         * of this class is destroyed.
         */
        ~Server() = default;
};

}
