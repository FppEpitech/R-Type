/*
** EPITECH PROJECT, 2024
** InitWindow.cpp
** File description:
** DESCRIPTION
*/

#include "InitWindow.hpp"

InitWindow::InitWindow(std::shared_ptr<IGraphic> graphicLib, std::string settingsPath)
{
    Json::Value root;
    Json::Reader reader;
    std::ifstream file(settingsPath);
    std::vector<std::pair<int, int>> allResolutions;

    try {
        if (!reader.parse(file, root, false))
            throw JsonError("Error while parsing the settings file: " + settingsPath);
        for (const auto &resolution: root["window"]["resolutions"])
            allResolutions.push_back({resolution["w"].asInt(), resolution["h"].asInt()});
        bool fullscreen = root["window"]["fullscreen"].asBool();
        int index = root["window"]["resolutionIndex"].asInt();
        std::string title = root["gameInfo"]["title"].asString();
        graphicLib->setResolutionList(allResolutions);
        graphicLib->init(title);
        graphicLib->changeResolution(allResolutions[index].first, allResolutions[index].second);
        if (fullscreen)
            graphicLib->setFullscreen();
    } catch (const std::exception &e) {
        throw JsonError(e.what());
    }
}
