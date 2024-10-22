/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MultiplayerButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/multiplayerButtonSystem.json"

/**
 * @brief MultiplayerButtonInitSystem class
 *
 */
class MultiplayerButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new MultiplayerButtonInitSystem object
         *
         */
        MultiplayerButtonInitSystem();

        /**
         * @brief Destroy the MultiplayerButtonInitSystem object
         *
         */
        ~MultiplayerButtonInitSystem() = default;

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
