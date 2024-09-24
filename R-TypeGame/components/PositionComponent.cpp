/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** PositionComponent
*/

#include "PositionComponent.hpp"

PositionComponent::PositionComponent(int x, int y, int z) : x(x), y(y), z(z)
{
    _type = "PositionComponent";
}

const std::string &PositionComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance() {
    return new PositionComponent();
}
