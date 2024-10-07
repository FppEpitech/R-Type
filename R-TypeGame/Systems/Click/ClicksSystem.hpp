/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClicksSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle clicks.
 */
class ClicksSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Click System object.
         *
         */
        ClicksSystem();

        /**
         * @brief Destroy the Click System object.
         *
         */
        ~ClicksSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleClicks(reg, idxPacketEntities);
            };
        }

    private:

        void _handleClicks(ECS::Registry& reg, int idxPacketEntities); //< Function to handle clicks.
};
