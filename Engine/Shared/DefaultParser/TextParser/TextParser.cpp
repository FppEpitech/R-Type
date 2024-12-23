/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TextParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../DefaultComponents/Text/TextComponent.hpp"

std::shared_ptr<TextComponent> parseText(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& text = root["TextComponent"];

        if (text)
            return std::make_shared<TextComponent>(text.asString());
        return nullptr;
    } catch (std::exception e) {
        throw ComponentError(e.what());
    }
}
