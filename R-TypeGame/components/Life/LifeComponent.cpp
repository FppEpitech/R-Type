/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** LifeComponent
*/

#include "LifeComponent.hpp"

LifeComponent::LifeComponent(int life) :
    life(life), AComponent("LifeComponent")
{
}

extern "C" IComponent* loadComponentInstance()
{
    return new LifeComponent();
}
