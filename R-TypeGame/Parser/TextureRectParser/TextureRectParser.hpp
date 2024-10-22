/*
** EPITECH PROJECT, 2024
** TextureRectParser
** File description:
** TextureRectParser
*/

#pragma once

#include "TextureRect/TextureRectComponent.hpp"

#include <memory>

/**
 * @brief Parse a TextureRect Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<TextureRectComponent>
 */
std::shared_ptr<TextureRectComponent> parseTextureRect(std::string pathFile);
