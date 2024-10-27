/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootTypeComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component ShootType for R-Type Game.
 *
 */
 class ShootTypeComponent : public AComponent {

    public:

        /**
         * @brief Enum of the shot state.
         *
         */
        enum ShootType {
            SINGLE,
            DOUBLE,
            TRIPLE,
            QUADRUPLE,
            QUINTUPLE,
            SEXTUPLE,
            NONE
        };

        ShootType type;  // type of the shot.

        /**
         * @brief Construct a new Button type Component object.
         *
         * @param state The state of the shot.
         */
        ShootTypeComponent(ShootType type = ShootType::NONE);

        /**
         * @brief Get a state from a string.
         *
         * @param state The state in string.
         * @return ShootType The state in enum.
         */
        static ShootType getTypeFromString(std::string type);
};
