/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomManagementTextInitSystem.hpp
*/

#pragma once

#include "../../../AText/ATextInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultSystems/ISystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Texts/roomManagementTextSystem.json"

/**
 * @brief RoomManagementTextInitSystem class
 *
 */
class RoomManagementTextInitSystem : public ATextInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new RoomManagementTextInitSystem object
         *
         */
        RoomManagementTextInitSystem();

        /**
         * @brief Destroy the RoomManagementTextInitSystem object
         *
         */
        ~RoomManagementTextInitSystem() = default;

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
