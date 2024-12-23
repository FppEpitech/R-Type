/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ColourParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../DefaultComponents/Colour/ColourComponent.hpp"

std::shared_ptr<ColourComponent> parseColour(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& colour = root["ColourComponent"];

        const Json::Value& r = colour["r"];
        const Json::Value& g = colour["g"];
        const Json::Value& b = colour["b"];
        const Json::Value& a = colour["a"];

        if (r && g && b && a)
            return std::make_shared<ColourComponent>(r.asUInt64(), g.asUInt64(), b.asUInt64(), a.asUInt64());
        return nullptr;
    } catch (std::exception e) {
        throw ComponentError(e.what());
    }
}
