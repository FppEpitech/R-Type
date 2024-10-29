/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateRoomPageButtonInitSystem.hpp
*/

#pragma once

#include "../../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../AButton/AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/createRoomPageButtonSystem.json"
#define CREATE_ROOM "Menus/roomCreationMenu.json"

/**
 * @brief CreateRoomPageButtonInitSystem class
 *
 */
class CreateRoomPageButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new CreateRoomPageButtonInitSystem object
         *
         */
        CreateRoomPageButtonInitSystem();

        /**
         * @brief Destroy the CreateRoomPageButtonInitSystem object
         *
         */
        ~CreateRoomPageButtonInitSystem() = default;

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
