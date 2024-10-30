/*
** EPITECH PROJECT, 2024
** UpdatePlayerConnectionSystem
** File description:
** UpdatePlayerConnectionSystem
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <tuple>

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
        std::function<void(ABINetwork::UDPPacket, ECS::Registry&)> getFunction()
        {
            return [this](ABINetwork::UDPPacket packet, ECS::Registry& reg) {
                _updatePlayerConnection(packet, reg);
            };
        }

    private:

        void _updatePlayerConnection(ABINetwork::UDPPacket packet, ECS::Registry& reg); //The system to update player connection.
};
