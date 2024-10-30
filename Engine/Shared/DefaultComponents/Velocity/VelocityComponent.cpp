/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** VelocityComponent
*/

#include "Velocity/VelocityComponent.hpp"

VelocityComponent::VelocityComponent(float vx, float vy) :
    vx(vx), vy(vy), AComponent("VelocityComponent")
{
    frameRate = std::chrono::high_resolution_clock::now();
}
