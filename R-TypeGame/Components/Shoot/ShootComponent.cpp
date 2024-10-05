/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** ShootComponent
*/

#include "ShootComponent.hpp"

ShootComponent::ShootComponent(int damage, bool friendlyFire) :
    damage(damage), friendlyFire(friendlyFire), AComponent("ShootComponent")
{
}
