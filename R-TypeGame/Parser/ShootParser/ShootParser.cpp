/*
** EPITECH PROJECT, 2024
** ShootParser
** File description:
** ShootParser
*/

#include <memory>
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <unordered_map>

#include "ShootComponent.hpp"

static ShootComponent::ShootType getShootType(std::string type)
{
    std::unordered_map<std::string, ShootComponent::ShootType> map = {
        {"Player", ShootComponent::ShootType::PLAYER},
        {"Enemy", ShootComponent::ShootType::ENEMY},
        {"Boss", ShootComponent::ShootType::BOSS},
        {"Mob", ShootComponent::ShootType::MOB},
        {"None", ShootComponent::ShootType::NONE}
    };

    if (map.find(type) != map.end())
        return map[type];
    return ShootComponent::ShootType::NONE;
}

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
        const Json::Value& type = Shoot["type"];

        if (damage && friendlyFire && type)
            return std::make_shared<ShootComponent>(damage.asInt(), friendlyFire.asBool(), getShootType(type.asString()));
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
