/*
** EPITECH PROJECT, 2024
** BackgroundSystem
** File description:
** BackgroundSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a background entity.
 *
 */
class BackgroundSystem : public ASystem {

    public:

        /**
         * @brief Construct a new background Init System object.
         *
         */
        BackgroundSystem();

        /**
         * @brief Destroy the background Init System object.
         *
         */
        ~BackgroundSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initBackground(reg, idxPacketEntities);
            };
        }

    private:

        void _initBackground(ECS::Registry& reg, int idxPacketEntities); //< Function to init the background.
};
