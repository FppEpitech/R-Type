/*
** EPITECH PROJECT, 2024
** SpeedParser
** File description:
** Speed3DParser
*/

#pragma once

#include "../../DefaultComponents/Speed3D/Speed3DComponent.hpp"

#include <memory>

/**
 * @brief Parse a Speed Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<SpeedComponent>
 */
std::shared_ptr<Speed3DComponent> parseSpeed3D(std::string pathFile);
