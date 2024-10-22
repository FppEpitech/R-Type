/*
** EPITECH PROJECT, 2024
** MobParser
** File description:
** MobParser
*/

#include <json/json.h>
#include <iostream>
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

        const Json::Value& oscillateSpeed = Mob["oscillateSpeed"];
        const Json::Value& shootSpeed = Mob["shootSpeed"];
        const Json::Value& xStartOscillate = Mob["xStartOscillate"];
        const Json::Value& minY = Mob["minY"];
        const Json::Value& maxY = Mob["maxY"];

        if (Mob)
            return std::make_shared<MobComponent>(shootSpeed.asFloat(), xStartOscillate.asInt(), oscillateSpeed.asInt(), minY.asInt(), maxY.asInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
