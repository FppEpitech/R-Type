/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** VelocityComponent
*/

#pragma once

#include <chrono>

#include "../../../Engine/Shared/DefaultComponent/IComponent.hpp"

/**
 * @brief Component Velocity for R-Type Game.
 *
 */
class VelocityComponent : public AComponent {

    public:

        float vx;  // Velocity x.
        float vy;  // Velocity y.
        std::chrono::high_resolution_clock::time_point frameRate; // Velocity frameRate.

        /**
         * @brief Construct a new Velocity Component object.
         *
         * @param velocity Velocity.
         */
        VelocityComponent(float vx = 0, float vy = 0);
};
