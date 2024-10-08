/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonTexturePathParser.hpp
*/

#pragma once

#include <memory>

#include "ButtonTexturePathComponent.hpp"

/**
 * @brief Parse a path to create a ButtonTexturePathComponent
 * @param path The path to parse
 * @return A shared pointer to the ButtonTexturePathComponent
 */
std::shared_ptr<ButtonTexturePathComponent> parseButtonTexturePath(const std::string &path);
