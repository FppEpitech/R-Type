/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationParser
** File description:
** SpriteSheetAnimationParser
*/

#pragma once

#include "SpriteSheetAnimation/SpriteSheetAnimationComponent.hpp"

#include <memory>

/**
 * @brief Parse a SpriteSheetAnimation Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<SpriteSheetAnimationComponent>
 */
std::shared_ptr<SpriteSheetAnimationComponent> parseSpriteSheetAnimation(std::string pathFile);
