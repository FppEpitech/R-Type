/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlayerDeathHandler.cpp
*/
#include "ABIClient.hpp"
#include "ABIServer.hpp"
#include "AEvent.hpp"
#include "PlayerDeathHandler.hpp"
#include <iostream>

PlayerDeathHandler::PlayerDeathHandler(std::string eventType)
    : AEventHandler("PlayerDeath") {}

bool PlayerDeathHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {

        if (event->getValues().size() != 2)
            throw PlayerDeathHandlerError("Event values corrupted.");

        std::size_t entity = std::any_cast<std::size_t>(event->getValues()[0]);
        uint32_t token = std::any_cast<uint32_t>(event->getValues()[1]);

        if (ABINetwork::getTypeOfNetwork(networkUnit) != ABINetwork::INetworkUnit::TypeOfNetwork::TYPE_CLIENT) {
            std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> argsUpdate;
            argsUpdate.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(entity)));
            argsUpdate.push_back(std::make_pair(ABINetwork::Type::Bool, false));
            ABINetwork::sendUpdateComponent(networkUnit, "DrawComponent", 2, argsUpdate);
            return true;
        }

        if (entity != sceneManager->getIndexPlayer())
            return true;

        ABINetwork::sendPacketLeaveRoom(networkUnit);
        ABINetwork::disconnectToServer(networkUnit);

        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, END_SCENE);
        sceneManager->changeScene(scenePair);

    } catch (const std::exception &e) {
        throw PlayerDeathHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new PlayerDeathHandler();
    }
}
