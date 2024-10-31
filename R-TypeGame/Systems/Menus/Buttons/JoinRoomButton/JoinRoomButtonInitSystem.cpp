/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AEvent.hpp"
#include "TextComponent.hpp"
#include "DrawComponent.hpp"
#include "EntityIdComponent.hpp"
#include "AButtonInitSystem.hpp"
#include "DefaultTextComponent.hpp"
#include "JoinRoomButtonInitSystem.hpp"

static void handleThis(ECS::Registry &reg, int idxPacketEntities)
{
    std::string roomName = "";
    std::string roomPassword = "";

    try {
        ECS::SparseArray<IComponent> textComponents = reg.get_components<IComponent>("TextComponent");
        ECS::SparseArray<IComponent> defaultTextComponents = reg.get_components<IComponent>("DefaultTextComponent");
        ECS::SparseArray<IComponent> entityIds = reg.get_components<IComponent>("EntityIdComponent");
        int roomId = -1;

        if (textComponents.size() > idxPacketEntities && entityIds.size() > idxPacketEntities) {
            std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(textComponents[idxPacketEntities]);
            std::shared_ptr<EntityIdComponent> entityId = std::dynamic_pointer_cast<EntityIdComponent>(entityIds[idxPacketEntities]);
            if (!text || !entityId)
                return;
            if (text->text == "Join")
                roomId = entityId->id;
        }

        for (ECS::entity_t entity = 0; entity < textComponents.size() && entity < defaultTextComponents.size(); entity++) {
            std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(textComponents[entity]);
            std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTextComponents[entity]);
            std::shared_ptr<EntityIdComponent> entityId = std::dynamic_pointer_cast<EntityIdComponent>(entityIds[entity]);
            if (!text || !defaultText || !entityId)
                continue;
            if (defaultText->text == "Room Infos" && entityId->id == roomId) {
                roomName = text->text.substr(0, text->text.find(" - "));
            }
            if (defaultText->text == "Password" && entityId->id == roomId) {
                roomPassword = text->text;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::vector<std::any> values = {};
    values.push_back(std::string(roomName));
    values.push_back(std::string(roomPassword));
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("JoinRoom", values);
    reg.addEvent(event);
}

JoinRoomButtonInitSystem::JoinRoomButtonInitSystem(ECS::Registry &reg, int idxPacketEntities, std::size_t roomId)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, JSON_PATH, callback);

    std::shared_ptr<IComponent> entityId = std::make_shared<EntityIdComponent>(roomId);
    reg.set_component(idxPacketEntities, entityId, "EntityIdComponent");

    std::shared_ptr<IComponent> draw = std::make_shared<DrawComponent>();
    reg.set_component(idxPacketEntities, draw, "DrawComponent");
}
