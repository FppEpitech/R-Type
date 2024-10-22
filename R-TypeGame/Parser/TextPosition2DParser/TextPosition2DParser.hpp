/*
** EPITECH PROJECT, 2024
** TextPosition2DParser
** File description:
** TextPosition2DParser
*/

#pragma once

#include "TextPosition2D/TextPosition2DComponent.hpp"

#include <memory>

/**
 * @brief Parse a TextPosition2D Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<Position2DComponent>
 */
std::shared_ptr<TextPosition2DComponent> parseTextPosition2D(std::string pathFile);
