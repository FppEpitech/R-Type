/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** SpeedComponent
*/

#pragma once

#include <chrono>

#include "IComponent.hpp"

/**
 * @brief Component Speed for R-Type Game.
 *
 */
class SpeedComponent : public AComponent {

    public:

        std::size_t speedX;  // Speed X.
        std::size_t speedY;  // Speed Y.
        std::chrono::high_resolution_clock::time_point frameRate;  // Frame rate.

        /**
         * @brief Construct a new Speed Component object.
         *
         * @param speedX Speed X.
         * @param speedY speed Y.
         */
        SpeedComponent(std::size_t speedX = 1, std::size_t speedY = 1);
};
