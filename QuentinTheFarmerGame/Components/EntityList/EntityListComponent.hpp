/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** EntityListComponent
*/

#pragma once

#include <vector>

#include "IComponent.hpp"

/**
 * @brief Component Entity List for R-Type Game.
 *
 */
class EntityListComponent : public AComponent {

    public:

        std::vector<std::size_t> entities; // List of entities.
        std::string listType; // Type of the list.

        /**
         * @brief Construct a new Entity List Component object.
         *
         * @param entities List of entities.
         */
        EntityListComponent(std::vector<std::size_t> entities = {}, std::string listType = "");
};
