/*
** EPITECH PROJECT, 2024
** SoundVolumeComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class SoundVolumeComponent
 * @brief Component for the sound volume.
 *
 * This component is used to store the path to a sound file.
 *
 * @var Volume The volume of the sound.
 */
class SoundVolumeComponent : public AComponent {
public:

    float Volume; //< The volume of the sound.

    /**
     * @brief Construct a new SoundVolumeComponent object
     *
     * @param Volume Initial volume of the sound (default is 0.5f).
     */
    SoundVolumeComponent(float Volume = 0.5f);
};
