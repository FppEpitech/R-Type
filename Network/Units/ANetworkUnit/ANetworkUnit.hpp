/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ANetworkUnit
*/

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
         * @brief Destructor.
         *
         * Default destructor for `ANetworkUnit`, which is automatically called when
         * an object of this class is destroyed.
         */
        ~ANetworkUnit() = default;
};

}
