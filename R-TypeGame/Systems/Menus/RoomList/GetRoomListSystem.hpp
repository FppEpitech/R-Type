/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GetRoomListSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

#define SEND_ROOMS_INFOS "SendRoomsInfos"

/**
 * @brief GetRoomListSystem class
 *
 */
class GetRoomListSystem : public ASystem {

    public:

        /**
         * @brief Construct a new GetRoomListSystem object
         *
         */
        GetRoomListSystem();

        /**
         * @brief Destroy the GetRoomListSystem object
         *
         */
        ~GetRoomListSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry &reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _getRoomListSystem(reg, idxPacketEntities);
            };
        }

    private:

        void _getRoomListSystem(ECS::Registry& reg, int idxPacketEntities); //< Function to get the room list.
};
