/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientErrors
*/

#pragma once

#include "../../../Error/AError.hpp"

/**
 * @brief Abstract class for client errors.
 *
 */
class ClientError : public AError {

    public:

        /**
         * @brief Construct a new ClientError object.
         *
         */
        ClientError(const std::string &message) : AError(message) {}

        /**
         * @brief Destroy the ClientError object.
         *
         */
        ~ClientError() = default;
};
