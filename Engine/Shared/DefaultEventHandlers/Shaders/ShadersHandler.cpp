/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShadersHandler.cpp
*/

#include "ShadersHandler.hpp"

ShadersHandler::ShadersHandler(std::string eventType)
    : AEventHandler("ShadersHandler") {}

bool ShadersHandler::processEvent(std::shared_ptr<IEvent> event,
                                  std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                  std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                  std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;
        int key = graphicLib->getKeyPressedInput();
        if (key == KEY_RIGHT)
            graphicLib->nextCurrentShader();
        else if (key == KEY_LEFT)
            graphicLib->previousCurrentShader();
        else if (key == KEY_UP)
            graphicLib->nextShaderIntensity();
        else if (key == KEY_DOWN)
            graphicLib->previousShaderIntensity();
    } catch (const std::exception &e) {
        throw ShadersHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new ShadersHandler();
    }
}
