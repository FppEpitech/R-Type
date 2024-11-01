/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** PlayerComponent
*/

#pragma once

#include <cstdint>

#include "IComponent.hpp"

/**
 * @brief Component PlayerComponent for R-Type Game.
 *
 */
class PlayerComponent : public AComponent {

    public:

        uint32_t token; // Token of player.
        bool isAlive; // Is player alive.

        /**
         * @brief Construct a new PlayerComponent Component object.
         *
         * @param token of player.
         * @param isAlive of player.
         */
        PlayerComponent(uint32_t token = 0x00000000, bool isAlive = true);
};
