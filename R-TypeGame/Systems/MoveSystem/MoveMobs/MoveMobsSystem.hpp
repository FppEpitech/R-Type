/*
** EPITECH PROJECT, 2024
** MoveMobsSystem
** File description:
** MoveMobsSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"
/**
 * @brief Move all mobs based on their positions and velocity.
 *
 */
class MoveMobsSystem : public ASystem {

    public:

        /**
         * @brief Construct a new MoveMobs System object.
         *
         */
        MoveMobsSystem();

        /**
         * @brief Destroy the MoveMobs System object.
         *
         */
        ~MoveMobsSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketMobs)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketMobs)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketMobs) {
                _moveMobs(reg, idxPacketMobs);
            };
        }

    private:

        void _moveMobs(ECS::Registry& reg, int idxPacketMobs); //< Function to Move Mobs.
};
