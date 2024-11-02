/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlaySoundsHandler.cpp
*/

#include "PlaySoundsHandler.hpp"

PlaySoundsHandler::PlaySoundsHandler(std::string eventType)
    : AEventHandler("DefaultPlaySounds") {}

bool PlaySoundsHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;
        std::string soundPath = std::any_cast<std::string>(event->getValues()[0]);
        graphicLib->playSound(soundPath);
    } catch (const std::exception &e) {
        throw PlaySoundsHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new PlaySoundsHandler();
    }
}
