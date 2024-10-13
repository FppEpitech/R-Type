/*
** EPITECH PROJECT, 2024
** DrawTextureSystem
** File description:
** DrawTextureSystem
*/

#include "DrawTextureSystem.hpp"
#include "Position2DComponent.hpp"
#include "ScaleComponent.hpp"
#include "TexturePathComponent.hpp"
#include "DrawComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SparseArray.hpp"

#include <exception>

DrawTextureSystem::DrawTextureSystem() :
    ASystem("DrawTextureSystem")
{
}

void DrawTextureSystem::_drawTexture(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> texturePathComponents = reg.get_components<IComponent>("TexturePathComponent");
    ECS::SparseArray<IComponent> position2DComponents = reg.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> scaleComponents = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> drawComponents = reg.get_components<IComponent>("DrawComponent");

    for (ECS::entity_t entity = 0; texturePathComponents.size() >= entity + 1; entity++) {
        std::shared_ptr<DrawComponent> draw = (drawComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<DrawComponent>(drawComponents[entity]) : nullptr;

        if (!draw || !draw->draw)
            continue;

        std::shared_ptr<TexturePathComponent> texture = std::dynamic_pointer_cast<TexturePathComponent>(texturePathComponents[entity]);

        std::shared_ptr<Position2DComponent> pos = (position2DComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<Position2DComponent>(position2DComponents[entity]) : nullptr;

        std::shared_ptr<ScaleComponent> scale = (scaleComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<ScaleComponent>(scaleComponents[entity]) : nullptr;

        float modelScale;

        if (!texture)
            continue;
        modelScale = (scale) ? scale->scale : 1.0;
        if (pos)
            libGraphic->drawTexture(texture->path, pos->x, pos->y, modelScale);
        else
            libGraphic->drawTexture(texture->path, 0, 0, modelScale);
    }
}
