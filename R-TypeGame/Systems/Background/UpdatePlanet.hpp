/*
** EPITECH PROJECT, 2024
** UpdatePlanet
** File description:
** UpdatePlanet
*/

#pragma once

#include <chrono>
#include <random>

#include "VelocityComponent.hpp"
#include "Position2DComponent.hpp"

void updateNewPositions(std::shared_ptr<VelocityComponent> velocity, std::shared_ptr<Position2DComponent> position);
