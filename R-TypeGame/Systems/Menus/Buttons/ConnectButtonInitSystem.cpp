/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ConnectToServerButtonSystem.cpp
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
#include "Size1DComponent.hpp"
#include "ColourComponent.hpp"
#include "ButtonInitSystem.hpp"
#include "Position2DParser.hpp"
#include "CallBackComponent.hpp"
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

#define PATH_JSON "GameData/Scenes/Menus/Buttons/connectButtonSystem.json"

ButtonInitSystem::ButtonInitSystem() :
    ASystem("ButtonInitSystem")
{}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::cout << "Connect to server" << std::endl;
}

static void handleOther(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> states = reg.get_components<IComponent>("ButtonStateComponent");
    ECS::SparseArray<IComponent> callbacks = reg.get_components<IComponent>("CallBackComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");
    for (int i = 0; i < states.size() && i < callbacks.size() && i < texts.size() && i < defaultTexts.size(); i++) {
        std::shared_ptr<ButtonStateComponent> newState = std::dynamic_pointer_cast<ButtonStateComponent>(states[i]);
        std::shared_ptr<CallBackComponent> callback = std::dynamic_pointer_cast<CallBackComponent>(callbacks[i]);
        std::shared_ptr<TextComponent> newText = std::dynamic_pointer_cast<TextComponent>(texts[i]);
        std::shared_ptr<DefaultTextComponent> newDefaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[i]);
        if (!newState || !callback || !newText || !newDefaultText)
            continue;
        if (newState->state == ButtonStateComponent::ButtonState::CLICKED && i != idxPacketEntities) {
            newState->state = ButtonStateComponent::ButtonState::NONE;
            if (newText->text.empty())
                newText->text = newDefaultText->text;
        }
    }
}

void ButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<TextComponent> text = parseText(PATH_JSON);
    if (text) {
        reg.register_component<IComponent>(text->getType());
        reg.set_component<IComponent>(idxPacketEntities, text, text->getType());
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
        handleThis(reg, idxPacketEntities);
        handleOther(reg, idxPacketEntities);
    });
    reg.register_component<IComponent>(callback->getType());
    reg.set_component<IComponent>(idxPacketEntities, callback, callback->getType());

    std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = parseButtonTexturePath(PATH_JSON);
    if (buttonTexturePath) {
        reg.register_component<IComponent>(buttonTexturePath->getType());
        reg.set_component<IComponent>(idxPacketEntities, buttonTexturePath, buttonTexturePath->getType());
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new ButtonInitSystem();
}
