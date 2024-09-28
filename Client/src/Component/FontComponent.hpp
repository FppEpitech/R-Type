/*
** EPITECH PROJECT, 2024
** FontComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class FontComponent
 * @brief Component for handling font paths in the graphical engine.
 *
 * This component is used to store and manage the font path for text rendering within the graphical engine.
 *
 * @var fontPath The path to the font file.
 */

class FontComponent : public AComponent {
    public:

        std::string fontPath; //< The path to the font file.

        /**
         * @brief Construct a new FontComponent object
         *
         * @param fontPath Initial path to the font file (default is an empty string).
         */
        FontComponent(std::string fontPath = "");
};
