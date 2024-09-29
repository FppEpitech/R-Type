/*
** EPITECH PROJECT, 2024
** Size1DComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IComponent.hpp"

/**
 * @class Size1DComponent
 * @brief Component for handling size in one dimension within the graphical engine.
 *
 * This component is used to store and manage the size of entities in one dimension.
 * For example, the size in pixels of a text.
 *
 * @var size The size of the entity in one dimension.
 */
class Size1DComponent : public AComponent {
    public:

        size_t size; //< The size of the entity in one dimension.

        /**
         * @brief Construct a new Size1DComponent object
         *
         * @param size Initial size of the entity (default is 0).
         */
        Size1DComponent(size_t size = 0);
};
