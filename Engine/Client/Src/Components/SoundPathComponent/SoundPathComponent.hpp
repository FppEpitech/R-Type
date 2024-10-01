/*
** EPITECH PROJECT, 2024
** SoundPathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../../../../Shared/Interface/IComponent.hpp"

/**
 * @class SoundPathComponent
 * @brief Component for handling font paths in the graphical engine.
 *
 * This component is used to store and manage one path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class SoundPathComponent : public AComponent {
public:

    std::string path; //< The path to one file.

    /**
     * @brief Construct a new SoundPathComponent object
     *
     * @param Path Initial path to the font file (default is an empty string).
     */
    SoundPathComponent(std::string Path = "");
};
