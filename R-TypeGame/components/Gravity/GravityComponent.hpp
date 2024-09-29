/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** GravityComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Gravity for R-Type Game.
 *
 */
class GravityComponent : public AComponent {

    public:

        unsigned int gravity;  // Gravity.

        /**
         * @brief Construct a new Gravity Component object.
         *
         * @param gravity Gravity.
         */
        GravityComponent(unsigned int gravity = 1);
};
