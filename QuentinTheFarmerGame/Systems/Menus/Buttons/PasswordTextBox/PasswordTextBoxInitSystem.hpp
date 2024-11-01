/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PasswordTextBoxInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/passwordTextBoxSystem.json"

class PasswordTextBoxInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new PasswordTextBoxInitSystem object
         *
         */
        PasswordTextBoxInitSystem();

        /**
         * @brief Destroy the PasswordTextBoxInitSystem object
         *
         */
        ~PasswordTextBoxInitSystem() = default;

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
