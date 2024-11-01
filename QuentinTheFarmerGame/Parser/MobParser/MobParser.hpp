/*
** EPITECH PROJECT, 2024
** MobParser
** File description:
** ShotParser
*/

#pragma once

#include "MobComponent.hpp"

#include <memory>

/**
 * @brief Parse a Mob Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<MobComponent>
 */
std::shared_ptr<MobComponent> parseMob(std::string pathFile);
