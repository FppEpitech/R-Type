/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** LifeComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Life for R-Type Game.
 *
 */
class LifeComponent : public AComponent {

    public:

        int life;  // Life.

        /**
         * @brief Construct a new Life Component object.
         *
         * @param life Life.
         */
        LifeComponent(int life = 100);
};
