/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootTypeParser.hpp
*/

#pragma once

#include <memory>

#include "ShootTypeComponent.hpp"

/**
 * @brief Parse a button state Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ShootTypeComponent>
 */
std::shared_ptr<ShootTypeComponent> parseShootType(std::string pathFile);
