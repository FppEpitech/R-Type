/*
** EPITECH PROJECT, 2024
** LifeParser
** File description:
** LifeParser
*/

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "../../Components/Life/LifeComponent.hpp"

std::shared_ptr<LifeComponent> parseLife(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& life = root["LifeComponent"];

        if (life)
            return std::make_shared<LifeComponent>(life.asUInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
