/*
** EPITECH PROJECT, 2024
** Speed3DParser
** File description:
** Speed3DParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "../../DefaultComponents/Speed3D/Speed3DComponent.hpp"

std::shared_ptr<Speed3DComponent> parseSpeed3D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& speed = root["Speed3DComponent"];
        const Json::Value& x = speed["x"];
        const Json::Value& y = speed["y"];
        const Json::Value& z = speed["z"];

        if (x && y && z)
            return std::make_shared<Speed3DComponent>(x.asFloat(), y.asFloat(), z.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
