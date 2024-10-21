/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootDamageSystem.hpp
*/

#pragma once

#include <iostream>

#include "../../../Engine/Shared/DefaultSystems/ISystem.hpp"

/**
 * @brief Destroy a shot if the bullet leave the screen.
 *
 */
class ShootDamageSystem : public ASystem {

    public:

        /**
         * @brief Construct a new ShootDestroy System object.
         *
         */
        ShootDamageSystem();

        /**
         * @brief Destroy the ShootDestroy System object.
         *
         */
        ~ShootDamageSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _shootDamage(reg, idxPacketEntities);
            };
        }

    private:

        void _shootDamage(ECS::Registry& reg, int idxPacketEntities); //< Function to destroy shoot.
};
