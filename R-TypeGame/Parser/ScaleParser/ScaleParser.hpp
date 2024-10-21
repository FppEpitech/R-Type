/*
** EPITECH PROJECT, 2024
** ScaleParser
** File description:
** ScaleParser
*/

#pragma once

#include "../../../Engine/Shared/DefaultComponent/Scale/ScaleComponent.hpp"

#include <memory>

/**
 * @brief Parse a Scale Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ScaleComponent>
 */
std::shared_ptr<ScaleComponent> parseScale(std::string pathFile);
