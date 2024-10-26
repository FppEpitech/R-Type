/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ConnectButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/connectButtonSystem.json"
#define ACCOUNT_MANAGEMENT "Menus/accountManagementMenu.json"

/**
 * @brief ConnectButtonInitSystem class
 *
 */
class ConnectButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new ConnectButtonInitSystem object
         *
         */
        ConnectButtonInitSystem();

        /**
         * @brief Destroy the ConnectButtonInitSystem object
         *
         */
        ~ConnectButtonInitSystem() = default;

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
