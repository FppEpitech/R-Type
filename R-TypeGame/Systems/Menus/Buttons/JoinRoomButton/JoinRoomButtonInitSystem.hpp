/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomButtonInitSystem.hpp
*/

#pragma once

#include "AButtonInitSystem.hpp"

#define JSON_PATH "GameData/Scenes/Menus/Buttons/joinRoomButtonSystem.json"

/**
 * @brief JoinRoomButtonInitSystem class
 *
 */
class JoinRoomButtonInitSystem : public AButtonInitSystem {

    public:

        /**
         * @brief Construct a new JoinRoomButtonInitSystem object
         *
         * @param reg The entity-component-system registry
         * @param idxPacketEntities The index of the packet entities
         * @param roomId The id of the room
         */
        JoinRoomButtonInitSystem(ECS::Registry &reg, int idxPacketEntities, std::size_t roomId);

        /**
         * @brief Destroy the JoinRoomButtonInitSystem object
         *
         */
        ~JoinRoomButtonInitSystem() = default;
};
