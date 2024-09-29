/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Position3DComponent
*/

#include "Position3DComponent.hpp"

Position3DComponent::Position3DComponent(int x, int y, int z) :
    x(x), y(y), z(z), AComponent("Position3DComponent") {}

extern "C" IComponent* loadComponentInstance()
{
    return new Position3DComponent();
}
