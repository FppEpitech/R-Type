/*
** EPITECH PROJECT, 2024
** DrawTextureSystem
** File description:
** DrawTextureSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief System to draw an Texture.
 *
 */
class DrawTextureSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Draw Texture System object.
         *
         */
        DrawTextureSystem();

        /**
         * @brief Destroy the Draw Texture System object.
         *
         */
        ~DrawTextureSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _drawTexture(reg, idxPacketEntities);
            };
        }

    private:

        void _drawTexture(ECS::Registry& reg, int idxPacketEntities); //< Function to draw texture.
};
