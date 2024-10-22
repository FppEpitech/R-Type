/*
** EPITECH PROJECT, 2024
** HitboxPlayerSystem
** File description:
** HitboxPlayerSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"
/**
 * @brief Handle hitbox for players.
 *
 */
class HitboxPlayerSystem : public ASystem {

    public:

        /**
         * @brief Construct a new HitboxPlayer System object.
         *
         */
        HitboxPlayerSystem();

        /**
         * @brief Destroy the HitboxPlayer System object.
         *
         */
        ~HitboxPlayerSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _hitboxPlayer(reg, idxPacketEntities);
            };
        }

    private:

        void _hitboxPlayer(ECS::Registry& reg, int idxPacketEntities); //< Function to handle players hitbox.
};
