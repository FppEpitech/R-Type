/*
** EPITECH PROJECT, 2024
** ScaleComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../Interface/IComponent.hpp"

/**
 * @class ScaleComponent
 * @brief Component for handling scale within the graphical engine.
 *
 * This component is used to store and manage the scale of entities.
 *
 * @var scale The scale factor of the entity.
 */
class ScaleComponent : public AComponent {

    public:

        float scale; //< The scale factor of the entity.

        /**
         * @brief Construct a new ScaleComponent object
         *
         * @param scale Initial scale factor of the entity (default is 1.0f).
         */
        ScaleComponent(float scale = 1.0f);
};
