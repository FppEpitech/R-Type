/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TextParser.hpp
*/

#pragma once

#include <memory>

#include "TextComponent.hpp"

/**
 * @brief Parse a text Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<TextComponent>
 */
std::shared_ptr<TextComponent> parseText(std::string pathFile);