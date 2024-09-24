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
 *  A component is a modular piece of data that defines
 *  specific attributes or behaviors of an entity.
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
