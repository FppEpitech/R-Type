/*
** EPITECH PROJECT, 2024
** TextPosition2DComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class TextPosition2DComponent
 * @brief Component Text Position 2D for the graphical engine.
 * @inherit AComponent (inherits IComponent)
 *
 * We use this component to store the position of a text in 2D.
 *
 * @var x Position on the width of the window.
 * @var y Position on the height of the window.
 *
 */
class TextPosition2DComponent : public AComponent {

    public:

        int x; //< Position x.
        int y; //< Position y.

        /**
         * @brief Construct a new Position 2D Component object
         *
         * @param x Initial x position (default is 0).
         * @param y Initial y position (default is 0).
         */
        TextPosition2DComponent(int x = 0, int y = 0);
};
