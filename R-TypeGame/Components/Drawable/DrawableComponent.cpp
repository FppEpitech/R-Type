/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** DrawableComponent
*/

#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent(bool drawable, std::string pathTexture) :
    drawable(drawable), pathTexture(pathTexture), AComponent("DrawableComponent")
{
}

extern "C" IComponent* loadComponentInstance()
{
    return new DrawableComponent();
}
