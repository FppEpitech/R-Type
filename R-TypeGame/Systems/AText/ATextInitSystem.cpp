/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AText.cpp
*/

#include "ATextInitSystem.hpp"
#include "TextParser.hpp"
#include "Size1DParser.hpp"
#include "ColourParser.hpp"
#include "FontPathParser.hpp"
#include "TextPosition2DParser.hpp"

void ATextInitSystem::_setTextProperties(ECS::Registry &reg, int idxPacketEntities, const std::string &filePath)
{
    std::shared_ptr<TextComponent> text = parseText(filePath);
    if (text) {
        reg.register_component<IComponent>(text->getType());
        reg.set_component<IComponent>(idxPacketEntities, text, text->getType());
    }

    std::shared_ptr<FontPathComponent> font = parseFontPath(filePath);
    if (font) {
        reg.register_component<IComponent>(font->getType());
        reg.set_component<IComponent>(idxPacketEntities, font, font->getType());
    }

    std::shared_ptr<Size1DComponent> size1D = parseSize1D(filePath);
    if (size1D) {
        reg.register_component<IComponent>(size1D->getType());
        reg.set_component<IComponent>(idxPacketEntities, size1D, size1D->getType());
    }

    std::shared_ptr<TextPosition2DComponent> textPosition2D = parseTextPosition2D(filePath);
    if (textPosition2D) {
        reg.register_component<IComponent>(textPosition2D->getType());
        reg.set_component<IComponent>(idxPacketEntities, textPosition2D, textPosition2D->getType());
    }

    std::shared_ptr<ColourComponent> colour = parseColour(filePath);
    if (colour) {
        reg.register_component<IComponent>(colour->getType());
        reg.set_component<IComponent>(idxPacketEntities, colour, colour->getType());
    }
}
