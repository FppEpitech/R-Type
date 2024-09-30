/*
** EPITECH PROJECT, 2024
** MusicVolumeComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class MusicVolumeComponent
 * @brief Component for the music volume.
 *
 * This component is used to store the path to a music file.
 *
 * @var Volume The volume of the music.
 */
class MusicVolumeComponent : public AComponent {
public:

    float Volume; //< The volume of the music.

    /**
     * @brief Construct a new MusicVolumeComponent object
     *
     * @param Volume Initial volume of the music (default is 0.5f).
     */
    MusicVolumeComponent(float Volume = 0.5f);
};
