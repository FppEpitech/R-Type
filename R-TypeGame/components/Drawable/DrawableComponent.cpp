/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** DrawableComponent
*/

#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent(bool drawable, std::string pathTexture) : drawable(drawable), pathTexture(pathTexture)
{
    _type = "DrawableComponent";
}

const std::string &DrawableComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance()
{
    return new DrawableComponent();
}
