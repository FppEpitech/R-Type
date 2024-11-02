/*
** EPITECH PROJECT, 2024
** GravityParser
** File description:
** GravityParser
*/

#pragma once

#include "../../DefaultComponents/Gravity/GravityComponent.hpp"

#include <memory>

/**
 * @brief Parse a Gravity Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<GravityComponent>
 */
std::shared_ptr<GravityComponent> parseGravity(std::string pathFile);
