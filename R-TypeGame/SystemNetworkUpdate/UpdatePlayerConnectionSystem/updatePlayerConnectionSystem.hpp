/*
** EPITECH PROJECT, 2024
** UpdatePlayerConnectionSystem
** File description:
** UpdatePlayerConnectionSystem
*/

#pragma once

#include <iostream>

#include "ISystemNetworkUpdate.hpp"

/**
 * @brief Update player connection system.
 *
 */
class UpdatePlayerConnectionSystem : public ISystemNetworkUpdate {

    public:

        /**
         * @brief Construct a new UpdatePlayerConnectionSystem System object.
         *
         */
        UpdatePlayerConnectionSystem() = default;

        /**
         * @brief Destroy the UpdatePlayerConnectionSystem System object.
         *
         */
        ~UpdatePlayerConnectionSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(Network::UDPPacket, ECS::Registry&)> getFunction()
        {
            return [this](Network::UDPPacket packet, ECS::Registry& reg) {
                _updatePlayerConnection(packet, reg);
            };
        }

    private:

        void _updatePlayerConnection(Network::UDPPacket packet, ECS::Registry& reg); //The system to update player connection.
};
