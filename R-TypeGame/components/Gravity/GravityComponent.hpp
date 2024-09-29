/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** GravityComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Gravity for R-Type Game.
 *
 */
class GravityComponent : public IComponent {

    public:

        int gravity;  // Gravity.

        /**
         * @brief Construct a new Gravity Component object.
         *
         * @param gravity Gravity.
         */
        GravityComponent(int gravity = 1);

        /**
         * @brief Get the Type object.
         *
         * @return const std::string& Type of the Component.
         */
        const std::string &getType();

    private:

        std::string     _type;  // Type of the Component.
};
