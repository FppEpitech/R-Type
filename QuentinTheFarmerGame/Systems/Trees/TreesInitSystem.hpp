/*
** EPITECH PROJECT, 2024
** TreeInitSystem
** File description:
** TreeInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a tree entity.
 *
 */
class TreeInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Tree Init System object.
         *
         */
        TreeInitSystem();

        /**
         * @brief Destroy the Tree Init System object.
         *
         */
        ~TreeInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initTree(reg, idxPacketEntities);
            };
        }

    private:

        void _initTree(ECS::Registry& reg, int idxPacketEntities); //< Function to init the player.
};
