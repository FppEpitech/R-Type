/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** MobComponent
*/

#include "MobComponent.hpp"

MobComponent::MobComponent(float shootSpeed, int xStartOscillate, float oscillateSpeed, int minY, int maxY) : AComponent("MobComponent"), shootSpeed(shootSpeed), xStartOscillate(xStartOscillate), oscillateSpeed(oscillateSpeed), minY(minY), maxY(maxY)
{
}
