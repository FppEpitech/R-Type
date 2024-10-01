/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** SpeedComponent
*/

#pragma once

#include "../../../Engine/Shared/Interface/IComponent.hpp"

/**
 * @brief Component Speed for R-Type Game.
 *
 */
class SpeedComponent : public AComponent {

    public:

        int speedX;  // Speed X.
        int speedY;  // Speed Y.

        /**
         * @brief Construct a new Speed Component object.
         *
         * @param speedX Speed X.
         * @param speedY speed Y.
         */
        SpeedComponent(int speedX = 1, int speedY = 1);
};
