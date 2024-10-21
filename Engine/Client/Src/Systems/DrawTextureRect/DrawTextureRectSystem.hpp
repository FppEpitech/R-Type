/*
** EPITECH PROJECT, 2024
** DrawTextureRectSystem
** File description:
** DrawTextureRectSystem
*/

#pragma once

#include <iostream>

#include "../../../../Shared/DefaultSystems/ISystem.hpp"

/**
 * @brief System to draw an Texture Rect.
 *
 */
class DrawTextureRectSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Draw Texture Rect System object.
         *
         */
        DrawTextureRectSystem();

        /**
         * @brief Destroy the Draw Texture Rect System object.
         *
         */
        ~DrawTextureRectSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _drawTextureRect(reg, idxPacketEntities);
            };
        }

    private:

        void _drawTextureRect(ECS::Registry& reg, int idxPacketEntities); //< Function to draw texture rect.
};
