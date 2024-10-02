/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** PlayerComponent
*/

#pragma once

#include <cstdint>

#include "../../../Interface/IComponent.hpp"

/**
 * @brief Component PlayerComponent for R-Type Game.
 *
 */
class PlayerComponent : public AComponent {

    public:

        uint32_t token; // Token of player.

        /**
         * @brief Construct a new PlayerComponent Component object.
         *
         * @param token of player.
         */
        PlayerComponent(uint32_t token = 0x00000000);
};
