/*
** EPITECH PROJECT, 2024
** LifeParser
** File description:
** LifeParser
*/

#pragma once

#include "LifeComponent.hpp"

#include <memory>

/**
 * @brief Parse a life Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<LifeComponent>
 */
std::shared_ptr<LifeComponent> parseLife(std::string pathFile);
