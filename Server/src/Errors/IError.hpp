/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IError
*/

#pragma once

class IError {
    public:
        virtual ~IError() = default;
        virtual const char *what() const noexcept = 0;
};
