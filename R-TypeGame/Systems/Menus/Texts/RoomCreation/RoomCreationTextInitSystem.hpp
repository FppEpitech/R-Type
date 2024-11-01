/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomCreationTextInitSystem.hpp
*/

#pragma once

#include "../../../AText/ATextInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultSystems/ISystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Texts/roomCreationTextSystem.json"

/**
 * @brief RoomCreationTextInitSystem class
 *
 */
class RoomCreationTextInitSystem : public ATextInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new RoomCreationTextInitSystem object
         *
         */
        RoomCreationTextInitSystem();

        /**
         * @brief Destroy the RoomCreationTextInitSystem object
         *
         */
        ~RoomCreationTextInitSystem() = default;

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
