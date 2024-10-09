/*
** EPITECH PROJECT, 2024
** MobParser
** File description:
** MobParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "MobComponent.hpp"

std::shared_ptr<MobComponent> parseMob(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& Mob = root["MobComponent"];

        if (Mob)
            return std::make_shared<MobComponent>();
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
