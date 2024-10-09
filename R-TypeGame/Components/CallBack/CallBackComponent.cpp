/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CallbackComponent.cpp
*/

#include "CallBackComponent.hpp"

CallBackComponent::CallBackComponent(std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback) : callback(callback), AComponent("CallBackComponent") {}
