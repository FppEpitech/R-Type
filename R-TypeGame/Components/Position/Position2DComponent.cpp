/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Position2DComponent
*/

#include "Position2DComponent.hpp"

Position2DComponent::Position2DComponent(int x, int y) :
    x(x), y(y), AComponent("Position2DComponent")
{
}

extern "C" IComponent* loadComponentInstance()
{
    return new Position2DComponent();
}
