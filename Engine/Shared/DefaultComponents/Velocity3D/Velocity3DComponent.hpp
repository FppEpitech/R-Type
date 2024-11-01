/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Velocity3DComponent
*/

#pragma once

#include <chrono>

#include "../IComponent.hpp"

/**
 * @brief Component Velocity3D for R-Type Game.
 *
 */
class Velocity3DComponent : public AComponent {

    public:

        float vx;  // Velocity x.
        float vy;  // Velocity y.
        float vz;  // Velocity z.
        std::chrono::high_resolution_clock::time_point frameRate; // Velocity3D frameRate.

        /**
         * @brief Construct a new Velocity3D Component object.
         *
         * @param velocity Velocity3D.
         */
        Velocity3DComponent(float vx = 0, float vy = 0, float vz = 0);
};
