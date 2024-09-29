/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Position3DComponent
*/

#pragma once

#include "../../../Engine/Shared/Interface/IComponent.hpp"

/**
 * @brief Component Position 3D for R-Type Game.
 *
 */
class Position3DComponent : public AComponent {

    public:

        int x;  // Position x.
        int y;  // Position y.
        int z;  // Position z.

        /**
         * @brief Construct a new Position 3D Component object.
         *
         * @param x Position x.
         * @param y Position y.
         * @param z Position z.
         */
        Position3DComponent(int x = 0, int y = 0, int z = 0);
};
