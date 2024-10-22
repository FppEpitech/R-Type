/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** DefaultTextParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "DefaultTextComponent.hpp"

std::shared_ptr<DefaultTextComponent> parseDefaultText(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& defaultText = root["DefaultTextComponent"];

        if (defaultText)
            return std::make_shared<DefaultTextComponent>(defaultText.asString());
        return nullptr;
    } catch (std::exception e) {
        throw ComponentError(e.what());
    }
}
