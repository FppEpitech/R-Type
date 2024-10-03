/*
** EPITECH PROJECT, 2024
** SpeedParser
** File description:
** SpeedParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "SpeedComponent.hpp"

std::shared_ptr<SpeedComponent> parseSpeed(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        SpeedComponent texture;

        const Json::Value& speed = root["SpeedComponent"];
        const Json::Value& x = speed["x"];
        const Json::Value& y = speed["y"];

        if (x && y)
            return std::make_shared<SpeedComponent>(x.asUInt(), y.asUInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}