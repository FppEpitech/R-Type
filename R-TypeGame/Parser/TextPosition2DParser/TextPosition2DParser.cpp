/*
** EPITECH PROJECT, 2024
** TextPosition2DParser
** File description:
** TextPosition2DParser
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "TextPosition2DComponent.hpp"

std::shared_ptr<TextPosition2DComponent> parseTextPosition2D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& textPosition2D = root["TextPosition2DComponent"];

        const Json::Value& x = textPosition2D["x"];
        const Json::Value& y = textPosition2D["y"];

        if (x && y)
            return std::make_shared<TextPosition2DComponent>(x.asInt(), y.asInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
