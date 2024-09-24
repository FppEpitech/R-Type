/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ServerErrors
*/

#pragma once

#include "AError.hpp"

class ServerErrors : public AError {
    public:
        ServerErrors(const std::string &message);
        ~ServerErrors() override = default;
};

class SceneManagerError : public ServerErrors {
    public:
        SceneManagerError(const std::string &message);
        ~SceneManagerError() override = default;
};

