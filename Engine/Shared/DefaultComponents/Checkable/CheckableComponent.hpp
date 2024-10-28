/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CheckableComponent.hpp
*/

#pragma once

#include <functional>

#include "../IComponent.hpp"

/**
 * @brief Component Checkable for R-Type Game.
 *
 */
class CheckableComponent : public AComponent {

    public:

        bool isChecked; //< The checked state.

        /**
         * @brief Construct a new Checkable Component object.
         *
         * @param isChecked The checked state.
         */
        CheckableComponent(bool isChecked = false);
};
