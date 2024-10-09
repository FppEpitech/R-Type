/*
** EPITECH PROJECT, 2024
** InitShader.cpp
** File description:
** DESCRIPTION
*/

#include <memory>
#include <json/json.h>
#include <unordered_map>
#include <fstream>

#include "InitShader.hpp"
#include "IGraphic.hpp"

InitShader::InitShader(std::shared_ptr<IGraphic> graphicLib, std::string settingsPath)
{
    Json::Value root;
    Json::Reader reader;
    std::ifstream file(settingsPath);
    std::unordered_map<std::string, std::string> shaders;

    try {
        if (!reader.parse(file, root, false))
            throw JsonError("Error while parsing the settings file: " + settingsPath);
        for (const auto &shader: root["color_blindness"]["allPaths"].getMemberNames())
            shaders[shader] = root["color_blindness"]["allPaths"][shader].asString();
        graphicLib->initShaderWithMap(shaders);
        graphicLib->initShaderIntensity(root["color_blindness"]["intensity"].asFloat());
        graphicLib->initCurrentShader(root["color_blindness"]["current"].asString());
    } catch (const std::exception &e) {
        throw JsonError(e.what());
    }
}
