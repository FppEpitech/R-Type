/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

/**
 * @class IFont
 * @brief Interface for font operations.
 *
 * This interface defines methods for loading and retrieving default fonts.
 */
class IFont {
    public:
        /**
         * @brief Retrieve the default font.
         */
        virtual void GetFontDefault(void) = 0;

        /**
         * @brief Load a font from a file.
         * @param fileName The name of the file to load the font from.
         */
        virtual void LoadFont(const char *fileName) = 0;
};
