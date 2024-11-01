/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** EntityIdComponent
*/

#pragma once

#include <vector>

#include "IComponent.hpp"

/**
 * @brief Component Entity Id for R-Type Game.
 *
 */
class EntityIdComponent : public AComponent {

    public:

        int id;

        /**
         * @brief Construct a new Entity Id Component object.
         *
         * @param id The id of the entity.
         */
        EntityIdComponent(int id = -1);
};
