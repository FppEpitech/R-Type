/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IError
*/

#pragma once

#include <exception>
#include <string>

/**
 * @brief Interface for error handling
 *
 */
class IError : public std::exception {

    public:

        /**
         * @brief Construct a new IError object
         *
         */
        virtual ~IError() = default;

        /**
         * @brief Get the error message
         *
         * @return const char* Error message
         */
        virtual const char *what() const noexcept = 0;
};
