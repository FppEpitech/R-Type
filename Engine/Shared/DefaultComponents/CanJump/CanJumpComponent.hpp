/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** CanJumpComponent
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @brief Component CanJump for R-Type Game.
 *
 */
class CanJumpComponent : public AComponent {

    public:

        bool canJump; //< Can jump

        /**
         * @brief Construct a new CanJump Component object.
         *
         * @param canJump Define if the entity can jump
         */
        CanJumpComponent(bool canJump = false);
};
