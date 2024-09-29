/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** LifeComponent
*/

#include "LifeComponent.hpp"

LifeComponent::LifeComponent(int life) : life(life)
{
    _type = "LifeComponent";
}

const std::string &LifeComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance()
{
    return new LifeComponent();
}
