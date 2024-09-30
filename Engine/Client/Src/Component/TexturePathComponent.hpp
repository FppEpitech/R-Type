/*
** EPITECH PROJECT, 2024
** TexturePathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class TexturePathComponent
 * @brief Component for handling paths in the graphical engine.
 *
 * This component is used to store and manage one obj path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class TexturePathComponent : public AComponent {
    public:

        std::string path; //< The path to one file.

        /**
         * @brief Construct a new TexturePathComponent object
         *
         * @param Path Initial path to the font file (default is an empty string).
         */
        TexturePathComponent(std::string Path = "");
};
