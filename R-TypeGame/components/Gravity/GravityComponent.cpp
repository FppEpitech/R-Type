/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** GravityComponent
*/

#include "GravityComponent.hpp"

GravityComponent::GravityComponent(int gravity) : gravity(gravity)
{
    _type = "GravityComponent";
}

const std::string &GravityComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance()
{
    return new GravityComponent();
}
