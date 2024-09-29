/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** DrawableComponent
*/

#pragma once

#include "../../../Engine/Shared/Interface/IComponent.hpp"

/**
 * @brief Component Drawable for R-Type Game.
 *
 */
class DrawableComponent : public AComponent {

    public:

        bool drawable;              // Drawable.
        std::string pathTexture;    // Path of the texture to draw.

        /**
         * @brief Construct a new Drawable Component object.
         *
         * @param drawable True if texture is drawable else false..
         * @param pathTexture The texture to draw.
         */
        DrawableComponent(bool drawable = false, std::string pathTexture = "None");
};
