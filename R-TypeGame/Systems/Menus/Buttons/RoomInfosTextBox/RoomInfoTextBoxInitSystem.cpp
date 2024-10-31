/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomInfoTextBoxInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "TextParser.hpp"
#include "ScaleParser.hpp"
#include "Size1DParser.hpp"
#include "ColourParser.hpp"
#include "DrawComponent.hpp"
#include "FontPathParser.hpp"
#include "Position2DParser.hpp"
#include "DefaultTextParser.hpp"
#include "TextureRectParser.hpp"
#include "EntityIdComponent.hpp"
#include "TextPosition2DParser.hpp"
#include "RoomInfoTextBoxInitSystem.hpp"

RoomInfoTextBoxInitSystem::RoomInfoTextBoxInitSystem(ECS::Registry &reg, int idxPacketEntities, const std::string &filePath)
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

    std::shared_ptr<ScaleComponent> scale = parseScale(filePath);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxPacketEntities, scale, scale->getType());
    }

    std::shared_ptr<TextureRectComponent> textureRect = parseTextureRect(filePath);
    if (textureRect) {
        reg.register_component<IComponent>(textureRect->getType());
        reg.set_component<IComponent>(idxPacketEntities, textureRect, textureRect->getType());
    }

    std::shared_ptr<Position2DComponent> position2D = parsePosition2D(filePath);
    if (position2D) {
        reg.register_component<IComponent>(position2D->getType());
        reg.set_component<IComponent>(idxPacketEntities, position2D, position2D->getType());
    }

    std::shared_ptr<DefaultTextComponent> defaultText = parseDefaultText(filePath);
    if (defaultText) {
        reg.register_component<IComponent>(defaultText->getType());
        reg.set_component<IComponent>(idxPacketEntities, defaultText, defaultText->getType());
    }

    std::shared_ptr<EntityIdComponent> entityId = std::make_shared<EntityIdComponent>(idxPacketEntities);
    reg.set_component<IComponent>(idxPacketEntities, entityId, "EntityIdComponent");

    std::shared_ptr<IComponent> draw = std::make_shared<DrawComponent>();
    reg.set_component(idxPacketEntities, draw, "DrawComponent");
}
