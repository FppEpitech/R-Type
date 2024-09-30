/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** ShooterComponent
*/

#pragma once

#include "../../../Engine/Shared/Interface/IComponent.hpp"

/**
 * @brief Component Shooter for R-Type Game.
 *
 */
class ShooterComponent : public AComponent {

    public:

        int bullet;  // Bullet shootable per second.
        int damage;  // Damage of one bullet.

        /**
         * @brief Construct a new Shooter Component object.
         *
         * @param bullet Number of bullet shootable per second.
         * @param damage Damage of one bullet.
         */
        ShooterComponent(int bullet = 1, int damage = 20);
};
