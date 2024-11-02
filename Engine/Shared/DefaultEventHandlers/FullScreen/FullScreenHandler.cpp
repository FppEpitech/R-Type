/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** FullScreenHandler.cpp
*/

#include "FullScreenHandler.hpp"

FullScreenHandler::FullScreenHandler(std::string eventType)
    : AEventHandler("FullScreenHandler") {}

bool FullScreenHandler::processEvent(std::shared_ptr<IEvent> event,
                                  std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                  std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                  std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;
        int key = graphicLib->getKeyPressedInput();
        if (key == KEY_F2)
            graphicLib->changeFullscreen();
        else
            return true;
    } catch (const std::exception &e) {
        throw FullScreenHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new FullScreenHandler();
    }
}
