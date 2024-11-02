/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShaderSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle mouse events.
 */
class ShaderSystem : public ASystem {

    public:

        /**
         * @brief Construct a new UpdateConsumption System object.
         *
         */
        ShaderSystem();

        /**
         * @brief Destroy the UpdateConsumption System object.
         *
         */
        ~ShaderSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleShader(reg, idxPacketEntities);
            };
        }

    private:

        void _handleShader(ECS::Registry& reg, int idxPacketEntities); //< Function to handle shader
};
