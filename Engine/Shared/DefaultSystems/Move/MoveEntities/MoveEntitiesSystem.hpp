/*
** EPITECH PROJECT, 2024
** MoveEntitiesSystem
** File description:
** MoveEntitiesSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"
/**
 * @brief Move all entities based on their positions and velocity.
 *
 */
class MoveEntitiesSystem : public ASystem {

    public:

        /**
         * @brief Construct a new MoveEntities System object.
         *
         */
        MoveEntitiesSystem();

        /**
         * @brief Destroy the MoveEntities System object.
         *
         */
        ~MoveEntitiesSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _moveEntities(reg, idxPacketEntities);
            };
        }

    private:

        void _moveEntities(ECS::Registry& reg, int idxPacketEntities); //< Function to Move Entities.
};
