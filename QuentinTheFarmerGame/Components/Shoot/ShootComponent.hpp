/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** ShootComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Shoot for R-Type Game.
 *
 */
class ShootComponent : public AComponent {

    public:

        enum ShootType {
            PLAYER,
            ENEMY,
            BOSS,
            MOB,
            NONE
        };

        int damage;         // Damage of one bullet.
        bool friendlyFire;  // Friendly bullet.
        ShootType type;     // Type of the bullet.

        /**
         * @brief Construct a new Shoot Component object.
         *
         * @param damage Damage of one bullet.
         * @param friendlyFire True if friendly bullet.
         */
        ShootComponent(int damage = 20, bool friendlyFire = true, ShootType type = ShootType::NONE);
};
