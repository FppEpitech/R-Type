/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AError
*/

#pragma once

#include "IError.hpp"

class AError : public IError {
    public:
        AError(const std::string &message);
        ~AError() override = default;

        const char *what() const noexcept override;

    protected:
        std::string _message;
};
