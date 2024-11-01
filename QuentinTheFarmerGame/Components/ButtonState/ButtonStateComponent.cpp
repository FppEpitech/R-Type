/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonStateComponent.cpp
*/

#include <unordered_map>

#include "ButtonStateComponent.hpp"

ButtonStateComponent::ButtonStateComponent(ButtonState state) : state(state), AComponent("ButtonStateComponent") {}

ButtonStateComponent::ButtonState ButtonStateComponent::getStateFromString(std::string state)
{
    const std::unordered_map<std::string, ButtonState> states = {
        {"CLICKED", ButtonState::CLICKED},
        {"PRESSED", ButtonState::PRESSED},
        {"HOVER", ButtonState::HOVER},
        {"NONE", ButtonState::NONE}
    };
    if (states.find(state) != states.end())
        return states.at(state);
    return ButtonState::NONE;
}
