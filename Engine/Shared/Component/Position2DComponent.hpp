/*
** EPITECH PROJECT, 2024
** Position2DComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class Position2DComponent
 * @brief Component Position 2D for the graphical engine.
 * @inherit AComponent (inherits IComponent)
 *
 * We use this component to store the position of an entity in 2D.
 * for example, the position of a sprite or a text on the window.
 *
 * @var x Position on the width of the window.
 * @var y Position on the height of the window.
 *
 */
class Position2DComponent : public AComponent {

    public:

        float x; //< Position x.
        float y; //< Position y.

        /**
         * @brief Construct a new Position 2D Component object
         *
         * @param x Initial x position (default is 0).
         * @param y Initial y position (default is 0).
         */
        Position2DComponent(float x = 0, float y = 0);
};
