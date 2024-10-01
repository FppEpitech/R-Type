/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** SpeedComponent
*/

#include "SpeedComponent.hpp"

SpeedComponent::SpeedComponent(int speedX, int speedY) :
    speedX(speedX), speedY(speedY), AComponent("SpeedComponent")
{
}

extern "C" IComponent* loadComponentInstance()
{
    return new SpeedComponent();
}
