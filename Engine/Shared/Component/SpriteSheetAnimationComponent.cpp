/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationComponent.cpp
** File description:
** DESCRIPTION
*/

#include "SpriteSheetAnimationComponent.hpp"

SpriteSheetAnimationComponent::SpriteSheetAnimationComponent(
    std::size_t nbFrame, float timeFrame, float vx, float vy, float startX, float startY, std::size_t currentFrame, bool reverseMod) :
    AComponent("SpriteSheetAnimationComponent"),
    nbFrame(nbFrame), timeFrame(timeFrame), vx(vx), vy(vy), startX(startX), startY(startY), currentFrame(currentFrame), reverseMod(reverseMod)
{
    timeElapsed = clock();
}
