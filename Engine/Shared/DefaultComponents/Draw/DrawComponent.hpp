/*
** EPITECH PROJECT, 2024
** DrawComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once
#include "../IComponent.hpp"

/**
 * @class DrawComponent
 * @brief Component for handling draw in the graphical engine.
 * @inherit AComponent (inherits IComponent)
 *
 * This component is used to know if we should draw entities within the graphical engine.
 *
 * @var text The text content to be managed by this component.
 */
class DrawComponent : public AComponent {
    public:

        bool draw; //< The draw boolean.

        /**
         * @brief Construct a new Default Draw Component object
         *
         * @param draw True if we draw, false instead.
         */
        DrawComponent(bool draw = true);
};
