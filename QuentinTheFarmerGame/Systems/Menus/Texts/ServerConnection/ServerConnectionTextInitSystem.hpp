/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ServerConnectionTextInitSystem.hpp
*/

#pragma once

#include "ATextInitSystem.hpp"
#include "ISystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Texts/serverConnectionTextSystem.json"

/**
 * @brief ServerConnectionTextInitSystem class
 *
 */
class ServerConnectionTextInitSystem : public ATextInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new ServerConnectionTextInitSystem object
         *
         */
        ServerConnectionTextInitSystem();

        /**
         * @brief Destroy the ServerConnectionTextInitSystem object
         *
         */
        ~ServerConnectionTextInitSystem() = default;

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
