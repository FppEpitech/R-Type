/*
** EPITECH PROJECT, 2024
** SoundComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class SoundComponent
 * @brief A component that handles sound properties.
 */
class SoundComponent : public AComponent {
public:

    /**
     * @brief Volume of the sound.
     */
    float volume;

    /**
     * @brief File path to the sound resource.
     */
    std::string path;

    /**
     * @brief Pitch of the sound.
     */
    float pitch;

    /**
     * @brief Constructor for SoundComponent.
     * @param Volume Initial volume of the sound.
     * @param Path File path to the sound resource.
     * @param Pitch Initial pitch of the sound.
     */
    SoundComponent(float Volume = 0.5f, std::string Path = "", float Pitch = 1.0f);
};
