/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonTexturePathComponent.cpp
*/

#include "ButtonTexturePathComponent.hpp"

ButtonTexturePathComponent::ButtonTexturePathComponent(const std::string &noneTexturePath, const std::string &hoverTexturePath, const std::string &clickedTexturePath)
    : noneTexturePath(noneTexturePath), hoverTexturePath(hoverTexturePath), clickedTexturePath(clickedTexturePath), AComponent("ButtonTexturePathComponent") {}
