/*
** EPITECH PROJECT, 2024
** PlayerUpdatePositionSystem
** File description:
** PlayerUpdatePositionSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"
/**
 * @brief System to update the position of a player.
 *
 */
class PlayerUpdatePositionSystem : public ASystem {

    public:

        /**
         * @brief Construct a new PlayerUpdatePosition System object.
         *
         */
        PlayerUpdatePositionSystem();

        /**
         * @brief Destroy the PlayerUpdatePosition System object.
         *
         */
        ~PlayerUpdatePositionSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _updatePlayerPosition(reg, idxPacketEntities);
            };
        }

    private:

        void _updatePlayerPosition(ECS::Registry& reg, int idxPacketEntities); //< Function to update the player's position.
};
