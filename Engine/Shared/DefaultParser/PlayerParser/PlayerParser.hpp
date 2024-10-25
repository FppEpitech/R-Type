/*
** EPITECH PROJECT, 2024
** PlayerParser
** File description:
** PlayerParser
*/

#pragma once

#include "../../DefaultComponents/Entities/Player/PlayerComponent.hpp"

#include <memory>

/**
 * @brief Parse a Player Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<PlayerComponent>
 */
std::shared_ptr<PlayerComponent> parsePlayer(std::string pathFile);
