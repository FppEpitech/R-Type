/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#include <memory>
#include <string>

#include "IGraphic.hpp"
#include "DLLoader/DLLoader.hpp"

#define PATH_GRAPHIC_LIB "Server/lib/components/"

std::shared_ptr<IGraphic> getGraphicalLibrary()
{
    static std::shared_ptr<IGraphic> _libGraphic = DLLoader<IGraphic>::load(std::string(PATH_GRAPHIC_LIB) + "libgraphic.so", "loadGraphicInstance");
    return _libGraphic;
}
