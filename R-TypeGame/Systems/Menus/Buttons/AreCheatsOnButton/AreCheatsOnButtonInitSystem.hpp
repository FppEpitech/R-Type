/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AreCheatsOnButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/areCheatsOnButtonSystem.json"

/**
 * @brief AreCheatsOnButtonInitSystem class
 *
 */
class AreCheatsOnButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new AreCheatsOnButtonInitSystem object
         *
         */
        AreCheatsOnButtonInitSystem();

        /**
         * @brief Destroy the AreCheatsOnButtonInitSystem object
         *
         */
        ~AreCheatsOnButtonInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry &reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initButton(reg, idxPacketEntities);
            };
        }

    private:

        void _initButton(ECS::Registry& reg, int idxPacketEntities); //< Function to init the button.
};
