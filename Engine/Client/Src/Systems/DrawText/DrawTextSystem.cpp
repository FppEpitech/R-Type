/*
** EPITECH PROJECT, 2024
** DrawTextSystem
** File description:
** DrawTextSystem
*/

#include "SparseArray.hpp"
#include "DrawTextSystem.hpp"
#include "Text/TextComponent.hpp"
#include "Draw/DrawComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "Size1D/Size1DComponent.hpp"
#include "Colour/ColourComponent.hpp"
#include "FontPath/FontPathComponent.hpp"
#include "TextPosition2D/TextPosition2DComponent.hpp"

DrawTextSystem::DrawTextSystem() :
    ASystem("DrawTextSystem")
{
}

void DrawTextSystem::_drawText(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> textComponents = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> textPosition2DComponents = reg.get_components<IComponent>("TextPosition2DComponent");
    ECS::SparseArray<IComponent> size1DComponents = reg.get_components<IComponent>("Size1DComponent");
    ECS::SparseArray<IComponent> fontPathComponents = reg.get_components<IComponent>("FontPathComponent");
    ECS::SparseArray<IComponent> colourComponents = reg.get_components<IComponent>("ColourComponent");
    ECS::SparseArray<IComponent> drawComponents = reg.get_components<IComponent>("DrawComponent");

    for (ECS::entity_t entity = 0; textComponents.size() >= entity + 1; entity++) {
        std::shared_ptr<DrawComponent> draw = (drawComponents.size() >= entity + 1) ?
                std::dynamic_pointer_cast<DrawComponent>(drawComponents[entity]) : nullptr;

        if (!draw || !draw->draw)
            continue;

        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(textComponents[entity]);
        if (!text)
            continue;
        std::shared_ptr<TextPosition2DComponent> pos = (textPosition2DComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<TextPosition2DComponent>(textPosition2DComponents[entity]) : nullptr;
        std::shared_ptr<Size1DComponent> size = (size1DComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<Size1DComponent>(size1DComponents[entity]) : nullptr;
        std::shared_ptr<FontPathComponent> path = (fontPathComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<FontPathComponent>(fontPathComponents[entity]) : nullptr;
        std::shared_ptr<ColourComponent> colour = (colourComponents.size() >= entity + 1) ?
            std::dynamic_pointer_cast<ColourComponent>(colourComponents[entity]) : nullptr;

        float fontSize;
        std::string fontPath;
        fontSize = (size) ? size->size : 24;
        fontPath = (path) ? path->path : "";

        if (colour) {
            if (pos)
                libGraphic->drawText(text->text, pos->x, pos->y, fontSize, fontPath, colour->r, colour->g, colour->b, colour->a);
            else
                libGraphic->drawText(text->text, 0, 0, fontSize, fontPath, colour->r, colour->g, colour->b, colour->a);
        } else {
            if (pos)
                libGraphic->drawText(text->text, pos->x, pos->y, fontSize, fontPath);
            else
                libGraphic->drawText(text->text, 0, 0, fontSize, fontPath);
        }
    }
}
