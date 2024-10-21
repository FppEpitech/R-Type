/*
** EPITECH PROJECT, 2024
** UpdatePlanet
** File description:
** UpdatePlanet
*/

#pragma once

#include <chrono>
#include <random>
#include  <memory>

#include "VelocityComponent.hpp"
#include "../../../Engine/Shared/DefaultComponent/Position2D/Position2DComponent.hpp"

/**
 * @brief Update the positions for planets.
 *
 * @param velocity Velocity of the planet.
 * @param position Position of the planet.
 */
void updateNewPositions(std::shared_ptr<VelocityComponent> velocity, std::shared_ptr<Position2DComponent> position);
