/*
** EPITECH PROJECT, 2024
** ShootParser
** File description:
** ShotParser
*/

#pragma once

#include "ShootComponent.hpp"

#include <memory>

/**
 * @brief Parse a Shoot Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ShootComponent>
 */
std::shared_ptr<ShootComponent> parseShoot(std::string pathFile);
