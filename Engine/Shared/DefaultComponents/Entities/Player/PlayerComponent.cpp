/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"

PlayerComponent::PlayerComponent(uint32_t token, bool isAlive)
    : token(token), isAlive(isAlive), AComponent("PlayerComponent") {}