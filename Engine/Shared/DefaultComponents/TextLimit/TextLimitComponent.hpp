/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TextLimitComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

/**
* @brief TextLimitComponent class, used to limit the number of characters in a text
 *
*/
class TextLimitComponent : public AComponent {
    public:

        std::size_t limit; /*!< The limit of characters in the text */

        /**
         * @brief Construct a new Text Limit Component object
         *
         * @param limit
         */
        TextLimitComponent(std::size_t limit);

        /**
         * @brief Destroy the Text Limit Component object
         *
         */
        ~TextLimitComponent() = default;
};
