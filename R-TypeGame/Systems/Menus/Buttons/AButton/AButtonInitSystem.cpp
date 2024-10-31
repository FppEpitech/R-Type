/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../../../../Engine/Shared/DefaultParser/TextParser/TextParser.hpp"
#include "../../../../../Engine/Shared/DefaultParser/ScaleParser/ScaleParser.hpp"
#include "../../../../../Engine/Shared/DefaultParser/Size1DParser/Size1DParser.hpp"
#include "../../../../../Engine/Shared/DefaultParser/ColourParser/ColourParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Text/TextComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Draw/DrawComponent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/FontPathParser/FontPathParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Scale/ScaleComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Size1D/Size1DComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Colour/ColourComponent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/Position2DParser/Position2DParser.hpp"
#include "AButtonInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultParser/ButtonStateParser/ButtonStateParser.hpp"
#include "../../../../../Engine/Shared/DefaultParser/TextureRectParser/TextureRectParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Clickable/ClickableComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Position2D/Position2DComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/ButtonState/ButtonStateComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/TextureRect/TextureRectComponent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/TextPosition2DParser/TextPosition2DParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/TextPosition2D/TextPosition2DComponent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/ButtonTexturePathParser/ButtonTexturePathParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/ButtonTexturePath/ButtonTexturePathComponent.hpp"

void AButtonInitSystem::_setButtonProperties(ECS::Registry &reg, int idxPacketEntities, const std::string &filePath, std::function<void(ECS::Registry &, int)> callback)
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
    if (clickableComponent) {
        reg.register_component<IComponent>(clickableComponent->getType());
        reg.set_component<IComponent>(idxPacketEntities, clickableComponent, clickableComponent->getType());
    }

    std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = parseButtonTexturePath(filePath);
    if (buttonTexturePath) {
        reg.register_component<IComponent>(buttonTexturePath->getType());
        reg.set_component<IComponent>(idxPacketEntities, buttonTexturePath, buttonTexturePath->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}
