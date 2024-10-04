/*
** EPITECH PROJECT, 2024
** Position2DParser
** File description:
** Position2DParser
*/

#pragma once

#include "Position2DComponent.hpp"

#include <memory>

/**
 * @brief Parse a Position2D Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<Position2DComponent>
 */
std::shared_ptr<Position2DComponent> parsePosition2D(std::string pathFile);
