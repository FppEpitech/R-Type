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

        /**
         * @brief Get the Arg object(mainly for lua api).
         *
         * @return std::any
         */
        std::any getArg(std::string key) override {
            if (key == "damage")
                return std::any(damage);
            if (key == "friendlyFire")
                return std::any(friendlyFire);
            if (key == "type")
                return std::any(type);
            return std::any();
        }

        /**
         * @brief Set the Arg object (mainly for lua api).
         *
         * @return bool
         */
        bool setArg(std::string key, std::any value) override {
            if (key == "damage") {
                damage = std::any_cast<int>(value);
                return true;
            }
            if (key == "friendlyFire") {
                friendlyFire = std::any_cast<bool>(value);
                return true;
            }
            if (key == "type") {
                type = std::any_cast<ShootType>(value);
                return true;
            }
            return false;
        }
};
