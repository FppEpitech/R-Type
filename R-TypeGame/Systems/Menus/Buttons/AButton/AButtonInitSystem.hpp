/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AButtonIniSystem.hpp
*/

#pragma once

#include "ClickableComponent.hpp"

/**
 * @brief AButtonInitSystem class
 *
 */
class AButtonInitSystem {

    public:

        /**
         * @brief Construct a new AButtonInitSystem object
         *
         */
        AButtonInitSystem() = default;

        /**
         * @brief Destroy the AButtonInitSystem object
         *
         */
        ~AButtonInitSystem() = default;

    protected:

        /**
         * @brief Set the Button Proprieties object
         *
         * @param reg The registry to fill
         * @param idxPacketEntities The index of the packet entities
         * @param filePath The path to the json file
         * @param callback The callback to set
         */
        void _setButtonProprieties(ECS::Registry &reg, int idxPacketEntities, const std::string &filePath, std::function<void(ECS::Registry &reg, int idxPacketEntities)> callback);
};
