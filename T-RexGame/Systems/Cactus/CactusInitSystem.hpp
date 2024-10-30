/*
** EPITECH PROJECT, 2024
** CactusInitSystem
** File description:
** CactusInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a cactus entity.
 *
 */
class CactusInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new cactus Init System object.
         *
         */
        CactusInitSystem();

        /**
         * @brief Destroy the cactus Init System object.
         *
         */
        ~CactusInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initCactus(reg, idxPacketEntities);
            };
        }

    private:

        void _initCactus(ECS::Registry& reg, int idxPacketEntities); //< Function to init the cactus.
};
