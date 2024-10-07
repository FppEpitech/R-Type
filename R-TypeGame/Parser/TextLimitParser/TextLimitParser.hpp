/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TextLimitParser.hpp
*/

#pragma once

#include <memory>

#include "TextLimitComponent.hpp"

/**
 * @brief Parse a TextLimitComponent from a json file
 * @param path The path to the json file
 * @return The TextLimitComponent
 */
std::shared_ptr<TextLimitComponent> parseTextLimit(const std::string &path);