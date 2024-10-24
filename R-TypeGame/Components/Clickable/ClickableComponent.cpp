/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClickableComponent.cpp
*/

#include "ClickableComponent.hpp"

ClickableComponent::ClickableComponent(std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback) : callback(callback), AComponent("ClickableComponent") {}
