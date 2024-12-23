/*
** EPITECH PROJECT, 2024
** ScaleParser
** File description:
** ScaleParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "../../DefaultComponents/Scale/ScaleComponent.hpp"

std::shared_ptr<ScaleComponent> parseScale(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& scale = root["ScaleComponent"];

        if (scale)
            return std::make_shared<ScaleComponent>(scale.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
