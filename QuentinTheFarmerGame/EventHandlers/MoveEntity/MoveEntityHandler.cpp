/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MoveEntityHandler.cpp
*/

#include <iostream>

#include "AEvent.hpp"
#include "ABIServer.hpp"
#include "MoveEntityHandler.hpp"

MoveEntityHandler::MoveEntityHandler(std::string eventType)
    : AEventHandler("MoveEntity") {}

bool MoveEntityHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {

        if (event->getValues().size() != 3)
            throw MoveEntityHandlerError("Event values corrupted.");

        int indexEntity = std::any_cast<int>(event->getValues()[0]);
        float posX = std::any_cast<float>(event->getValues()[1]);
        float posY = std::any_cast<float>(event->getValues()[2]);

        std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args;

        args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(indexEntity)));
        args.push_back(std::make_pair(ABINetwork::Type::Float, posX));
        args.push_back(std::make_pair(ABINetwork::Type::Float, posY));

        ABINetwork::sendUpdateComponent(networkUnit, "Position2DComponent", 3, args);

    } catch (const std::exception &e) {
        throw MoveEntityHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new MoveEntityHandler();
    }
}
