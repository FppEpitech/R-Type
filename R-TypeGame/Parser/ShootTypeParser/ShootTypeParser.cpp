/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootTypeParser.cpp
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <fstream>

#include "ShootTypeParser.hpp"

std::shared_ptr<ShootTypeComponent> parseShootType(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& shootType = root["ShootTypeComponent"];

        if (shootType)
            return std::make_shared<ShootTypeComponent>(ShootTypeComponent::getTypeFromString(shootType.asString()));
        return nullptr;
    } catch (std::exception &e) {
        throw ComponentError(e.what());
    }
}
