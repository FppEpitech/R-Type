/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Velocity3DComponent
*/

#include "Velocity3D/Velocity3DComponent.hpp"

Velocity3DComponent::Velocity3DComponent(float vx, float vy, float vz) :
    vx(vx), vy(vy), vz(vz), AComponent("Velocity3DComponent")
{
    frameRate = std::chrono::high_resolution_clock::now();
}
