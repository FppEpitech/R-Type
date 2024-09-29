/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** VelocityComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Velocity for R-Type Game.
 *
 */
class VelocityComponent : public IComponent {

    public:

        int velocity;  // Velocity.

        /**
         * @brief Construct a new Velocity Component object.
         *
         * @param velocity Velocity.
         */
        VelocityComponent(int velocity = 1);

        /**
         * @brief Get the Type object.
         *
         * @return const std::string& Type of the Component.
         */
        const std::string &getType();

    private:

        std::string     _type;  // Type of the Component.
};
