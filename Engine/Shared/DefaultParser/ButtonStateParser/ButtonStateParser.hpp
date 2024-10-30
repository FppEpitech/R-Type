/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonStateParser.hpp
*/

#pragma once

#include <memory>

#include "../../DefaultComponents/ButtonState/ButtonStateComponent.hpp"

/**
 * @brief Parse a button state Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ButtonStateComponent>
 */
std::shared_ptr<ButtonStateComponent> parseButtonState(std::string pathFile);
