/*
** EPITECH PROJECT, 2024
** FontPathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class FontPathComponent
 * @brief Component for handling font paths in the graphical engine.
 *
 * This component is used to store and manage one path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class FontPathComponent : public AComponent {
    public:

        std::string Path; //< The path to one file.

        /**
         * @brief Construct a new FontPathComponent object
         *
         * @param Path Initial path to the font file (default is an empty string).
         */
        FontPathComponent(std::string Path = "");
};
