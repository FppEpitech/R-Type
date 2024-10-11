/*
** EPITECH PROJECT, 2024
** ShootParser
** File description:
** ShootParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "ShootComponent.hpp"

std::shared_ptr<ShootComponent> parseShoot(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& Shoot = root["ShootComponent"];

        const Json::Value& damage = Shoot["damage"];
        const Json::Value& friendlyFire = Shoot["friendlyFire"];

        if (damage && friendlyFire)
            return std::make_shared<ShootComponent>(damage.asInt(), friendlyFire.asBool());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
