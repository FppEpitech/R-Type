/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** SpeedComponent
*/

#include "SpeedComponent.hpp"

SpeedComponent::SpeedComponent(std::size_t speedX, std::size_t speedY) :
    speedX(speedX), speedY(speedY), AComponent("SpeedComponent")
{
    frameRate = std::chrono::high_resolution_clock::now();
}
