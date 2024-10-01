/*
** EPITECH PROJECT, 2024
** MusicPathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../../../../Shared/Interface/IComponent.hpp"

/**
 * @class MusicPathComponent
 * @brief Component for handling font paths in the graphical engine.
 *
 * This component is used to store and manage one path for the graphical engine.
 *
 * @var Path The path to one file.
 */
class MusicPathComponent : public AComponent {
public:

    std::string path; //< The path to one file.

    /**
     * @brief Construct a new MusicPathComponent object
     *
     * @param Path Initial path to the font file (default is an empty string).
     */
    MusicPathComponent(std::string Path = "");
};
