/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CameraUpdateHandler.cpp
*/

#include "CameraUpdateHandler.hpp"

CameraUpdateHandler::CameraUpdateHandler(std::string eventType)
    : AEventHandler("UpdateCamera") {}

bool CameraUpdateHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;
        std::vector<float> position;
        position.push_back(std::any_cast<float>(event->getValues()[0]));
        position.push_back(std::any_cast<float>(event->getValues()[1]));
        position.push_back(std::any_cast<float>(event->getValues()[2]));

        graphicLib->setCameraSettings(position[0], position[1] + 20, position[2] - 20, position[0], position[1], position[2], 0, 1, 0, 45);
    } catch (const std::exception &e) {
        throw CameraUpdateHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new CameraUpdateHandler();
    }
}
