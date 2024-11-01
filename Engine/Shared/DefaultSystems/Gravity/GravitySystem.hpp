/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GravitySystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle gravity.
 */
class GravitySystem : public ASystem {

    public:

        /**
         * @brief Construct a new Gravity System object.
         *
         */
        GravitySystem();

        /**
         * @brief Destroy the Gravity System object.
         *
         */
        ~GravitySystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleGravity(reg, idxPacketEntities);
            };
        }

    private:

        void _handleGravity(ECS::Registry& reg, int idxPacketEntities); //< Function to handle mouse events.
};
