/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEvent.hpp
*/

#pragma once

#include <any>
#include <string>
#include <vector>

/**
 * @brief Interface for an event
 *
 */
class IEvent {

    public:

        /**
         * @brief Destroy the IEvent object
         *
         */
        virtual ~IEvent() = default;

        /**
         * @brief Get the type of the event
         *
         * @return std::string The type of the event
         */
         virtual std::string getEventType() const = 0;

         /**
           * @brief Set the type of the event
           *
           * @param type Type of the event
         */
         virtual void setEventType(std::string type) = 0;

         /**
          * @brief Get the values of the event
          *
          * @return std::vector<std::any> The values of the event
          */
         virtual std::vector<std::any> getValues() const = 0;

         /**
           * @brief Set the values of the event
           *
           * @param values The values of the event
           */
          virtual void setValues(std::vector<std::any> values) = 0;

          /**
           * @brief Add a value to the event
           *
           * @param value Value to add
           */
          virtual void addValue(std::any value) = 0;
};
