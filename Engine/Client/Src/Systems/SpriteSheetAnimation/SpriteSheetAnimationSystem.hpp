/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationSystem
** File description:
** SpriteSheetAnimationSystem
*/

#pragma once

#include <iostream>

#include "../../../../Shared/DefaultSystems/ISystem.hpp"

/**
 * @brief System to handle sprite sheet animation
 *
 */
class SpriteSheetAnimationSystem : public ASystem {

    public:

        /**
         * @brief Construct a new SpriteSheetAnimation System object.
         *
         */
        SpriteSheetAnimationSystem();

        /**
         * @brief Destroy the SpriteSheetAnimation System object.
         *
         */
        ~SpriteSheetAnimationSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _spriteSheetAnimation(reg, idxPacketEntities);
            };
        }

    private:

        void _spriteSheetAnimation(ECS::Registry& reg, int idxPacketEntities); //< Function anime a sprite sheet.
};
