/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** GravityComponent
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @brief Component Gravity for R-Type Game.
 *
 */
class GravityComponent : public AComponent {

    public:

        float gravityX;  // Gravity.
        float gravityY;  // Gravity.
        float gravityZ;  // Gravity.

        /**
         * @brief Construct a new Gravity Component object.
         *
         * @param gravityX Gravity.
         * @param gravityY Gravity.
         * @param gravityZ Gravity.
         */
        GravityComponent(float gravityX = 0, float gravityY = 0, float gravityZ = 0);
};
