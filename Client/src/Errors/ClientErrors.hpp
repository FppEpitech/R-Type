/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientErrors
*/

#pragma once

#include "IError.hpp"

/**
 * @brief Abstract class for client errors
 *
 */
class ClientError : public AError {

    public:

        /**
         * @brief Construct a new ClientError object
         *
         */
        ClientError(const std::string &message) : AError(message) {}

        /**
         * @brief Destroy the ClientError object
         *
         */
        ~ClientError() = default;
};

/**
 * @brief Class for ClientSceneManager errors
 *
 */
class SceneManagerError : public ClientError {

    public:

        /**
         * @brief Construct a new SceneManagerError object
         *
         */
        SceneManagerError(const std::string &message) : ClientError(message) {}

        /**
         * @brief Destroy the SceneManagerError object
         *
         */
        ~SceneManagerError() = default;
};

/**
 * @brief Class for the Client SceneManager json errors
 *
 */
class SceneManagerJsonError : public SceneManagerError {

    public:

        /**
         * @brief Construct a new SceneManagerJsonError object
         *
         */
        SceneManagerJsonError(const std::string &message) : SceneManagerError(message) {}

        /**
         * @brief Destroy the SceneManagerJsonError object
         *
         */
        ~SceneManagerJsonError() = default;
};
