/*
** EPITECH PROJECT, 2024
** TextComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once
#include "../IComponent.hpp"

/**
 * @class TextComponent
 * @brief Component for handling text in the graphical engine.
 * @inherit AComponent (inherits IComponent)
 *
 * This component is used to store and manage text entities within the graphical engine.
 *
 * @var text The text content to be managed by this component.
 */
class TextComponent : public AComponent {
    public:

        std::string text; //< The text content.

        /**
         * @brief Construct a new Text Component object
         *
         * @param text Initial text content (default is an empty string).
         */
        TextComponent(std::string text = "");
};
