/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** exitButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/exitButtonSystem.json"

/**
 * @brief ExitButtonInitSystem class
 *
 */
class ExitButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new ExitButtonInitSystem object
         *
         */
        ExitButtonInitSystem();

        /**
         * @brief Destroy the ExitButtonInitSystem object
         *
         */
        ~ExitButtonInitSystem() = default;

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
