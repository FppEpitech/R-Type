/*
** EPITECH PROJECT, 2024
** TextureRectComponent.cpp
** File description:
** DESCRIPTION
*/

#include "TextureRectComponent.hpp"

TextureRectComponent::TextureRectComponent(std::string path, float left, float top, float width, float height) :
    AComponent("TextureRectComponent"), path(path), left(left), top(top), width(width), height(height) {}
