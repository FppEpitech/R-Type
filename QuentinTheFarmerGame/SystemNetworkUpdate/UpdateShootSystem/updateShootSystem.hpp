/*
** EPITECH PROJECT, 2024
** UpdateShootSystem
** File description:
** UpdateShootSystem
*/

#pragma once

#include <iostream>

#include "ISystemNetworkUpdate.hpp"

/**
 * @brief Update shoot system.
 *
 */
class UpdateShootSystem : public ISystemNetworkUpdate {

    public:

        /**
         * @brief Construct a new UpdateShootSystem System object.
         *
         */
        UpdateShootSystem() = default;

        /**
         * @brief Destroy the UpdateShootSystem System object.
         *
         */
        ~UpdateShootSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ABINetwork::UDPPacket, ECS::Registry&)> getFunction()
        {
            return [this](ABINetwork::UDPPacket packet, ECS::Registry& reg) {
                _updateShootSystem(packet, reg);
            };
        }

    private:

        void _updateShootSystem(ABINetwork::UDPPacket packet, ECS::Registry& reg); //The system to update shoot.
};
