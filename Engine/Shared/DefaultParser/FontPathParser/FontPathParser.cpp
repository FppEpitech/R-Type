/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** FontParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../DefaultComponents/ObjPath/FontPathComponent.hpp"

std::shared_ptr<FontPathComponent> parseFontPath(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& font = root["FontPathComponent"];

        if (font)
            return std::make_shared<FontPathComponent>(font.asString());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
