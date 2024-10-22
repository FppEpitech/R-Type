/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ANetworkUnit
*/

#pragma once

#include "INetworkUnit.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

/**
 * @class ANetworkUnit
 * @brief Abstract base class for network units.
 *
 * This class inherits from `INetworkUnit` and can be used as a base for network entities
 * like clients and servers. It provides a common structure for derived classes.
 */
class ANetworkUnit : public INetworkUnit
{
    public:

        /**
         * @brief Construct a new ANetworkUnit object.
         *
         */
        ANetworkUnit();

        /**
         * @brief Destructor.
         *
         * Default destructor for `ANetworkUnit`, which is automatically called when
         * an object of this class is destroyed.
         */
        ~ANetworkUnit() = default;

        /**
         * @brief Get the Token object.
         *
         * @return uint32_t
         */
        uint32_t getToken();

        /**
         * @brief Get the Id Message object.
         *
         * @return uint32_t
         */
        uint32_t &getIdMessage();

    protected:

        uint32_t        _token;             // Token of client (used to be identify on server)
        uint32_t        _messageId;         // Current Message ID (auto-incremente every send of message)
};

}
