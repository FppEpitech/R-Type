/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Position2DComponent
*/

#include "Position2DComponent.hpp"

Position2DComponent::Position2DComponent(int x, int y) : x(x), y(y)
{
    _type = "Position2DComponent";
}

const std::string &Position2DComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance()
{
    return new Position2DComponent();
}
