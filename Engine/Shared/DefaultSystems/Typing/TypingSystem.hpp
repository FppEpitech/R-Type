/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TypingSystem.hpp
*/

#pragma once

#include "ISystem.hpp"

/**
 * @brief System to handle typing.
 */
class TypingSystem : public ASystem {
    public:

        /**
         * @brief Construct a new Typing System object.
         */
        TypingSystem();

        /**
         * @brief Destroy the Typing System object.
         */
        ~TypingSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _handleTyping(reg, idxPacketEntities);
            };
        }

    private:

        void _handleTyping(ECS::Registry& reg, int idxPacketEntities); //< Function to handle typing.

        /**
         * @brief Check if the key is printable.
         * @param input The input to check.
         * @return true if the key is printable.
         * @return false if the key is not printable.
         */
        bool _isKeyPrintable(size_t input);
};