/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** MobComponent
*/

#include "MobComponent.hpp"

MobComponent::MobComponent() : AComponent("MobComponent"), clock(std::chrono::high_resolution_clock::now())
{
}
