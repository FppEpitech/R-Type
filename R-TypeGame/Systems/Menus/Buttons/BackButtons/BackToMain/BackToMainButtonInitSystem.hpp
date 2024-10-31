/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** BackToMainButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define JSON_CONFIG_PATH "GameData/Scenes/Menus/Buttons/backButtonSystem.json"
#define BACK_TO_MAIN "Menus/mainMenu.json"

/**
 * @brief BackToMainButtonInitSystem class
 *
 */
class BackToMainButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new BackToMainButtonInitSystem object
         *
         */
        BackToMainButtonInitSystem();

        /**
         * @brief Destroy the BackToMainButtonInitSystem object
         *
         */
        ~BackToMainButtonInitSystem() = default;

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
