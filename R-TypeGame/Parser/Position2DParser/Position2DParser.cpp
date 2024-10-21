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

#include "../../../Engine/Shared/DefaultComponent/Position2D/Position2DComponent.hpp"

std::shared_ptr<Position2DComponent> parsePosition2D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

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
