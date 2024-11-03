/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBoxComponent.cpp
*/

#include "HitBoxComponent.hpp"

HitBoxComponent::HitBoxComponent(std::vector<HitBox> hitBoxes)
    : hitBoxes(hitBoxes), AComponent("HitBoxComponent") {}

bool HitBoxComponent::isColliding(std::vector<HitBox> otherHitBoxes)
{
    for (auto &hitBox : hitBoxes) {
        for (auto &otherHitBox : otherHitBoxes) {
            if (hitBox.hit(otherHitBox))
                return true;
        }
    }
    return false;
}
