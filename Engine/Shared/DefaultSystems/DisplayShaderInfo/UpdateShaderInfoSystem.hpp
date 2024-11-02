/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** UpdateShaderInfoSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class UpdateShaderInfoSystem : public ASystem {

    public:

        /**
         * @brief Construct a new UpdateShaderInfo System object.
         *
         */
        UpdateShaderInfoSystem();

        /**
         * @brief Destroy the UpdateShaderInfo System object.
         *
         */
        ~UpdateShaderInfoSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleUpdateShaderInfo(reg, idxPacketEntities);
            };
        }

    private:

        void _handleUpdateShaderInfo(ECS::Registry& reg, int idxPacketEntities); //< Function to handle mouse events.
};
