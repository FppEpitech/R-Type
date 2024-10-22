/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "TextParser.hpp"
#include "ScaleParser.hpp"
#include "Size1DParser.hpp"
#include "ColourParser.hpp"
#include "TextComponent.hpp"
#include "DrawComponent.hpp"
#include "FontPathParser.hpp"
#include "ScaleComponent.hpp"
#include "Size1DComponent.hpp"
#include "ColourComponent.hpp"
#include "AButtonInitSystem.hpp"
#include "Position2DParser.hpp"
#include "DefaultTextParser.hpp"
#include "FontPathComponent.hpp"
#include "ButtonStateParser.hpp"
#include "TextureRectParser.hpp"
#include "Position2DComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "TextureRectComponent.hpp"
#include "TextPosition2DParser.hpp"
#include "DefaultTextComponent.hpp"
#include "TextPosition2DComponent.hpp"
#include "ButtonTexturePathParser.hpp"
#include "ButtonTexturePathComponent.hpp"

void AButtonInitSystem::_setButtonProprieties(ECS::Registry &reg, int idxPacketEntities, const std::string &filePath, std::function<void(ECS::Registry &, int)> callback)
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

    std::shared_ptr<DefaultTextComponent> defaultText = parseDefaultText(filePath);
    if (defaultText) {
        reg.register_component<IComponent>(defaultText->getType());
        reg.set_component<IComponent>(idxPacketEntities, defaultText, defaultText->getType());
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

    std::shared_ptr<ButtonStateComponent> state = parseButtonState(filePath);
    if (state) {
        reg.register_component<IComponent>(state->getType());
        reg.set_component<IComponent>(idxPacketEntities, state, state->getType());
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

    std::shared_ptr<ClickableComponent> clickableComponent = std::make_shared<ClickableComponent>([callback](ECS::Registry& reg, int idxPacketEntities){
        callback(reg, idxPacketEntities);
    });
    reg.register_component<IComponent>(clickableComponent->getType());
    reg.set_component<IComponent>(idxPacketEntities, clickableComponent, clickableComponent->getType());


    std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = parseButtonTexturePath(filePath);
    if (buttonTexturePath) {
        reg.register_component<IComponent>(buttonTexturePath->getType());
        reg.set_component<IComponent>(idxPacketEntities, buttonTexturePath, buttonTexturePath->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}
