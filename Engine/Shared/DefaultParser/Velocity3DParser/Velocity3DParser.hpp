/*
** EPITECH PROJECT, 2024
** Velocity3DParser
** File description:
** Velocity3DParser
*/

#pragma once

#include "../../DefaultComponents/Velocity3D/Velocity3DComponent.hpp"

#include <memory>

/**
 * @brief Parse a Velocity3D Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<Velocity3DComponent>
 */
std::shared_ptr<Velocity3DComponent> parseVelocity3D(std::string pathFile);
