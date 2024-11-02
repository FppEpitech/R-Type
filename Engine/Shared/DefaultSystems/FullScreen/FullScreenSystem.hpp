/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** FullScreenSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class FullScreenSystem : public ASystem {

    public:

        /**
         * @brief Construct a new UpdateConsumption System object.
         *
         */
        FullScreenSystem();

        /**
         * @brief Destroy the UpdateConsumption System object.
         *
         */
        ~FullScreenSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleFullScreen(reg, idxPacketEntities);
            };
        }

    private:

        void _handleFullScreen(ECS::Registry& reg, int idxPacketEntities); //< Function to handle full screen.
};
