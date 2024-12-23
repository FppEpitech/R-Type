/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonTexturePathParser.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "ButtonTexturePathParser.hpp"

std::shared_ptr<ButtonTexturePathComponent> parseButtonTexturePath(const std::string &path)
{
    try {
        std::ifstream file(path);
        Json::Reader reader;
        Json::Value root;

        if (!file.is_open())
            return nullptr;

        if (!reader.parse(file, root, false))
            return nullptr;

        const Json::Value &buttonTexturePath = root["ButtonTexturePathComponent"];
        const Json::Value &buttonNoneTexturePath = buttonTexturePath["None"];
        const Json::Value &buttonHoverTexturePath = buttonTexturePath["Hover"];
        const Json::Value &buttonClickedTexturePath = buttonTexturePath["Clicked"];
        const Json::Value &buttonPressedTexturePath = buttonTexturePath["Pressed"];

        if (buttonTexturePath && buttonNoneTexturePath && buttonHoverTexturePath && buttonClickedTexturePath && buttonPressedTexturePath)
            return std::make_shared<ButtonTexturePathComponent>(buttonNoneTexturePath.asString(), buttonHoverTexturePath.asString(), buttonClickedTexturePath.asString(), buttonPressedTexturePath.asString());
        return nullptr;
    } catch (std::exception e) {
        throw ComponentError(e.what());
    }
}
