/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** UpdateConsumptionSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class UpdateConsumptionSystem : public ASystem {

    public:

        /**
         * @brief Construct a new UpdateConsumption System object.
         *
         */
        UpdateConsumptionSystem();

        /**
         * @brief Destroy the UpdateConsumption System object.
         *
         */
        ~UpdateConsumptionSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleUpdateConsumption(reg, idxPacketEntities);
            };
        }

    private:

        void _handleUpdateConsumption(ECS::Registry& reg, int idxPacketEntities); //< Function to handle mouse events.
};
