/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** VelocityComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Velocity for R-Type Game.
 *
 */
class VelocityComponent : public AComponent {

    public:

        unsigned int velocity;  // Velocity.

        /**
         * @brief Construct a new Velocity Component object.
         *
         * @param velocity Velocity.
         */
        VelocityComponent(unsigned int velocity = 1);
};
