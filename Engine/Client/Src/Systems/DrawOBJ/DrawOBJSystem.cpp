/*
** EPITECH PROJECT, 2024
** DrawOBJSystem
** File description:
** DrawOBJSystem
*/

#include "DrawOBJSystem.hpp"
#include "ObjPathComponent.hpp"
#include "Position3DComponent.hpp"
#include "ScaleComponent.hpp"
#include "DrawComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SparseArray.hpp"

#include <exception>

DrawOBJSystem::DrawOBJSystem() :
    ASystem("DrawOBJSystem")
{
}

void DrawOBJSystem::_drawOBJ(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> objPathComponents = reg.get_components<IComponent>("ObjPathComponent");
    ECS::SparseArray<IComponent> position3DComponents = reg.get_components<IComponent>("Position3DComponent");
    ECS::SparseArray<IComponent> scaleComponents = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> drawComponents = reg.get_components<IComponent>("DrawComponent");

    for (ECS::entity_t entity = 0; objPathComponents.size() >= entity + 1; entity++) {
        std::shared_ptr<DrawComponent> draw = (drawComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<DrawComponent>(drawComponents[entity]) : nullptr;

        if (!draw || !draw->draw)
            continue;

        std::shared_ptr<ObjPathComponent> obj = std::dynamic_pointer_cast<ObjPathComponent>(objPathComponents[entity]);

        std::shared_ptr<Position3DComponent> pos = (position3DComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<Position3DComponent>(position3DComponents[entity]) : nullptr;

        std::shared_ptr<ScaleComponent> scale = (scaleComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<ScaleComponent>(scaleComponents[entity]) : nullptr;

        float modelScale;

        if (!obj)
            continue;
        modelScale = (scale) ? scale->scale : 1.0;
        if (pos)
            libGraphic->drawOBJ(obj->path, pos->x, pos->y, pos->z, modelScale);
        else
            libGraphic->drawOBJ(obj->path, 0, 0, 0, modelScale);
    }
}
