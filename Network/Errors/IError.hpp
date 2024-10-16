/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Network IError
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

/**
 * @brief Abstract class for error handling
 *
 */
class AError : public IError {

    public:

        /**
         * @brief Construct a new AError object
         *
         */
        AError(const std::string &message) : _message(message) {}

        /**
         * @brief Destroy the AError object
         *
         */
        virtual ~AError() = default;

        /**
         * @brief Get the error message
         *
         * @return const char* Error message
         */
        virtual const char *what() const noexcept override { return _message.c_str(); }

    private:

        std::string _message; // Error message
};
