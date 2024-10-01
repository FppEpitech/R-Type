/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** ISystem
*/

#pragma once

#include <string>
#include <functional>

#include "../Ecs/Src/Registry.hpp"

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
         * @brief Get the Type object.
         *
         * @return const std::string&
         */
        virtual const std::string &getType() = 0;

        /**
         * @brief Get the Function of the System.
         *
         * @return std::function<void(Registry& reg)> System's function.
         */
        virtual std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction() = 0;
};

/**
 * @class ASystem
 * @brief A basic implementation of the ASystem interface.
 *
 * This class provides a basic implementation of the ASystem interface,
 * firstly for the function getType() which returns the type of the component.
 * And so who is the same for all components.
 */
class ASystem : public ISystem {
    public:
        /**
         * @brief Construct a new ASystem object.
         *
         * @param type The type of the component.
         */
        ASystem(std::string type) : _type(type) {}

        /**
         * @brief Destroy the ASystem object.
         */
        ~ASystem() = default;

        /**
         * @brief Get the type of the component.
         *
         * @return const std::string& The type of the component.
         */
        const std::string &getType() override
        {
            return _type;
        }

    private:
        std::string _type; //< The type identifier for this component.
};
