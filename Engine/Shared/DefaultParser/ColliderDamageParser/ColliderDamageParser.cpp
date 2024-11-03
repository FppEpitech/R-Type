/*
** EPITECH PROJECT, 2024
** ColliderDamageParser
** File description:
** ColliderDamageParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "../../DefaultComponents/ColliderDamage/ColliderDamageComponent.hpp"

std::shared_ptr<ColliderDamageComponent> parseColliderDamage(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& colliderDamage = root["ColliderDamageComponent"];

        if (colliderDamage)
            return std::make_shared<ColliderDamageComponent>(colliderDamage.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
