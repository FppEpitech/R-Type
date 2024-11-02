/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** InitShaderInfoSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class InitShaderInfoSystem : public ASystem {

    public:

        /**
         * @brief Construct a new PlaySounds System object.
         *
         */
        InitShaderInfoSystem();

        /**
         * @brief Destroy the PlaySounds System object.
         *
         */
        ~InitShaderInfoSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleShaderInfo(reg, idxPacketEntities);
            };
        }

    private:

        void _handleShaderInfo(ECS::Registry& reg, int idxPacketEntities); //< Function to handle mouse events.
};
