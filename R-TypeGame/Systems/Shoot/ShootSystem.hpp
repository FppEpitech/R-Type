/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#pragma once

#include <iostream>

#define POS_PLAYER_X 155
#define POS_PLAYER_Y 50

#include "../../../Engine/Shared/DefaultSystems/ISystem.hpp"

/**
 * @brief Shoot a bullet by a player.
 *
 */
class ShootSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Shoot System object.
         *
         */
        ShootSystem();

        /**
         * @brief Destroy the Shoot System object.
         *
         */
        ~ShootSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _shoot(reg, idxPacketEntities);
            };
        }

    private:

        void _shoot(ECS::Registry& reg, int idxPacketEntities); //< Function to shoot.
};
