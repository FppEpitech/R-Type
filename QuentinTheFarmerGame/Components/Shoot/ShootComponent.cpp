/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** ShootComponent
*/

#include "ShootComponent.hpp"

ShootComponent::ShootComponent(int damage, bool friendlyFire, ShootType type) :
    damage(damage), friendlyFire(friendlyFire), type(type), AComponent("ShootComponent") {}
