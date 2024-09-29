/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** GravityComponent
*/

#include "GravityComponent.hpp"

GravityComponent::GravityComponent(int gravity) :
    gravity(gravity), AComponent("GravityComponent")
{
}

extern "C" IComponent* loadComponentInstance()
{
    return new GravityComponent();
}
