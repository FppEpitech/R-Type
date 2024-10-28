/*
** EPITECH PROJECT, 2024
** SoundComponent.cpp
** File description:
** DESCRIPTION
*/

#include "SoundComponent.hpp"

SoundComponent::SoundComponent(float volume, std::string path, float pitch) : AComponent("SoundComponent"), volume(volume), path(path), pitch(pitch) {}
