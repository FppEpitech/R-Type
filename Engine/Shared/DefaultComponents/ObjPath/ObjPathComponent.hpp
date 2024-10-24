/*
** EPITECH PROJECT, 2024
** ObjPathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class ObjPathComponent
 * @brief Component for handling paths in the graphical engine.
 *
 * This component is used to store and manage one obj path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class ObjPathComponent : public AComponent {
    public:

        std::string path; //< The path to one file.

        /**
         * @brief Construct a new ObjPathComponent object
         *
         * @param Path Initial path to the font file (default is an empty string).
         */
        ObjPathComponent(std::string Path = "");
};
