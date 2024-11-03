/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ColliderDamageComponent.hpp
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @brief ColliderDamage component.
 */
class ColliderDamageComponent : public AComponent {
    public:

        float damage; //< The damage dealt by the collider.

        /**
         * @brief Construct a new ColliderDamage Component object.
         *
         * @param damage The damage of the collider.
         */
        ColliderDamageComponent(float damage = 0);
};
