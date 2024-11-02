/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginCheckSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#define LOGIN "Menus/roomManagementMenu.json"


/**
 * @brief LoginCheckSystem class
 *
 */
class LoginCheckSystem : public ASystem {

    public:

        /**
         * @brief Construct a new LoginCheckSystem object
         *
         */
        LoginCheckSystem();

        /**
         * @brief Destroy the LoginCheckSystem object
         *
         */
        ~LoginCheckSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry &reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _loginCheckSystem(reg, idxPacketEntities);
            };
        }

    private:

        void _loginCheckSystem(ECS::Registry& reg, int idxPacketEntities); //< Function to check the login.
};
