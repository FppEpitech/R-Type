/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlayMusicHandler.cpp
*/

#include "PlayMusicHandler.hpp"

PlayMusicHandler::PlayMusicHandler(std::string eventType)
    : AEventHandler("PlayMusic") {}

bool PlayMusicHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        std::string musicPath = std::any_cast<std::string>(event->getValues()[0]);
        graphicLib->playMusic(musicPath);
    } catch (const std::exception &e) {
        throw PlayMusicHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new PlayMusicHandler();
    }
}
