/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** EditableComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

/**
 * @brief Editable component.
 */
class EditableComponent : public AComponent {
    public:

        bool _isEditable; //< Is editable.

        /**
         * @brief Construct a new Editable Component object.
         *
         * @param isEditable
         */
        EditableComponent(bool isEditable = true);
};
