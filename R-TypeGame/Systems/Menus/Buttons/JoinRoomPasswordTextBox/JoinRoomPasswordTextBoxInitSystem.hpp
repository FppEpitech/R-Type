/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomPasswordTextBoxInitSystem.hpp
*/

#pragma once

#include "AButtonInitSystem.hpp"

#define CONFIG_PATH "GameData/Scenes/Menus/Buttons/joinRoomPasswordTextBoxSystem.json"

class JoinRoomPasswordTextBoxInitSystem : public AButtonInitSystem {

    public:

        /**
         * @brief Construct a new JoinRoomPasswordTextBoxInitSystem object
         **
         * @param reg The entity-component-system registry
         * @param idxPacketEntities The index of the packet entities
         * @param roomId The id of the room
         */
        JoinRoomPasswordTextBoxInitSystem(ECS::Registry &reg, int idxPacketEntities, std::size_t roomId);

        /**
         * @brief Destroy the JoinRoomPasswordTextBoxInitSystem object
         *
         */
        ~JoinRoomPasswordTextBoxInitSystem() = default;
};
