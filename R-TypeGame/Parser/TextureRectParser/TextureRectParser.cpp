/*
** EPITECH PROJECT, 2024
** TextureRectParser
** File description:
** TextureRectParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "TextureRect/TextureRectComponent.hpp"

std::shared_ptr<TextureRectComponent> parseTextureRect(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& textureRectJson = root["TextureRectComponent"];
        const Json::Value& scaleJson = root["ScaleComponent"];
        const Json::Value& position2DJson = root["Position2DComponent"];
        const Json::Value& lifeJson = root["LifeComponent"];
        const Json::Value& playerJson = root["PlayerComponent"];
        const Json::Value& speedJson = root["SpeedComponent"];

        const Json::Value& path = textureRectJson["path"];
        const Json::Value& left = textureRectJson["left"];
        const Json::Value& top = textureRectJson["top"];
        const Json::Value& width = textureRectJson["width"];
        const Json::Value& height = textureRectJson["height"];

        if (path && left && top && width && height)
            return std::make_shared<TextureRectComponent>(path.asString(), left.asFloat(), top.asFloat(), width.asFloat(), height.asFloat());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
