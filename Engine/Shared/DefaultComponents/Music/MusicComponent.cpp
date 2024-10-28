/*
** EPITECH PROJECT, 2024
** MusicComponent.cpp
** File description:
** DESCRIPTION
*/

#include "MusicComponent.hpp"

MusicComponent::MusicComponent(float volume, float pitch, std::string path) : AComponent("MusicComponent"), volume(volume), pitch(pitch), path(path) {}
