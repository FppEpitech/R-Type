/*
** EPITECH PROJECT, 2024
** TextureRectComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class TextureRectComponent
 * @brief Component for handling Texture Rect in the graphical engine.
 *
 * This component is used to store and manage texture rect for the graphical engine.
 *
 * @var Path The path to one file.
 */
class TextureRectComponent : public AComponent {
    public:

        std::string path; //< The path to one file.
        float left; //< Left coordinate of the rectangle.
        float top; //< Top coordinate of the rectangle.
        float width; //< Width of the rectangle.
        float height; //< Height of the rectangle.

        /**
         * @brief Construct a new TextureRectComponent object
         *
         * @param Path Initial path to the font file (default is an empty string).
         * @param left Left coordinate of the rectangle.
         * @param top Top coordinate of the rectangle.
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         */
        TextureRectComponent(std::string Path = "", float left = 0, float top = 0, float width = 0, float height = 0);
};
