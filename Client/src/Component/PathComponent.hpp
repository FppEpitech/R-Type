/*
** EPITECH PROJECT, 2024
** PathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class PathComponent
 * @brief Component for handling paths in the graphical engine.
 *
 * This component is used to store and manage one path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class PathComponent : public AComponent {
    public:

        std::string Path; //< The path to one file.

        /**
         * @brief Construct a new PathComponent object
         *
         * @param Path Initial path to the font file (default is an empty string).
         */
        PathComponent(std::string Path = "");
};
