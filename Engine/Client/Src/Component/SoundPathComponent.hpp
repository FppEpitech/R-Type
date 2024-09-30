/*
** EPITECH PROJECT, 2024
** SoundPathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class jSoundPathComponent
 * @brief Component for handling font paths in the graphical engine.
 *
 * This component is used to store and manage one path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class jSoundPathComponent : public AComponent {
public:

    std::string Path; //< The path to one file.

    /**
     * @brief Construct a new jSoundPathComponent object
     *
     * @param Path Initial path to the font file (default is an empty string).
     */
    jSoundPathComponent(std::string Path = "");
};
