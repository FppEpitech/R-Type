/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** Speed3DComponent
*/

#pragma once

#include <chrono>

#include "IComponent.hpp"

/**
 * @brief Component Speed3D for R-Type Game.
 *
 */
class Speed3DComponent : public AComponent {

    public:

        float speedX;  // Speed X.
        float speedY;  // Speed Y.
        float speedZ;  // Speed Z.
        std::chrono::high_resolution_clock::time_point frameRate;  // Frame rate.

        /**
         * @brief Construct a new Speed3D Component object.
         *
         * @param speedX Speed X.
         * @param speedY speed Y.
         * @param speedZ speed Z.
         */
        Speed3DComponent(float speedX = 0, float speedY = 0, float speedZ = 0);
};
