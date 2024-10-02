/*
** EPITECH PROJECT, 2024
** TextureRectComponent.cpp
** File description:
** DESCRIPTION
*/

#include "TextureRectComponent.hpp"

TextureRectComponent::TextureRectComponent(std::string path, int left, int top, int width, int height) :
    AComponent("TextureRectComponent"), path(path), left(left), top(top), width(width), height(height) {}
