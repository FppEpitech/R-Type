/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IpTextBoxInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "TextParser.hpp"
#include "ScaleParser.hpp"
#include "Size1DParser.hpp"
#include "ColourParser.hpp"
#include "TextComponent.hpp"
#include "FontPathParser.hpp"
#include "ScaleComponent.hpp"
#include "TextLimitParser.hpp"
#include "Size1DComponent.hpp"
#include "ColourComponent.hpp"
#include "ButtonInitSystem.hpp"
#include "Position2DParser.hpp"
#include "DefaultTextParser.hpp"
#include "CallBackComponent.hpp"
#include "FontPathComponent.hpp"
#include "ButtonStateParser.hpp"
#include "TextureRectParser.hpp"
#include "EditableComponent.hpp"
#include "TextLimitComponent.hpp"
#include "Position2DComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "TextureRectComponent.hpp"
#include "TextPosition2DParser.hpp"
#include "DefaultTextComponent.hpp"
#include "TextPosition2DComponent.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/ipTextBoxSystem.json"

ButtonInitSystem::ButtonInitSystem() :
        ASystem("ButtonInitSystem") {}

void ButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<TextComponent> text = parseText(PATH_JSON);
    if (text) {
        reg.register_component<IComponent>(text->getType());
        reg.set_component<IComponent>(idxPacketEntities, text, text->getType());
    }

    std::shared_ptr<DefaultTextComponent> defaultText = parseDefaultText(PATH_JSON);
    if (defaultText) {
        reg.register_component<IComponent>(defaultText->getType());
        reg.set_component<IComponent>(idxPacketEntities, defaultText, defaultText->getType());
    }

    std::shared_ptr<FontPathComponent> font = parseFontPath(PATH_JSON);
    if (font) {
        reg.register_component<IComponent>(font->getType());
        reg.set_component<IComponent>(idxPacketEntities, font, font->getType());
    }

    std::shared_ptr<Size1DComponent> size1D = parseSize1D(PATH_JSON);
    if (size1D) {
        reg.register_component<IComponent>(size1D->getType());
        reg.set_component<IComponent>(idxPacketEntities, size1D, size1D->getType());
    }

    std::shared_ptr<TextPosition2DComponent> textPosition2D = parseTextPosition2D(PATH_JSON);
    if (textPosition2D) {
        reg.register_component<IComponent>(textPosition2D->getType());
        reg.set_component<IComponent>(idxPacketEntities, textPosition2D, textPosition2D->getType());
    }

    std::shared_ptr<ColourComponent> colour = parseColour(PATH_JSON);
    if (colour) {
        reg.register_component<IComponent>(colour->getType());
        reg.set_component<IComponent>(idxPacketEntities, colour, colour->getType());
    }

    std::shared_ptr<ButtonStateComponent> state = parseButtonState(PATH_JSON);
    if (state) {
        reg.register_component<IComponent>(state->getType());
        reg.set_component<IComponent>(idxPacketEntities, state, state->getType());
    }

    std::shared_ptr<ScaleComponent> scale = parseScale(PATH_JSON);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxPacketEntities, scale, scale->getType());
    }

    std::shared_ptr<TextureRectComponent> textureRect = parseTextureRect(PATH_JSON);
    if (textureRect) {
        reg.register_component<IComponent>(textureRect->getType());
        reg.set_component<IComponent>(idxPacketEntities, textureRect, textureRect->getType());
    }

    std::shared_ptr<Position2DComponent> position2D = parsePosition2D(PATH_JSON);
    if (position2D) {
        reg.register_component<IComponent>(position2D->getType());
        reg.set_component<IComponent>(idxPacketEntities, position2D, position2D->getType());
    }

    std::shared_ptr<CallBackComponent> callback = std::make_shared<CallBackComponent>([](ECS::Registry& reg, int idxPacketEntities) {
        std::shared_ptr<ButtonStateComponent> state = std::dynamic_pointer_cast<ButtonStateComponent>(reg.get_components<IComponent>("ButtonStateComponent")[idxPacketEntities]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(reg.get_components<IComponent>("TextComponent")[idxPacketEntities]);
        std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(reg.get_components<IComponent>("DefaultTextComponent")[idxPacketEntities]);
        if (state && text && defaultText) {
            if (state->state == ButtonStateComponent::ButtonState::CLICKED) {
                state->state = ButtonStateComponent::ButtonState::NONE;
                if (text->text.empty())
                    text->text = defaultText->text;
            } else
                state->state = ButtonStateComponent::ButtonState::CLICKED;
        }
        ECS::SparseArray<IComponent> entities = reg.get_components<IComponent>("ButtonStateComponent");
        for (int i = 0; i < entities.size(); i++) {
            std::shared_ptr<ButtonStateComponent> state = std::dynamic_pointer_cast<ButtonStateComponent>(entities[i]);
            if (state && state->state == ButtonStateComponent::ButtonState::CLICKED && i != idxPacketEntities)
                state->state = ButtonStateComponent::ButtonState::NONE;
        }
    });
    reg.register_component<IComponent>(callback->getType());
    reg.set_component<IComponent>(idxPacketEntities, callback, callback->getType());

    std::shared_ptr<EditableComponent> editable = std::make_shared<EditableComponent>();
    reg.register_component<IComponent>(editable->getType());
    reg.set_component<IComponent>(idxPacketEntities, editable, editable->getType());

    std::shared_ptr<TextLimitComponent> textLimit = parseTextLimit(PATH_JSON);
    if (textLimit) {
        reg.register_component<IComponent>(textLimit->getType());
        reg.set_component<IComponent>(idxPacketEntities, textLimit, textLimit->getType());
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new ButtonInitSystem();
}
