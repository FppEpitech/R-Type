/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AccountManagementTextInitSystem.hpp
*/

#pragma once

#include "ATextInitSystem.hpp"
#include "ISystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Texts/accountManagementTextSystem.json"

/**
 * @brief AccountManagementTextInitSystem class
 *
 */
class AccountManagementTextInitSystem : public ATextInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new AccountManagementTextInitSystem object
         *
         */
        AccountManagementTextInitSystem();

        /**
         * @brief Destroy the AccountManagementTextInitSystem object
         *
         */
        ~AccountManagementTextInitSystem() = default;

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
