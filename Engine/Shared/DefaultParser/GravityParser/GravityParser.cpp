/*
** EPITECH PROJECT, 2024
** GravityParser
** File description:
** GravityParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "GravityParser.hpp"

std::shared_ptr<GravityComponent> parseGravity(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& gravity = root["GravityComponent"];

        const Json::Value& x = gravity["x"];
        const Json::Value& y = gravity["y"];
        const Json::Value& z = gravity["z"];

        if (x && y && z)
            return std::make_shared<GravityComponent>(x.asFloat(), y.asFloat(), z.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
