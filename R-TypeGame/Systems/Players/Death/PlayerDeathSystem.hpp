/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlayerDeathSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief PlayerDeathSystem class
 *
 */
class PlayerDeathSystem : public ASystem {

    public:

        /**
         * @brief Construct a new PlayerDeathSystem object
         *
         */
        PlayerDeathSystem();

        /**
         * @brief Destroy the PlayerDeathSystem object
         *
         */
        ~PlayerDeathSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry &reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _playerDeathSystem(reg, idxPacketEntities);
            };
        }

    private:

        void _playerDeathSystem(ECS::Registry& reg, int idxPacketEntities); //< Function to check if a player is dead.
};
