/*
** EPITECH PROJECT, 2024
** Position3DParser
** File description:
** Position3DParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "Position3DParser.hpp"

std::shared_ptr<Position3DComponent> parsePosition3D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& position3D = root["Position3DComponent"];

        const Json::Value& x = position3D["x"];
        const Json::Value& y = position3D["y"];
        const Json::Value& z = position3D["z"];

        if (x && y && z)
            return std::make_shared<Position3DComponent>(x.asFloat(), y.asFloat(), z.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
