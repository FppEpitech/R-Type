/*
** EPITECH PROJECT, 2024
** Velocity3DParser
** File description:
** Velocity3DParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "../../DefaultComponents/Velocity3D/Velocity3DComponent.hpp"

std::shared_ptr<Velocity3DComponent> parseVelocity3D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        Velocity3DComponent texture;

        const Json::Value& Velocity3D = root["Velocity3DComponent"];

        const Json::Value& vx = Velocity3D["vx"];
        const Json::Value& vy = Velocity3D["vy"];
        const Json::Value& vz = Velocity3D["vz"];

        if (vx && vy && vz)
            return std::make_shared<Velocity3DComponent>(vx.asFloat(), vy.asFloat(), vz.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
