/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** DrawableComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Drawable for R-Type Game.
 *
 */
class DrawableComponent : public IComponent {

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

        /**
         * @brief Get the Type object.
         *
         * @return const std::string& Type of the Component.
         */
        const std::string &getType();

    private:

        std::string     _type;  // Type of the Component.
};
