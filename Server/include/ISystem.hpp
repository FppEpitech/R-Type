/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** ISystem
*/

#pragma once

#include <string>
#include <functional>

#include "../../Ecs/src/Registry.hpp"

/**
 * @brief Interface class for ECS systems.
 *
 */
class ISystem {

    public:

        /**
         * @brief Destroy the ISystem object.
         *
         */
        virtual ~ISystem() = default;

        /**
         * @brief Get the Type object
         *
         * @return const std::string&
         */
        virtual const std::string &getType() = 0;

        /**
         * @brief Get the Function of the System.
         *
         * @return std::function<void(Registry& reg)> System's function.
         */
        virtual std::function<void(ECS::Registry& reg)> getFunction() = 0;
};
