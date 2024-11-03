/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBoxesDrawHandler.cpp
*/

#include "../../../Ecs/Src/Events/AEvent.hpp"
#include "HitBoxComponent.hpp"
#include "HitBoxesDrawHandler.hpp"

HitBoxesDrawHandler::HitBoxesDrawHandler(std::string eventType)
    : AEventHandler("HitBoxesDraw") {}

bool HitBoxesDrawHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;

        if (event->getValues().size() != 5)
            throw HitBoxesDrawHandlerError("Error while processing the event: invalid number of arguments");

        std::vector<HitBox> hitBoxes = std::any_cast<std::vector<HitBox>>(event->getValues()[0]);
        unsigned int r = std::any_cast<unsigned int>(event->getValues()[1]);
        unsigned int g = std::any_cast<unsigned int>(event->getValues()[2]);
        unsigned int b = std::any_cast<unsigned int>(event->getValues()[3]);
        unsigned int a = std::any_cast<unsigned int>(event->getValues()[4]);

        graphicLib->drawHitBoxes(hitBoxes, r, g, b, a);
    } catch (const std::exception &e) {
        throw HitBoxesDrawHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new HitBoxesDrawHandler();
    }
}
