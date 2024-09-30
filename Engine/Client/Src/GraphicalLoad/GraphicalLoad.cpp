/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#include <memory>
#include <string>
#include <filesystem>

#include "IGraphic.hpp"
#include "DLLoader.hpp"
#include "GraphicalLoad.hpp"

#define PATH_GRAPHIC_LIB "Engine/Client/Lib/Graphic/"

static std::string getPathGraphicalLib()
{
    std::string path = PATH_GRAPHIC_LIB;

    for (const auto& file : std::filesystem::directory_iterator(path)) {
        std::string prefix = path + "libgraphic_";
        std::string suffix = ".so";
        if (std::string(file.path().c_str()).length() < prefix.size() + suffix.size())
            continue;;
        if (std::string(file.path().c_str()).compare(std::string(file.path().c_str()).length() - suffix.length(), suffix.length(), suffix) == 0 && std::string(file.path().c_str()).compare(0, prefix.length(), prefix) == 0)
            return file.path().c_str();
    }

    return "";
    // std::string(PATH_GRAPHIC_LIB) + "libgraphic_raylib.so"
}

std::shared_ptr<IGraphic> getGraphicalLibrary()
{
    static std::shared_ptr<IGraphic> _libGraphic = DLLoader<IGraphic>::load(getPathGraphicalLib(), "loadGraphicInstance");
    return _libGraphic;
}

void loadGraphicalEcs::loadInRegister(ECS::Registry registry)
{
    for (auto& component : _components)
        registry.register_component<IComponent>(component.get().getType());
}
