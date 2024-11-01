/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateRoomButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AEvent.hpp"
#include "DrawComponent.hpp"
#include "TextComponent.hpp"
#include "ScaleComponent.hpp"
#include "AButtonInitSystem.hpp"
#include "CheckableComponent.hpp"
#include "ClickableComponent.hpp"
#include "Position2DComponent.hpp"
#include "DefaultTextComponent.hpp"
#include "TextureRectComponent.hpp"
#include "CreateRoomButtonInitSystem.hpp"
#include "ButtonTexturePathComponent.hpp"

CreateRoomButtonInitSystem::CreateRoomButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> clickables = reg.get_components<IComponent>("ClickableComponent");
    ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> buttonTexturePaths = reg.get_components<IComponent>("ButtonTexturePathComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");
    ECS::SparseArray<IComponent> checkables = reg.get_components<IComponent>("CheckableComponent");

    ECS::entity_t roomName = 0;
    ECS::entity_t roomPassword = 0;
    ECS::entity_t roomMaxPlayer = 0;
    std::vector<bool> isFilled = {false, false, false, false, false};

    for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1 && texts.size() >= entity + 1; entity++) {
        std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
        std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
        std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
        std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(texts[entity]);

        std::shared_ptr<DefaultTextComponent> defaultText = nullptr;
        std::shared_ptr<ClickableComponent> clickable = nullptr;
        std::shared_ptr<CheckableComponent> checkable = nullptr;

        if (checkables.size() >= entity + 1 )
            checkable = std::dynamic_pointer_cast<CheckableComponent>(checkables[entity]);
        if (clickables.size() >= entity + 1 && defaultTexts.size() >= entity + 1) {
            clickable = std::dynamic_pointer_cast<ClickableComponent>(clickables[entity]);
            defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[entity]);
        }

        if (!position || !textureRect || !scale || !buttonTexturePath || !text)
            continue;

        if (clickable && defaultText) {
            if (defaultText->text == "Room name") {
                roomName = entity;
                isFilled[0] = true;
            } if (defaultText->text == "Password") {
                roomPassword = entity;
                isFilled[1] = true;
            } if (defaultText->text == "Max player number") {
                roomMaxPlayer = entity;
                isFilled[2] = true;
            }
        }

        if (checkable) {
            if (checkable->isChecked && text->text == "Private")
                isFilled[3] = true;
            if (checkable->isChecked && text->text == "Cheats")
                isFilled[4] = true;
        }
    }

    if (!isFilled[0] || !isFilled[1] || !isFilled[2])
        return;
    std::shared_ptr<TextComponent> roomNameText = std::dynamic_pointer_cast<TextComponent>(texts[roomName]);
    std::shared_ptr<TextComponent> roomPasswordText = std::dynamic_pointer_cast<TextComponent>(texts[roomPassword]);
    std::shared_ptr<TextComponent> roomMaxPlayerText = std::dynamic_pointer_cast<TextComponent>(texts[roomMaxPlayer]);

    if (roomNameText->text.empty() || (roomPasswordText->text.empty() && isFilled[3]) || roomMaxPlayerText->text.empty())
        return;
    if (roomNameText->text == "Room name" || (roomPasswordText->text == "Password" && isFilled[3]) || roomMaxPlayerText->text == "Max player number")
        return;

    int playerMax = atoi(roomMaxPlayerText->text.c_str());
    if (playerMax <= 0)
        return;

    std::vector<std::any> valuesCreateRoom = {};
    valuesCreateRoom.push_back(std::string(roomNameText->text));
    valuesCreateRoom.push_back(std::string(roomPasswordText->text));
    valuesCreateRoom.push_back(int(playerMax));
    valuesCreateRoom.push_back(bool(isFilled[3]));
    valuesCreateRoom.push_back(bool(isFilled[4]));
    std::shared_ptr<IEvent> eventCreateRoom = std::make_shared<AEvent>("CreateRoom", valuesCreateRoom);
    reg.addEvent(eventCreateRoom);
}

void CreateRoomButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);

    std::shared_ptr<IComponent> draw = std::make_shared<DrawComponent>();
    reg.set_component(idxPacketEntities, draw, "DrawComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new CreateRoomButtonInitSystem();
    }
}
