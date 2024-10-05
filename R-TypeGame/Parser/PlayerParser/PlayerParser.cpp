/*
** EPITECH PROJECT, 2024
** PlayerParser
** File description:
** PlayerParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "PlayerComponent.hpp"

std::shared_ptr<PlayerComponent> parsePlayer(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& player = root["PlayerComponent"];

        if (player)
            return std::make_shared<PlayerComponent>(player.asUInt());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
