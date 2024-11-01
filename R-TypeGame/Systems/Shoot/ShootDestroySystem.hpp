/*
** EPITECH PROJECT, 2024
** ShootDestroySystem
** File description:
** ShootDestroySystem
*/

#pragma once

#include <iostream>

#define POS_PLAYER_X 155
#define POS_PLAYER_Y 50

#include "ISystem.hpp"
#include "../../Network/ABI/ABIServer.hpp"

/**
 * @brief Destroy a shot if the bullet leave the screen.
 *
 */
class ShootDestroySystem : public ASystem {

    public:

        #define SHOOT_DESTROY 2

        /**
         * @brief Construct a new ShootDestroy System object.
         *
         */
        ShootDestroySystem();

        /**
         * @brief Destroy the ShootDestroy System object.
         *
         */
        ~ShootDestroySystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _shootDestroy(reg, idxPacketEntities);
            };
        }

    private:

        void _shootDestroy(ECS::Registry& reg, int idxPacketEntities); //< Function to destroy shoot.
};
