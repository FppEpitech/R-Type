/*
** EPITECH PROJECT, 2024
** Size1DParser
** File description:
** Size1DParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "../../DefaultComponents/Size1D/Size1DComponent.hpp"

std::shared_ptr<Size1DComponent> parseSize1D(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& size = root["Size1DComponent"];

        if (size)
            return std::make_shared<Size1DComponent>(size.asInt());
        return nullptr;
    } catch (std::exception e) {
        throw ComponentError(e.what());
    }
}
