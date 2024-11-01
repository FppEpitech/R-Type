/*
** EPITECH PROJECT, 2024
** SpeedParser
** File description:
** SpeedParser
*/

#pragma once

#include "../../DefaultComponents/Speed/SpeedComponent.hpp"

#include <memory>

/**
 * @brief Parse a Speed Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<SpeedComponent>
 */
std::shared_ptr<SpeedComponent> parseSpeed(std::string pathFile);
