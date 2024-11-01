/*
** EPITECH PROJECT, 2024
** VelocityParser
** File description:
** VelocityParser
*/

#pragma once

#include "../../DefaultComponents/Velocity/VelocityComponent.hpp"

#include <memory>

/**
 * @brief Parse a Velocity Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<VelocityComponent>
 */
std::shared_ptr<VelocityComponent> parseVelocity(std::string pathFile);
