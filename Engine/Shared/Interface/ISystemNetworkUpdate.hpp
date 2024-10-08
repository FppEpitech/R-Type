/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** ISystemNetworkUpdate
*/

#pragma once

#include <string>
#include <functional>

#include "../Ecs/Src/Registry.hpp"
#include "../Network/Packet/NetworkPacket.hpp"

/**
 * @brief Interface class for network update systems.
 *
 */
class ISystemNetworkUpdate {

    public:

        /**
         * @brief Destroy the ISystemNetworkUpdate object.
         *
         */
        virtual ~ISystemNetworkUpdate() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(Network::UDPPacket packet, ECS::Registry& reg)>
         */
        virtual std::function<void(Network::UDPPacket packet, ECS::Registry& reg)> getFunction() = 0;
};
