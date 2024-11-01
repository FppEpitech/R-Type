/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonStateComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Component ButtonState for R-Type Game.
 *
 */
 class ButtonStateComponent : public AComponent {

    public:

        /**
         * @brief Enum of the button state.
         *
         */
        enum ButtonState {
            CLICKED,
            PRESSED,
            HOVER,
            NONE
        };

        ButtonState state;  // State of the button.

        /**
         * @brief Construct a new Button State Component object.
         *
         * @param state The state of the button.
         */
        ButtonStateComponent(ButtonState state = ButtonState::NONE);

        /**
         * @brief Get a state from a string.
         *
         * @param state The state in string.
         * @return ButtonState The state in enum.
         */
        static ButtonState getStateFromString(std::string state);
};
