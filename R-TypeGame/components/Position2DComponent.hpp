/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Position2DComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Position 2D for R-Type Game.
 *
 */
class Position2DComponent : public IComponent {

    public:

        int x;  // Position x.
        int y;  // Position y.

        /**
         * @brief Construct a new Position 2D Component object.
         *
         * @param x Position x.
         * @param y Position y.
         */
        Position2DComponent(int x = 0, int y = 0);

        /**
         * @brief Get the Type object.
         *
         * @return const std::string& Type of the Component.
         */
        const std::string &getType();

    private:

        std::string     _type;  // Type of the Component.
};
