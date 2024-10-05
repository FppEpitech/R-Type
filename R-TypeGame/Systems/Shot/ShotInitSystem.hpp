/*
** EPITECH PROJECT, 2024
** ShotInitSystem
** File description:
** ShotInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a shot entity.
 *
 */
class ShotInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Shot Init System object.
         *
         */
        ShotInitSystem();

        /**
         * @brief Destroy the Shot Init System object.
         *
         */
        ~ShotInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initShot(reg, idxPacketEntities);
            };
        }

    private:

        void _initShot(ECS::Registry& reg, int idxPacketEntities); //< Function to init the Shot.
};
