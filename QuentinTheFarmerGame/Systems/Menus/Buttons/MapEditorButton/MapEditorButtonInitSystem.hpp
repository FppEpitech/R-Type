/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MapEditorButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"
#include "AButtonInitSystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/mapEditorButtonSystem.json"

/**
 * @brief MapEditorButtonInitSystem class
 *
 */
class MapEditorButtonInitSystem : public AButtonInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new MapEditorButtonInitSystem object
         *
         */
        MapEditorButtonInitSystem();

        /**
         * @brief Destroy the MapEditorButtonInitSystem object
         *
         */
        ~MapEditorButtonInitSystem() = default;

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