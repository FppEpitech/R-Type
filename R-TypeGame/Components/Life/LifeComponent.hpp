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

        std::size_t life;  // Life.

        /**
         * @brief Construct a new Life Component object.
         *
         * @param life Life.
         */
        LifeComponent(std::size_t life = 100);
};
