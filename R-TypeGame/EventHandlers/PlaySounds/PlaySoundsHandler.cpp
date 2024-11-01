/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlaySoundsHandler.cpp
*/

#include "PlaySoundsHandler.hpp"
#include "AEvent.hpp"

PlaySoundsHandler::PlaySoundsHandler(std::string eventType)
    : AEventHandler("PlaySounds") {}

bool PlaySoundsHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;
        int key = graphicLib->getKeyDownInput();
        if (graphicLib->isMouseButtonDown(IGraphic::MouseButtons::MOUSE_LEFT))
            key = MOUSE_LEFT_CLICK;
        if (graphicLib->isMouseButtonDown(IGraphic::MouseButtons::MOUSE_RIGHT))
            key = MOUSE_RIGHT_CLICK;
        if (graphicLib->isMouseButtonDown(IGraphic::MouseButtons::MOUSE_MIDDLE))
            key = MOUSE_MIDDLE_CLICK;
        if (sceneManager->getSoundMap().contains(static_cast<KEY_MAP>(key))) {
            std::string path = sceneManager->getSoundMap().at(static_cast<KEY_MAP>(key));
            std::vector<std::any> soundPath = {path};
            std::shared_ptr<IEvent> event = std::make_shared<AEvent>("DefaultPlaySounds", soundPath);
            sceneManager->getRegistry()->addEvent(event);
        }
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
