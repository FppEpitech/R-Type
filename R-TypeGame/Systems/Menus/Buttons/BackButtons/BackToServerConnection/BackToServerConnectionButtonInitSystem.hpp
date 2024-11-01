/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** BackToServerConnectionButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/backButtonSystem.json"
#define BACK_TO_SERVER_CONNECTION "Menus/serverConnectionMenu.json"

/**
 * @brief BackToServerConnectionButtonInitSystem class
 *
 */
class BackToServerConnectionButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new BackToServerConnectionButtonInitSystem object
         *
         */
        BackToServerConnectionButtonInitSystem();

        /**
         * @brief Destroy the BackToServerConnectionButtonInitSystem object
         *
         */
        ~BackToServerConnectionButtonInitSystem() = default;

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
