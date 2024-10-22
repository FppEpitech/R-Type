/*
** EPITECH PROJECT, 2024
** DrawOBJSystem
** File description:
** DrawOBJSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief System to draw an OBJ Model.
 *
 */
class DrawOBJSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Draw OBJ System object.
         *
         */
        DrawOBJSystem();

        /**
         * @brief Destroy the Draw OBJ System object.
         *
         */
        ~DrawOBJSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _drawOBJ(reg, idxPacketEntities);
            };
        }

    private:

        void _drawOBJ(ECS::Registry& reg, int idxPacketEntities); //< Function to init the player.
};
