/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MouseSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class MouseSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Mouse System object.
         *
         */
        MouseSystem();

        /**
         * @brief Destroy the Mouse System object.
         *
         */
        ~MouseSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleMouse(reg, idxPacketEntities);
            };
        }

    private:

        void _handleMouse(ECS::Registry& reg, int idxPacketEntities); //< Function to handle mouse events.
};
