/*
** EPITECH PROJECT, 2024
** MusicComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class MusicComponent
 * @brief A component that handles music properties.
 */
class MusicComponent : public AComponent {
public:
    /**
     * @brief Volume of the music.
     */
    float volume;

    /**
     * @brief Pitch of the music.
     */
    float pitch;

    /**
     * @brief File path to the music.
     */
    std::string path;

    /**
     * @brief Constructor for MusicComponent.
     * @param Volume Initial volume of the music, default is 0.5f.
     */
    MusicComponent(float Volume = 0.5f, float Pitch = 1.0f, std::string Path = "");
};
