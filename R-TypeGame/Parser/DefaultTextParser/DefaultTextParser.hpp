/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** DefaultTextParser.hpp
*/

#pragma once

#include <memory>

#include "DefaultTextComponent.hpp"

/**
 * @brief Parse a text Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<DefaultTextComponent>
 */
std::shared_ptr<DefaultTextComponent> parseDefaultText(std::string pathFile);
