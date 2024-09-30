/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IFont.hpp"
#include "IColor.hpp"

/**
 * @class IText
 * @brief Interface for text operations.
 *
 * This interface defines a set of methods for loading, setting properties, and displaying text.
 */
class IText {
    public:
        /**
         * @brief Virtual destructor for IText.
         */
        virtual ~IText() = default;

        /**
         * @brief Load a text.
         * @return An instance of IText.
         */
        virtual IText LoadText() = 0;

        /**
         * @brief Set the color of the text.
         * @param color The color to set.
         */
        virtual void SetColor(Color color) = 0;

        /**
         * @brief Set the size of the text.
         * @param size The size to set.
         */
        virtual void SetSize(int size) = 0;

        /**
         * @brief Set the font of the text.
         * @param font The font to set.
         */
        virtual void SetFont(IFont font) = 0;

        /**
         * @brief Set the position of the text.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        virtual void SetPosition(int x, int y) = 0;

        /**
         * @brief Display the text.
         */
        virtual void DisplayText() = 0;
};
