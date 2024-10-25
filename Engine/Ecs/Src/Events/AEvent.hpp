/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AEvent.hpp
*/

#pragma once

#include "IEvent.hpp"
#include "AError.hpp"

class AEvent : public IEvent {

    public:

        /**
         * @brief Construct a new AEvent object
         *
         * @param type Type of the event
         * @param values Values of the event
         */
        AEvent(std::string type, std::vector<std::any> values = {});

        /**
         * @brief Destroy the AEvent object
         *
         */
        ~AEvent() = default;

        /**
         * @brief Get the type of the event
         *
         * @return std::string The type of the event
         */
        std::string getEventType() const override;

        /**
         * @brief Set the type of the event
         *
         * @param type Type of the event
         */
        void setEventType(std::string type) override;

        /**
         * @brief Get the values of the event
         *
         * @return std::vector<std::any> The values of the event
         */
        std::vector<std::any> getValues() const override;

        /**
         * @brief Set the values of the event
         *
         * @param values The values of the event
         */
        void setValues(std::vector<std::any> values) override;

        /**
         * @brief Add a value to the event
         *
         * @param value Value to add
         */
        void addValue(std::any value) override;

    protected:

        std::string             _type; //!< Type of the event
        std::vector<std::any>   _values; //!< Values of the event
};

class EventError : public AError {

    public:

        /**
         * @brief Construct a new EventError object
         *
         * @param message Message of the error
         */
        EventError(std::string message) : AError(message) {}
};
