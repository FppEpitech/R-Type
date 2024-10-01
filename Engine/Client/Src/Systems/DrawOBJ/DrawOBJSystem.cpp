/*
** EPITECH PROJECT, 2024
** DrawOBJSystem
** File description:
** DrawOBJSystem
*/

#include "DrawOBJSystem.hpp"
#include "ObjPathComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SparseArray.hpp"

DrawOBJSystem::DrawOBJSystem() :
    ASystem("DrawOBJSystem")
{
}

void DrawOBJSystem::_drawOBJ(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> objPathComponents = reg.get_components<IComponent>("ObjPathComponent");

    for (auto entity : reg.getEntities()) {
        std::shared_ptr<ObjPathComponent> obj = std::dynamic_pointer_cast<ObjPathComponent>(objPathComponents[entity]);
        if (obj)
            libGraphic->drawOBJ(obj->path, entity * 2, 0, 0, 1);
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new DrawOBJSystem();
}
