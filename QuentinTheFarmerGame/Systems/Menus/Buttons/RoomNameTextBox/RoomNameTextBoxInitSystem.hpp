/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomNameTextBoxInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/roomNameTextBoxSystem.json"

class RoomNameTextBoxInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new RoomNameTextBoxInitSystem object
         *
         */
        RoomNameTextBoxInitSystem();

        /**
         * @brief Destroy the RoomNameTextBoxInitSystem object
         *
         */
        ~RoomNameTextBoxInitSystem() = default;

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
