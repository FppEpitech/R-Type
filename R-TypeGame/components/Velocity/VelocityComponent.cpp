/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** VelocityComponent
*/

#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(int velocity) :
    velocity(velocity), AComponent("VelocityComponent")
{
}

extern "C" IComponent* loadComponentInstance()
{
    return new VelocityComponent();
}
