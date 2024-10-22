/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CallBackComponent.hpp
*/

#pragma once

#include <functional>

#include "IComponent.hpp"
#include "Registry.hpp"

/**
 * @brief Component CallBack for R-Type Game.
 *
 */
class CallBackComponent : public AComponent {

    public:

        std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback; /*!< The callback function. */

        /**
         * @brief Construct a new CallBack Component object.
         *
         * @param callback The callback function.
         */
        CallBackComponent(std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback);
};
