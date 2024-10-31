/*
** EPITECH PROJECT, 2024
** MobSpeOneShootInitSystem
** File description:
** MobSpeOneShootInitSystem
*/

#pragma once

#include <iostream>

#include "ISystem.hpp"

/**
 * @brief Initialize a shoot entity.
 *
 */
class MobSpeOneShootInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Shoot Init System object.
         *
         */
        MobSpeOneShootInitSystem();

        /**
         * @brief Destroy the Shoot Init System object.
         *
         */
        ~MobSpeOneShootInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initShoot(reg, idxPacketEntities);
            };
        }

    private:

        void _initShoot(ECS::Registry& reg, int idxPacketEntities); //< Function to init the Shoot.
};