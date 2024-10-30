/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClickableComponent.hpp
*/

#pragma once

#include <functional>

#include "IComponent.hpp"
#include "Registry.hpp"

/**
 * @brief Component Clickable for R-Type Game.
 *
 */
class ClickableComponent : public AComponent {

    public:

        std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback; /*!< The callback function. */

        /**
         * @brief Construct a new Clickable Component object.
         *
         * @param callback The callback function.
         */
        ClickableComponent(std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback);
};
