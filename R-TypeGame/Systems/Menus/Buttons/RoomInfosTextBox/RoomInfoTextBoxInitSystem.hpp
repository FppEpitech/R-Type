/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomInfoTextBoxInitSystem.hpp
*/

#pragma once

#include "Registry.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/roomInfoTextBoxSystem.json"

/**
 * @brief RoomInfoTextBoxInitSystem class
 *
 */
class RoomInfoTextBoxInitSystem {

    public:

        /**
         * @brief Construct a new RoomInfoTextBoxInitSystem object
         *
         * @param reg The entity-component-system registry
         * @param idxPacketEntities The index of the packet entities
         * @param pathJson The path to the json file
         */
        RoomInfoTextBoxInitSystem(ECS::Registry &reg, int idxPacketEntities, const std::string &pathJson);

        /**
         * @brief Destroy the RoomInfoTextBoxInitSystem object
         *
         */
        ~RoomInfoTextBoxInitSystem() = default;
};
