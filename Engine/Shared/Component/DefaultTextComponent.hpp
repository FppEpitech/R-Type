/*
** EPITECH PROJECT, 2024
** DefaultTextComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once
#include "IComponent.hpp"

/**
 * @class DefaultTextComponent
 * @brief Component for handling default text in the graphical engine.
 * @inherit AComponent (inherits IComponent)
 *
 * This component is used to store and manage text entities within the graphical engine.
 *
 * @var text The text content to be managed by this component.
 */
class DefaultTextComponent : public AComponent {
    public:

        std::string text; //< The text content.

        /**
         * @brief Construct a new Default Text Component object
         *
         * @param text Initial text content (default is an empty string).
         */
        DefaultTextComponent(std::string text = "");
};
