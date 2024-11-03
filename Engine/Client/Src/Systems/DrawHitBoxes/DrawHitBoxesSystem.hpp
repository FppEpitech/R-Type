/*
** EPITECH PROJECT, 2024
** DrawHitBoxesSystem
** File description:
** DrawHitBoxesSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief System to draw an HitBoxes Model.
 *
 */
class DrawHitBoxesSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Draw HitBoxes System object.
         *
         */
        DrawHitBoxesSystem();

        /**
         * @brief Destroy the Draw HitBoxes System object.
         *
         */
        ~DrawHitBoxesSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _drawHitBoxes(reg, idxPacketEntities);
            };
        }

    private:

        void _drawHitBoxes(ECS::Registry& reg, int idxPacketEntities); //< Function to init the player.
};
