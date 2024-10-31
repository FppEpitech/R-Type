/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomListInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief RoomListInitSystem class
 *
 */
class RoomListInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new RoomListInitSystem object
         *
         */
        RoomListInitSystem();

        /**
         * @brief Destroy the RoomListInitSystem object
         *
         */
        ~RoomListInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry &reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initRoomList(reg, idxPacketEntities);
            };
        }

    private:

        void _initRoomList(ECS::Registry& reg, int idxPacketEntities); //< Function to init the button.
};
