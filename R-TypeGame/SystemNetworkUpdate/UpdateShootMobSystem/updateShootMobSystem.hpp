/*
** EPITECH PROJECT, 2024
** UpdateShootSystem
** File description:
** UpdateShootMobSystem
*/

#pragma once

#include <iostream>

#include "ISystemNetworkUpdate.hpp"

/**
 * @brief Update shoot system.
 *
 */
class UpdateShootMobSystem : public ISystemNetworkUpdate {

    public:

        /**
         * @brief Construct a new UpdateShootMobSystem System object.
         *
         */
        UpdateShootMobSystem() = default;

        /**
         * @brief Destroy the UpdateShootMobSystem System object.
         *
         */
        ~UpdateShootMobSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ABINetwork::UDPPacket, ECS::Registry&)> getFunction()
        {
            return [this](ABINetwork::UDPPacket packet, ECS::Registry& reg) {
                _updateShootMobSystem(packet, reg);
            };
        }

    private:

        void _updateShootMobSystem(ABINetwork::UDPPacket packet, ECS::Registry& reg); //The system to update shoot.
};
