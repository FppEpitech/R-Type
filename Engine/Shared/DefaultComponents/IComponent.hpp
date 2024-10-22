/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** IComponent
*/

#pragma once

#include <string>

#include "../../Error/AError.hpp"

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

/**
 * @class AComponent
 * @brief A basic implementation of the IComponent interface.
 *
 * This class provides a basic implementation of the IComponent interface,
 * firstly for the function getType() which returns the type of the component.
 * And so who is the same for all components.
 */
class AComponent : public IComponent {
    public:
        /**
         * @brief Construct a new AComponent object.
         *
         * @param type The type of the component.
         */
        AComponent(std::string type) : _type(type) {}

        /**
         * @brief Destroy the AComponent object.
         */
        ~AComponent() = default;

        /**
         * @brief Get the type of the component.
         *
         * @return const std::string& The type of the component.
         */
        const std::string &getType() override { return _type; }

    private:
        std::string _type; //< The type identifier for this component.
};

/**
 * @brief Error for components
 *
 */
class ComponentError : public AError {

public:
    /**
     * @brief Construct a new ComponentError object
     *
     * @param message Error message
     */
    ComponentError(const std::string &message) : AError(message) {}
};
