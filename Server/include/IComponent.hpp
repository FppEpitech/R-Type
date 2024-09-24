/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** IComponent
*/

#pragma once

#include <string>

/**
 * @brief Interface class for ECS components.
 *
 */
class IComponent {

    public:

        /**
         * @brief Destroy the IComponent object.
         *
         */
        virtual ~IComponent() = default;

        /**
         * @brief Get the Type object.
         *
         * @return const std::string&
         */
        virtual const std::string &getType() = 0;
};
