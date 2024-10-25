/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** DbError
*/

#pragma once

#include "AError.hpp"

/**
 * @brief Abstract class for Db errors.
 *
 */
class DbError : public AError {

    public:

        /**
         * @brief Construct a new DbError object.
         *
         */
        DbError(const std::string &message) : AError(message) {}

        /**
         * @brief Destroy the DbError object.
         *
         */
        ~DbError() = default;
};
