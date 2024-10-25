/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RegisterTextInitSystem.hpp
*/

#pragma once

#include "ATextInitSystem.hpp"
#include "ISystem.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Texts/registerTextSystem.json"

/**
 * @brief RegisterTextInitSystem class
 *
 */
class RegisterTextInitSystem : public ATextInitSystem, public ASystem {

    public:

        /**
         * @brief Construct a new RegisterTextInitSystem object
         *
         */
        RegisterTextInitSystem();

        /**
         * @brief Destroy the RegisterTextInitSystem object
         *
         */
        ~RegisterTextInitSystem() = default;

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
