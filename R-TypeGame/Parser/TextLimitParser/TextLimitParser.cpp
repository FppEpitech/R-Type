/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TextLimitParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "TextLimitParser.hpp"

std::shared_ptr<TextLimitComponent> parseTextLimit(const std::string &path)
{
    try {
        std::ifstream file(path);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value &textLimit = root["TextLimitComponent"];

        if (textLimit)
            return std::make_shared<TextLimitComponent>(textLimit.asUInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
