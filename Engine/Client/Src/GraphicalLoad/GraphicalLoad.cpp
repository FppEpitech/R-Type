/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#include <memory>
#include <string>

#include "IGraphic.hpp"
#include "DLLoader.hpp"
#include "GraphicalLoad.hpp"

#define PATH_GRAPHIC_LIB "Engine/Client/Lib/Graphic/"

std::shared_ptr<IGraphic> getGraphicalLibrary()
{
    static std::shared_ptr<IGraphic> _libGraphic = DLLoader<IGraphic>::load(std::string(PATH_GRAPHIC_LIB) + "libgraphic_raylib.so", "loadGraphicInstance");
    return _libGraphic;
}

void loadGraphicalEcs::loadInRegister(ECS::Registry registry)
{
    for (auto& component : _components)
        registry.register_component<IComponent>(component.get().getType());
}
