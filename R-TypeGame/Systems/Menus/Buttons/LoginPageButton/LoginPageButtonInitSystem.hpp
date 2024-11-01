/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginPageButtonInitSystem.hpp
*/

#pragma once

#include "../../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../AButton/AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/loginPageButtonSystem.json"
#define LOGIN_PAGE "Menus/loginMenu.json"

/**
 * @brief LoginPageButtonInitSystem class
 *
 */
class LoginPageButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new LoginPageButtonInitSystem object
         *
         */
        LoginPageButtonInitSystem();

        /**
         * @brief Destroy the LoginPageButtonInitSystem object
         *
         */
        ~LoginPageButtonInitSystem() = default;

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
