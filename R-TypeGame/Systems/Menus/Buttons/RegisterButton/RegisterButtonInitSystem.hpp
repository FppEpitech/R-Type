/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RegisterButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/registerButtonSystem.json"
#define REGISTER "Menus/accountManagementMenu.json"

/**
 * @brief RegisterButtonInitSystem class
 *
 */
class RegisterButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new RegisterButtonInitSystem object
         *
         */
        RegisterButtonInitSystem();

        /**
         * @brief Destroy the RegisterButtonInitSystem object
         *
         */
        ~RegisterButtonInitSystem() = default;

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
