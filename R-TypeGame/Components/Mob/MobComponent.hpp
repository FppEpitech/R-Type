/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** MobComponent
*/

#pragma once

#include "../../../Engine/Shared/Interface/IComponent.hpp"

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
        MobComponent();

        std::chrono::high_resolution_clock::time_point clock;   // clock.
};
