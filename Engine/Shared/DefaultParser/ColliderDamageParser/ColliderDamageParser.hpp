/*
** EPITECH PROJECT, 2024
** ColliderDamageParser
** File description:
** ColliderDamageParser
*/

#pragma once

#include "../../DefaultComponents/ColliderDamage/ColliderDamageComponent.hpp"

#include <memory>

/**
 * @brief Parse a ColliderDamage Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ColliderDamageComponent>
 */
std::shared_ptr<ColliderDamageComponent> parseColliderDamage(std::string pathFile);
