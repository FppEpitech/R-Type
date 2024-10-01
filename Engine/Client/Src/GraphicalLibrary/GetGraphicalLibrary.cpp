/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GetGraphicalLibrary.cpp
*/

#include <filesystem>

#include "DLLoader.hpp"
#include "IGraphic.hpp"
#include "ClientErrors.hpp"
#include "GetGraphicalLibrary.hpp"

static std::string getPathGraphicalLib()
{
    std::string path = PATH_GRAPHIC_LIB;

    for (const auto& file : std::filesystem::directory_iterator(path)) {
        std::string prefix = path + "libgraphic_";
        std::string suffix = LIB_SUFFIX;

        std::string libPath = file.path().libPathing();
        if (libPath.length() < prefix.size() + suffix.size())
            continue;
        if (libPath.find(prefix) == 0 && libPath.find(suffix, libPath.length() - 4) != std::string::npos)
            return libPath;
    }
    return "";
}

std::shared_ptr<IGraphic> getGraphicalLibrary()
{
    static std::shared_ptr<IGraphic> _libGraphic = DLLoader<IGraphic>::load(getPathGraphicalLib(), "loadGraphicInstance");
    if (!_libGraphic)
        throw ClientError("Failed to load graphic library");
    return _libGraphic;
}
