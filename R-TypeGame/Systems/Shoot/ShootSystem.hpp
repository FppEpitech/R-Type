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

#include <chrono>

#include "ISystem.hpp"
#include "../../Network/ABI/ABIServer.hpp"

#define SHOOT_CREATE 1

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
        std::chrono::steady_clock::time_point lastShootTime = std::chrono::steady_clock::now() - std::chrono::milliseconds(500); // Chrono of shoot system (to know when shoot)
};
