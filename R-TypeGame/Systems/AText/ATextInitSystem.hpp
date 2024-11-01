/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AText.hpp
*/

#pragma once

#include "../../../Engine/Ecs/Src/Registry.hpp"

class ATextInitSystem {

    public:

        /**
         * @brief Construct a new ATextInitSystem object
         *
         */
        ATextInitSystem() = default;

        /**
         * @brief Destroy the ATextInitSystem object
         *
         */
        ~ATextInitSystem() = default;

    protected:

        /**
         * @brief Set the Text Properties object
         *
         * @param reg The registry to fill
         * @param idxPacketEntities The index of the packet entities
         * @param filePath The path to the json file
         */
        void _setTextProperties(ECS::Registry &reg, int idxPacketEntities, const std::string &filePath);
};