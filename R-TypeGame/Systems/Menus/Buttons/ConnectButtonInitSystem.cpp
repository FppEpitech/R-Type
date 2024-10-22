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
#include "../Text/TextComponent.hpp"
#include "../Draw/DrawComponent.hpp"
#include "FontPathParser.hpp"
#include "../Scale/ScaleComponent.hpp"
#include "../Size1D/Size1DComponent.hpp"
#include "../Colour/ColourComponent.hpp"
#include "ButtonInitSystem.hpp"
#include "Position2DParser.hpp"
#include "DefaultTextParser.hpp"
#include "CallBackComponent.hpp"
#include "../FontPath/FontPathComponent.hpp"
#include "ButtonStateParser.hpp"
#include "TextureRectParser.hpp"
#include "../Position2D/Position2DComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "../TextureRect/TextureRectComponent.hpp"
#include "TextPosition2DParser.hpp"
#include "../DefaultText/DefaultTextComponent.hpp"
#include "../TextPosition2D/TextPosition2DComponent.hpp"
#include "ButtonTexturePathParser.hpp"
#include "ButtonTexturePathComponent.hpp"
#include "../NetworkConnection/NetworkConnectionComponent.hpp"

#define PATH_JSON "GameData/Scenes/Menus/Buttons/connectButtonSystem.json"

ButtonInitSystem::ButtonInitSystem() :
    ASystem("ButtonInitSystem")
{}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> callbacks = reg.get_components<IComponent>("CallBackComponent");
    ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> buttonTexturePaths = reg.get_components<IComponent>("ButtonTexturePathComponent");
    ECS::SparseArray<IComponent> buttonText = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> buttonDefaultText = reg.get_components<IComponent>("DefaultTextComponent");
    ECS::SparseArray<IComponent> buttonNetworkConnection = reg.get_components<IComponent>("NetworkConnectionComponent");

    std::string ipServer = "";
    std::string portServer = "";
    ECS::entity_t entityConnection = 0;

    for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && callbacks.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1; entity++) {
        std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
        std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
        std::shared_ptr<CallBackComponent> callback = std::dynamic_pointer_cast<CallBackComponent>(callbacks[entity]);
        std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
        std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(buttonText[entity]);
        std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(buttonDefaultText[entity]);
        if (!position || !textureRect || !callback || !scale || !buttonTexturePath || !text || !defaultText)
            continue;
        if (defaultText->text == "Write the server IP")
            ipServer = text->text;
        if (defaultText->text == "Write the server Port")
            portServer = text->text;
    }
    for (ECS::entity_t entity = 0; buttonNetworkConnection.size() >= entity + 1 && buttonDefaultText.size() >= entity + 1; entity++) {
        std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(buttonDefaultText[entity]);
        std::shared_ptr<NetworkConnectionComponent> connection = std::dynamic_pointer_cast<NetworkConnectionComponent>(buttonNetworkConnection[entity]);
        if (!connection || !defaultText)
            continue;
        if (defaultText->text == "Connect to server")
            entityConnection = entity;
    }
    if (buttonNetworkConnection.size() <= entityConnection)
        return;
    std::shared_ptr<NetworkConnectionComponent> network = std::dynamic_pointer_cast<NetworkConnectionComponent>(buttonNetworkConnection[entityConnection]);
    if (!network)
        return;
    network->connect = true;
    network->serverPort = portServer;
    network->serverIp = ipServer;
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

    std::shared_ptr<DefaultTextComponent> defaultText = parseDefaultText(PATH_JSON);
    if (defaultText) {
        reg.register_component<IComponent>(defaultText->getType());
        reg.set_component<IComponent>(idxPacketEntities, defaultText, defaultText->getType());
    }

    reg.register_component<IComponent>("NetworkConnectionComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<NetworkConnectionComponent>(), "NetworkConnectionComponent");

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

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new ButtonInitSystem();
}
}
