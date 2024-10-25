/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomPageButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/joinRoomPageButtonSystem.json"

/**
 * @brief JoinRoomPageButtonInitSystem class
 *
 */
class JoinRoomPageButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new JoinRoomPageButtonInitSystem object
         *
         */
        JoinRoomPageButtonInitSystem();

        /**
         * @brief Destroy the JoinRoomPageButtonInitSystem object
         *
         */
        ~JoinRoomPageButtonInitSystem() = default;

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
