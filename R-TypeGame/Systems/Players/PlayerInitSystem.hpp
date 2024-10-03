/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a player entity.
 * Set life, position and asset path.
 *
 */
class PlayerInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Player Init System object.
         *
         */
        PlayerInitSystem();

        /**
         * @brief Destroy the Player Init System object.
         *
         */
        ~PlayerInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initPlayer(reg, idxPacketEntities);
            };
        }

    private:

        void _initPlayer(ECS::Registry& reg, int idxPacketEntities); //< Function to init the player.
};
