/*
** EPITECH PROJECT, 2024
** MusicPitchComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class MusicPitchComponent
 * @brief Component for the music pitch.
 *
 * This component is used to store the pitch of a music file.
 *
 * @var Pitch The pitch of the music.
 */
class MusicPitchComponent : public AComponent {
public:

    float pitch; //< The pitch of the music.

    /**
     * @brief Construct a new MusicPitchComponent object
     *
     * @param Pitch Initial pitch of the music (default is 1.0f).
     */
    MusicPitchComponent(float Pitch = 1.0f);
};
