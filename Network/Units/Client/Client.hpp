/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Client
*/

#include "ANetworkUnit.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

/**
 * @class Client
 * @brief Represents a client in the network.
 *
 * This class inherits from `ANetworkUnit` and represents a client in the network architecture.
 */
class Client : public ANetworkUnit
{

    public:

        /**
         * @brief Destructor.
         *
         * Default destructor for `Client`, which is automatically called when an object
         * of this class is destroyed.
         */
        ~Client() = default;
};

}
