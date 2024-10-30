/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SendRoomInfosHandler.cpp
*/

#include <iostream>

#include "AEvent.hpp"
#include "TextComponent.hpp"
#include "Position2DComponent.hpp"
#include "EntityListComponent.hpp"
#include "SendRoomInfosHandler.hpp"
#include "TextPosition2DComponent.hpp"
#include "JoinRoomButton/JoinRoomButtonInitSystem.hpp"
#include "RoomInfosTextBox/RoomInfoTextBoxInitSystem.hpp"
#include "JoinRoomPasswordTextBox/JoinRoomPasswordTextBoxInitSystem.hpp"

SendRoomInfosHandler::SendRoomInfosHandler(std::string eventType)
    : AEventHandler(SEND_ROOMS_INFOS) {}

static std::vector<RoomInfos> getRoomInfosFromEvent(std::shared_ptr<ECS::Registry> reg, int idxEntity, std::shared_ptr<IEvent> event)
{
    std::vector<RoomInfos> roomsInfos = {};
    try {
        // TODO: Get the rooms information from the event values
        // If needed, refactor a bit the formating of the data
        if (event->getValues().size() != 1)
            return roomsInfos;
        roomsInfos = std::any_cast<std::vector<RoomInfos>>(event->getValues()[0]);
    } catch (const std::exception &e) {
        return roomsInfos;
    }
    return roomsInfos;
}

bool SendRoomInfosHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        ECS::entity_t entity = 0;
        std::shared_ptr<ECS::Registry> reg = sceneManager->getRegistry();
        ECS::SparseArray<IComponent> entityList = reg->get_components<IComponent>("EntityListComponent");
        if (entityList.size() <= entity)
            return false;
        for (; entityList.size() > entity; entity++) {
            std::shared_ptr<EntityListComponent> entityListComp = std::dynamic_pointer_cast<EntityListComponent>(entityList[entity]);
            if (!entityListComp)
                continue;
            if (entityListComp->listType == "RoomList")
                break;
        }
        std::vector<RoomInfos> roomsInfos = getRoomInfosFromEvent(reg, entity, event);

        std::size_t offset = 0;
        for (auto &room : roomsInfos) {
            ECS::entity_t roomInfoId = reg->spawn_entity();
            ECS::entity_t joinBtnId = reg->spawn_entity();
            ECS::entity_t passwordTextBoxId = reg->spawn_entity();
            RoomInfoTextBoxInitSystem(*reg, roomInfoId, PATH_JSON_INFO_ROOMS);
            JoinRoomButtonInitSystem(*reg, joinBtnId, roomInfoId);
            if (room.isPrivate)
                JoinRoomPasswordTextBoxInitSystem(*reg, passwordTextBoxId, roomInfoId);

            ECS::SparseArray<IComponent> positions = reg->get_components<IComponent>("Position2DComponent");
            ECS::SparseArray<IComponent> textPositions = reg->get_components<IComponent>("TextPosition2DComponent");
            ECS::SparseArray<IComponent> texts = reg->get_components<IComponent>("TextComponent");

            if (positions.size() <= roomInfoId || textPositions.size() <= roomInfoId || texts.size() <= roomInfoId)
                continue;
            if (positions.size() <= joinBtnId || textPositions.size() <= joinBtnId || texts.size() <= joinBtnId)
                continue;

            std::shared_ptr<Position2DComponent> roomInfoPosition = std::dynamic_pointer_cast<Position2DComponent>(positions[roomInfoId]);
            std::shared_ptr<TextPosition2DComponent> roomInfoTextPosition = std::dynamic_pointer_cast<TextPosition2DComponent>(textPositions[roomInfoId]);
            std::shared_ptr<TextComponent> roomInfoText = std::dynamic_pointer_cast<TextComponent>(texts[roomInfoId]);

            std::shared_ptr<Position2DComponent> joinBtnPosition = std::dynamic_pointer_cast<Position2DComponent>(positions[joinBtnId]);
            std::shared_ptr<TextPosition2DComponent> joinBtnTextPosition = std::dynamic_pointer_cast<TextPosition2DComponent>(textPositions[joinBtnId]);

            if (!roomInfoPosition || !roomInfoTextPosition || !roomInfoText || !joinBtnPosition || !joinBtnTextPosition)
                continue;
            roomInfoPosition->y += offset;
            roomInfoTextPosition->y += offset;
            roomInfoText->text = room.roomName + " - " + std::to_string(room.nbPlayers) + "/" + std::to_string(room.maxPlayers) + " - " + room.scene + " - " + (room.isPrivate ? "Private" : "Public");
            joinBtnPosition->y += offset;
            joinBtnTextPosition->y += offset;
            offset += BUTTON_OFFSET;

            if (positions.size() <= passwordTextBoxId || textPositions.size() <= passwordTextBoxId || texts.size() <= passwordTextBoxId)
                continue;

            std::shared_ptr<Position2DComponent> passwordTextBoxPosition = std::dynamic_pointer_cast<Position2DComponent>(positions[passwordTextBoxId]);
            std::shared_ptr<TextPosition2DComponent> passwordTextBoxTextPosition = std::dynamic_pointer_cast<TextPosition2DComponent>(textPositions[passwordTextBoxId]);

            if (!passwordTextBoxPosition || !passwordTextBoxTextPosition)
                continue;
            passwordTextBoxPosition->y += offset - BUTTON_OFFSET;
            passwordTextBoxTextPosition->y += offset - BUTTON_OFFSET;
        }
    } catch (const std::exception &e) {
        throw SendRoomInfosHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new SendRoomInfosHandler();
    }
}
