/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonTexturePathComponent.cpp
*/

#include "ButtonTexturePathComponent.hpp"

ButtonTexturePathComponent::ButtonTexturePathComponent(const std::string noneTexturePath, const std::string hoverTexturePath, const std::string clickedTexturePath, const std::string pressedTexturePath)
    : noneTexturePath(noneTexturePath), hoverTexturePath(hoverTexturePath), clickedTexturePath(clickedTexturePath), pressedTexturePath(pressedTexturePath), AComponent("ButtonTexturePathComponent") {}
