/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Speed3DComponent
*/

#include "Speed3DComponent.hpp"

Speed3DComponent::Speed3DComponent(float speedX, float speedY, float speedZ) :
    speedX(speedX), speedY(speedY), speedZ(speedZ), AComponent("Speed3DComponent")
{
    frameRate = std::chrono::high_resolution_clock::now();
}
