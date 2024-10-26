/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonStateComponent.cpp
*/

#include "ButtonStateComponent.hpp"

ButtonStateComponent::ButtonStateComponent(ButtonState state) : state(state), AComponent("ButtonStateComponent") {}

ButtonStateComponent::ButtonState ButtonStateComponent::getStateFromString(std::string state)
{
    if (state == "CLICKED")
        return ButtonState::CLICKED;
    if (state == "HOVER")
        return ButtonState::HOVER;
    return ButtonState::NONE;
}
