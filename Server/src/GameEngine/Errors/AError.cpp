/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AError
*/

#include "AError.hpp"

AError::AError(const std::string &message) : _message(message) {}

const char *AError::what() const noexcept
{
    return _message.c_str();
}
