/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** ShooterComponent
*/

#include "ShooterComponent.hpp"

ShooterComponent::ShooterComponent(int bullet, int damage) : bullet(bullet), damage(damage)
{
    _type = "ShooterComponent";
}

const std::string &ShooterComponent::getType()
{
    return _type;
}

extern "C" IComponent* loadComponentInstance()
{
    return new ShooterComponent();
}
