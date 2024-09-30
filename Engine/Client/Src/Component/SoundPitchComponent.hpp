/*
** EPITECH PROJECT, 2024
** SoundPitchComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class SoundPitchComponent
 * @brief Component for the sound pitch.
 *
 * This component is used to store the pitch of a sound file.
 *
 * @var Pitch The pitch of the sound.
 */
class SoundPitchComponent : public AComponent {
public:

    float pitch; //< The pitch of the sound.

    /**
     * @brief Construct a new SoundPitchComponent object
     *
     * @param Pitch Initial pitch of the sound (default is 1.0f).
     */
    SoundPitchComponent(float Pitch = 1.0f);
};
