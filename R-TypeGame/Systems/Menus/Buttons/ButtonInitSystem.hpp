/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonInitSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief Initialize a button entity.
 * Set position, scale, texture rect, a text, a font, a state and a callback.
 */
class ButtonInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new Button Init System object.
         *
         */
        ButtonInitSystem();

        /**
         * @brief Destroy the Button Init System object.
         *
         */
        ~ButtonInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initButton(reg, idxPacketEntities);
            };
        }

    private:

        void _initButton(ECS::Registry& reg, int idxPacketEntities); //< Function to init the button.
};