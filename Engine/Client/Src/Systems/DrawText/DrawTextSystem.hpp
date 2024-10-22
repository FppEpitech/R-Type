/*
** EPITECH PROJECT, 2024
** DrawTextSystem
** File description:
** DrawTextSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief System to draw a Text.
 *
 */
class DrawTextSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Draw Text System object.
         *
         */
        DrawTextSystem();

        /**
         * @brief Destroy the Draw Text System object.
         *
         */
        ~DrawTextSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _drawText(reg, idxPacketEntities);
            };
        }

    private:

        void _drawText(ECS::Registry& reg, int idxPacketEntities); //< Function to draw text.
};
