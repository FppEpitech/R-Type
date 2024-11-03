/*
** EPITECH PROJECT, 2024
** GroundInitSystem
** File description:
** GroundInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a ground entity.
 *
 */
class GroundInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Ground Init System object.
         *
         */
        GroundInitSystem();

        /**
         * @brief Destroy the Ground Init System object.
         *
         */
        ~GroundInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initGround(reg, idxPacketEntities);
            };
        }

    private:

        void _initGround(ECS::Registry& reg, int idxPacketEntities); //< Function to init the player.
};
