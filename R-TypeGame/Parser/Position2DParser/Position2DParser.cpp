/*
** EPITECH PROJECT, 2024
** Position2DParser
** File description:
** Position2DParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "Position2DComponent.hpp"

std::shared_ptr<Position2DComponent> parsePosition2D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        Position2DComponent texture;

        const Json::Value& position2D = root["Position2DComponent"];

        const Json::Value& x = position2D["x"];
        const Json::Value& y = position2D["y"];

        if (x && y)
            return std::make_shared<Position2DComponent>(x.asInt(), y.asInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
