/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SwitchSceneHandler.cpp
*/

#include "AEvent.hpp"
#include "SwitchSceneHandler.hpp"
#include <iostream>

SwitchSceneHandler::SwitchSceneHandler(std::string eventType)
    : AEventHandler("SwitchScene") {}

bool SwitchSceneHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        std::string sceneName = std::any_cast<std::string>(event->getValues()[0]);
        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, sceneName);
        sceneManager->changeScene(scenePair);
    } catch (const std::exception &e) {
        throw SwitchSceneHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new SwitchSceneHandler();
    }
}
