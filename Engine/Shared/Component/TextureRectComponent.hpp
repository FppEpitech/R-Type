/*
** EPITECH PROJECT, 2024
** TextureRectComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"
#include "SFML/Graphics.hpp"

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
        int left; //< Left coordinate of the rectangle.
        int top; //< Top coordinate of the rectangle.
        int width; //< Width of the rectangle.
        int height; //< Height of the rectangle.

        /**
         * @brief Construct a new TextureRectComponent object
         *
         * @param Path Initial path to the font file (default is an empty string).
         * @param left Left coordinate of the rectangle.
         * @param top Top coordinate of the rectangle.
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         */
        TextureRectComponent(std::string Path = "", int left = 0, int top = 0, int width = 0, int height = 0);
};
