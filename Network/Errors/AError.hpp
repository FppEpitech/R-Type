/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Network AError
*/

#pragma once

#include "IError.hpp"

/**
 * @brief Abstract class for error handling
 *
 */
class AError : public IErrorNetwork {

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
        const char *what() const noexcept { return _message.c_str(); }

    private:

        std::string _message; // Error message
};
