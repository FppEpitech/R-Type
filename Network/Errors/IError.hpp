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
 * @brief Interface for error handling.
 *
 */
class IErrorNetwork : public std::exception {

    public:

        /**
         * @brief Construct a new IErrorNetwork object.
         *
         */
        virtual ~IErrorNetwork() = default;

        /**
         * @brief Get the error message.
         *
         * @return const char* Error message.
         */
        virtual const char *what() const noexcept = 0;
};

/**
 * @brief Abstract class for error handling.
 *
 */
class AErrorNetwork : public IErrorNetwork {

    public:

        /**
         * @brief Construct a new AErrorNetwork object.
         *
         */
        AErrorNetwork(const std::string &message) : _message(message) {}

        /**
         * @brief Destroy the AErrorNetwork object.
         *
         */
        virtual ~AErrorNetwork() = default;

        /**
         * @brief Get the error message.
         *
         * @return const char* Error message.
         */
        virtual const char *what() const noexcept override { return _message.c_str(); }

    private:

        std::string _message; // Error message.
};
