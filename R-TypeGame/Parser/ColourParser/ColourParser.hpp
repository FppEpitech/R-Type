/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ColourParser.hpp
*/

#pragma once

#include <memory>

#include "../../../Engine/Shared/DefaultComponent/Colour/ColourComponent.hpp"

/**
 * @brief Parse a Colour Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ColourComponent>
 */
std::shared_ptr<ColourComponent> parseColour(std::string pathFile);
