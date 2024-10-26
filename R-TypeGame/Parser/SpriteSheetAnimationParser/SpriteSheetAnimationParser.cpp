/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationParser
** File description:
** SpriteSheetAnimationParser
*/

#include <json/json.h>
#include <exception>
#include <iostream>
#include <memory>
#include <fstream>

#include "SpriteSheetAnimationComponent.hpp"

std::shared_ptr<SpriteSheetAnimationComponent> parseSpriteSheetAnimation(std::string pathFile)
{
    try {
        std::ifstream file(pathFile);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value& spriteSheetAnimation = root["SpriteSheetAnimationComponent"];
        const Json::Value& nbFrame = spriteSheetAnimation["nbFrame"];
        const Json::Value& timeFrame = spriteSheetAnimation["timeFrame"];
        const Json::Value& vx = spriteSheetAnimation["vx"];
        const Json::Value& vy = spriteSheetAnimation["vy"];
        const Json::Value& startX = spriteSheetAnimation["startX"];
        const Json::Value& startY = spriteSheetAnimation["startY"];
        const Json::Value& reverseMod = spriteSheetAnimation["reverseMod"];

        if (nbFrame && timeFrame && vx && vy && startX && startY && reverseMod)
            return std::make_shared<SpriteSheetAnimationComponent>(
                nbFrame.asUInt(), timeFrame.asFloat(), vx.asFloat(), vy.asFloat(), startX.asFloat(), startY.asFloat(), reverseMod.asBool());
        return nullptr;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}
