/*
** EPITECH PROJECT, 2024
** MobSpeTwoInitSystem
** File description:
** MobSpeTwoInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a mob entity.
 *
 */
class MobSpeTwoInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Mob Init System object.
         *
         */
        MobSpeTwoInitSystem();

        /**
         * @brief Destroy the Mob Init System object.
         *
         */
        ~MobSpeTwoInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initMob(reg, idxPacketEntities);
            };
        }

    private:

        void _initMob(ECS::Registry& reg, int idxPacketEntities); //< Function to init the Mob.
};
