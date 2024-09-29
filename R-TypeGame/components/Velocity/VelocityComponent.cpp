/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** VelocityComponent
*/

#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(int velocity) : velocity(velocity)
{
    _type = "VelocityComponent";
}

const std::string &VelocityComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance()
{
    return new VelocityComponent();
}
