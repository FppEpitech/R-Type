/*
** EPITECH PROJECT, 2024
** VelocityParser
** File description:
** VelocityParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "../../DefaultComponents/Velocity/VelocityComponent.hpp"

std::shared_ptr<VelocityComponent> parseVelocity(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        VelocityComponent texture;

        const Json::Value& Velocity = root["VelocityComponent"];

        const Json::Value& vx = Velocity["vx"];
        const Json::Value& vy = Velocity["vy"];

        if (vx && vy)
            return std::make_shared<VelocityComponent>(vx.asFloat(), vy.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
