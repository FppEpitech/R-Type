/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ABIError
*/

#pragma once

#include "IError.hpp"

/**
 * @brief Abstract class for ABI errors.
 *
 */
class ABIError : public AError {

    public:

        /**
         * @brief Construct a new ABIError object.
         *
         */
        ABIError(const std::string &message) : AError(message) {}

        /**
         * @brief Destroy the ABIError object.
         *
         */
        ~ABIError() = default;
};