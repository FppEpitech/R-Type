/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** MobComponent
*/

#pragma once

#include "IComponent.hpp"

#include <chrono>
#include <ctime>

/**
 * @brief Component Mob for R-Type Game.
 *
 */
class MobComponent : public AComponent {

    public:

        /**
         * @brief Construct a new Mob Component object.
         *
         */
        MobComponent(float shootSpeed, int xStartOscillate, float oscillateSpeed, int minY, int maxY);

        std::chrono::high_resolution_clock::time_point clock = std::chrono::high_resolution_clock::now();   // clock.

        float shootSpeed = 1; // shoot speed.

        int xStartOscillate = 1600; // x start oscillate.

        float oscillateSpeed = 3; // oscillate speed.

        int minY = -50; // min y.

        int maxY = 850; // max y.
};
