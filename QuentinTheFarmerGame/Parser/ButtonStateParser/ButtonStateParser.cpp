/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonStateParser.cpp
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <fstream>

#include "ButtonStateParser.hpp"

std::shared_ptr<ButtonStateComponent> parseButtonState(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& buttonState = root["ButtonStateComponent"];

        if (buttonState)
            return std::make_shared<ButtonStateComponent>(ButtonStateComponent::getStateFromString(buttonState.asString()));
        return nullptr;
    } catch (std::exception &e) {
        throw ComponentError(e.what());
    }
}
