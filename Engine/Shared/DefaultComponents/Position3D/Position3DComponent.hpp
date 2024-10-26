/*
** EPITECH PROJECT, 2024
** Position3DComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class Position3DComponent
 * @brief Component for handling 3D positions within the graphical engine.
 *
 * This component is used to store and manage the 3D position of entities.
 *
 * @var x The x-coordinate of the position.
 * @var y The y-coordinate of the position.
 * @var z The z-coordinate of the position.
 */
class Position3DComponent : public AComponent {

    public:

        int x; //< Position x.
        int y; //< Position y.
        int z; //< Position z.

        /**
         * @brief Construct a new Position3DComponent object
         *
         * @param x Initial x position (default is 0).
         * @param y Initial y position (default is 0).
         * @param z Initial z position (default is 0).
         */
        Position3DComponent(int x = 0, int y = 0, int z = 0);
};
