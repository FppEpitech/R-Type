/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ServerErrors
*/

#pragma once

#include "../../../../Error/AError.hpp"

/**
 * @brief Abstract class for Server errors.
 *
 */
class ServerError : public AError {

    public:

        /**
         * @brief Construct a new ServerError object.
         *
         */
        ServerError(const std::string &message) : AError(message) {}

        /**
         * @brief Destroy the ServerError object.
         *
         */
        ~ServerError() = default;
};

/**
 * @brief Class for ServerSceneManager errors.
 *
 */
class SceneManagerError : public ServerError {

    public:

        /**
         * @brief Construct a new SceneManagerError object.
         *
         */
        SceneManagerError(const std::string &message) : ServerError(message) {}

        /**
         * @brief Destroy the SceneManagerError object.
         *
         */
        ~SceneManagerError() = default;
};

/**
 * @brief Class for the Server SceneManager json errors.
 *
 */
class SceneManagerJsonError : public SceneManagerError {

    public:

        /**
         * @brief Construct a new SceneManagerJsonError object.
         *
         */
        SceneManagerJsonError(const std::string &message) : SceneManagerError(message) {}

        /**
         * @brief Destroy the SceneManagerJsonError object.
         *
         */
        ~SceneManagerJsonError() = default;
};
