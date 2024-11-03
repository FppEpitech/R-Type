/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SingleplayerButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/singleplayerButtonSystem.json"
#define FIRST_GAME_SCENE "firstScene.json"

/**
 * @brief SingleplayerButtonInitSystem class
 *
 */
class SingleplayerButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new SingleplayerButtonInitSystem object
         *
         */
        SingleplayerButtonInitSystem();

        /**
         * @brief Destroy the SingleplayerButtonInitSystem object
         *
         */
        ~SingleplayerButtonInitSystem() = default;

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
