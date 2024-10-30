/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginTextInitSystem.hpp
*/

#pragma once

#include "ATextInitSystem.hpp"
#include "ISystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Texts/loginTextSystem.json"

/**
 * @brief LoginTextInitSystem class
 *
 */
class LoginTextInitSystem : public ATextInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new LoginTextInitSystem object
         *
         */
        LoginTextInitSystem();

        /**
         * @brief Destroy the LoginTextInitSystem object
         *
         */
        ~LoginTextInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry &reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initText(reg, idxPacketEntities);
            };
        }

    private:

        void _initText(ECS::Registry& reg, int idxPacketEntities); //< Function to init the text.
};
