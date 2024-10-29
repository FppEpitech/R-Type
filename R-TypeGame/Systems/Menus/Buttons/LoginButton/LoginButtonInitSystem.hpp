/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginButtonInitSystem.hpp
*/

#pragma once

#include "../../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../AButton/AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/loginButtonSystem.json"
#define LOGIN "Menus/roomManagementMenu.json"

/**
 * @brief LoginButtonInitSystem class
 *
 */
class LoginButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new LoginButtonInitSystem object
         *
         */
        LoginButtonInitSystem();

        /**
         * @brief Destroy the LoginButtonInitSystem object
         *
         */
        ~LoginButtonInitSystem() = default;

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
