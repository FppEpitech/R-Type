/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** FontParser.hpp
*/

#pragma once

#include <memory>

#include "../../../Engine/Shared/DefaultComponent/FontPath/FontPathComponent.hpp"

/**
 * @brief Parse a Font Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<FontPathComponent>
 */
std::shared_ptr<FontPathComponent> parseFontPath(std::string pathFile);
