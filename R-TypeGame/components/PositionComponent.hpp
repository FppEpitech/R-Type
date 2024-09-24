/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** PositionComponent
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component Position for R-Type Game.
 *
 */
class PositionComponent : public IComponent {

    public:

        int x = 0;
        int y = 0;

        /**
         * @brief Construct a new Position Component object.
         *
         * @param x Position x.
         * @param y Position y.
         */
        PositionComponent(int x = 0, int y = 0);

        /**
         * @brief Get the Type object.
         *
         * @return const std::string& Type of the Component.
         */
        const std::string &getType();

    private:

        std::string     _type;  // Type of the Component.
};
