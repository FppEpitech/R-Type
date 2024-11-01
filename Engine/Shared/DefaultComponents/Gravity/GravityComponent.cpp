/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** GravityComponent
*/

#include "GravityComponent.hpp"

GravityComponent::GravityComponent(float gravityX, float gravityY, float gravityZ)
    : gravityX(gravityX), gravityY(gravityY), gravityZ(gravityZ), AComponent("GravityComponent") {}
