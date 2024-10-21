/*
** EPITECH PROJECT, 2024
** Size1DParser
** File description:
** Size1DParser
*/

#pragma once

#include "../../../Engine/Shared/DefaultComponent/Size1D/Size1DComponent.hpp"

#include <memory>

/**
 * @brief Parse a Size1D Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ScaleComponent>
 */
std::shared_ptr<Size1DComponent> parseSize1D(std::string pathFile);
