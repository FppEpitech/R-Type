/*
** EPITECH PROJECT, 2024
** DrawTextureRectSystem
** File description:
** DrawTextureRectSystem
*/

#include "DrawTextureRectSystem.hpp"
#include "../../../../Shared/DefaultComponent/Position2D/Position2DComponent.hpp"
#include "../../../../Shared/DefaultComponent/Scale/ScaleComponent.hpp"
#include "../../../../Shared/DefaultComponent/TextureRect/TextureRectComponent.hpp"
#include "../../../../Shared/DefaultComponent/Draw/DrawComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SparseArray.hpp"

#include <exception>
#include <ColourComponent.hpp>

DrawTextureRectSystem::DrawTextureRectSystem() :
    ASystem("DrawTextureRectSystem")
{
}

void DrawTextureRectSystem::_drawTextureRect(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> texturerectComponents = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> position2DComponents = reg.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> scaleComponents = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> colourComponents = reg.get_components<IComponent>("ColourComponent");
    ECS::SparseArray<IComponent> drawComponents = reg.get_components<IComponent>("DrawComponent");

    for (ECS::entity_t entity = 0; texturerectComponents.size() >= entity + 1; entity++) {
        std::shared_ptr<DrawComponent> draw = (drawComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<DrawComponent>(drawComponents[entity]) : nullptr;

        if (!draw || !draw->draw)
            continue;

        std::shared_ptr<TextureRectComponent> texture = std::dynamic_pointer_cast<TextureRectComponent>(texturerectComponents[entity]);
        if (!texture)
            continue;

        std::shared_ptr<Position2DComponent> pos = (position2DComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<Position2DComponent>(position2DComponents[entity]) : nullptr;

        std::shared_ptr<ScaleComponent> scale = (scaleComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<ScaleComponent>(scaleComponents[entity]) : nullptr;

        std::shared_ptr<ColourComponent> colour = (colourComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<ColourComponent>(colourComponents[entity]) : nullptr;

        if (!colour)
            colour = std::make_shared<ColourComponent>(255, 255, 255, 255);

        float modelScale;

        modelScale = (scale) ? scale->scale : 1.0;
        if (pos)
            libGraphic->drawTextureRect(texture->path, pos->x, pos->y, texture->left, texture->top, texture->width, texture->height, modelScale, colour->r, colour->g, colour->b, colour->a);
        else
            libGraphic->drawTextureRect(texture->path, 0, 0, texture->left, texture->top, texture->width, texture->height, modelScale, colour->r, colour->g, colour->b, colour->a);
    }
}
