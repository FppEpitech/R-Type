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
#ifdef _WIN32
        std::string suffix = ".dll";
#else
        std::string suffix = ".so";
#endif
        if (file.path().string().length() < prefix.size() + suffix.size())
            continue;
        if (file.path().string().find(prefix) == 0 &&
            file.path().string().find(suffix, file.path().string().length() - 4) != std::string::npos)
            return file.path().string();
    }
    return "";
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
