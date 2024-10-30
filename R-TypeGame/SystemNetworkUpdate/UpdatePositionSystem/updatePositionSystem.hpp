/*
** EPITECH PROJECT, 2024
** UpdatePositionComponent
** File description:
** UpdatePositionComponent
*/

#pragma once

#include <iostream>

#include "ISystemNetworkUpdate.hpp"

/**
 * @brief Update position system.
 *
 */
class UpdatePositionComponent : public ISystemNetworkUpdate {

    public:

        /**
         * @brief Construct a new UpdatePositionComponent System object.
         *
         */
        UpdatePositionComponent() = default;

        /**
         * @brief Destroy the UpdatePositionComponent System object.
         *
         */
        ~UpdatePositionComponent() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ABINetwork::UDPPacket, ECS::Registry&)> getFunction()
        {
            return [this](ABINetwork::UDPPacket packet, ECS::Registry& reg) {
                _updatePosition(packet, reg);
            };
        }

    private:

        void _updatePosition(ABINetwork::UDPPacket packet, ECS::Registry& reg); //The system to update position.
};
