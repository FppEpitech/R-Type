/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RegisterPageButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/registerPageButtonSystem.json"
#define REGISTER_PAGE "Menus/registerMenu.json"

/**
 * @brief RegisterPageButtonInitSystem class
 *
 */
class RegisterPageButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new RegisterPageButtonInitSystem object
         *
         */
        RegisterPageButtonInitSystem();

        /**
         * @brief Destroy the RegisterPageButtonInitSystem object
         *
         */
        ~RegisterPageButtonInitSystem() = default;

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
