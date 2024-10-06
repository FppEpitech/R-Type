/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** ShootComponent
*/

#pragma once

#include "../../../Engine/Shared/Interface/IComponent.hpp"

/**
 * @brief Component Shoot for R-Type Game.
 *
 */
class ShootComponent : public AComponent {

    public:

        int damage;         // Damage of one bullet.
        bool friendlyFire;  // Friendly bullet.

        /**
         * @brief Construct a new Shoot Component object.
         *
         * @param damage Damage of one bullet.
         * @param friendlyFire True if friendly bullet.
         */
        ShootComponent(int damage = 20, bool friendlyFire = true);
};
