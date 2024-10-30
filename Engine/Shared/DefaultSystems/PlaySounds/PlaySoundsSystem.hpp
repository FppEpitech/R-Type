/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlaySoundsSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class PlaySoundsSystem : public ASystem {

    public:

        /**
         * @brief Construct a new PlaySounds System object.
         *
         */
        PlaySoundsSystem();

        /**
         * @brief Destroy the PlaySounds System object.
         *
         */
        ~PlaySoundsSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handlePlaySounds(reg, idxPacketEntities);
            };
        }

    private:

        void _handlePlaySounds(ECS::Registry& reg, int idxPacketEntities); //< Function to handle mouse events.
};
