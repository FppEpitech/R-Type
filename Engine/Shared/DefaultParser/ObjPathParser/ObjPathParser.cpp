/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ObjParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../DefaultComponents/ObjPath/ObjPathComponent.hpp"

std::shared_ptr<ObjPathComponent> parseObjPath(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& path = root["ObjPathComponent"];

        if (path)
            return std::make_shared<ObjPathComponent>(path.asString());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
