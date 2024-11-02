/*
** EPITECH PROJECT, 2024
** Position3DParser
** File description:
** Position3DParser
*/

#pragma once

#include "../../DefaultComponents/Position3D/Position3DComponent.hpp"

#include <memory>

/**
 * @brief Parse a Position3D Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<Position3DComponent>
 */
std::shared_ptr<Position3DComponent> parsePosition3D(std::string pathFile);
