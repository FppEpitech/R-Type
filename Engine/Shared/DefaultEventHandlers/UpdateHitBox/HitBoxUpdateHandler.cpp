/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBoxUpdateHandler.cpp
*/

#include "HitBoxComponent.hpp"
#include "HitBoxUpdateHandler.hpp"

HitBoxUpdateHandler::HitBoxUpdateHandler(std::string eventType)
    : AEventHandler("UpdateHitBox") {}

bool HitBoxUpdateHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        std::shared_ptr<ECS::Registry> reg = sceneManager->getRegistry();
        std::lock_guard<std::mutex> lock(reg->_myBeautifulMutex);
        if (!graphicLib)
            return true;

        if (event->getValues().size() != 6)
            throw HitBoxUpdateHandlerError("Error while processing the event: invalid number of arguments");

        std::vector<float> position;
        position.push_back(std::any_cast<float>(event->getValues()[0]));
        position.push_back(std::any_cast<float>(event->getValues()[1]));
        position.push_back(std::any_cast<float>(event->getValues()[2]));
        float scale = std::any_cast<float>(event->getValues()[3]);
        std::string objPath = std::any_cast<std::string>(event->getValues()[4]);
        int idxEntity = std::any_cast<int>(event->getValues()[5]);

        ECS::SparseArray<IComponent> hitBoxes = reg->get_components<IComponent>("HitBoxComponent");
        if (hitBoxes.size() <= idxEntity)
            return true;
        std::shared_ptr<HitBoxComponent> hitBox = std::dynamic_pointer_cast<HitBoxComponent>(hitBoxes[idxEntity]);
        if (!hitBox)
            return true;
        hitBox->hitBoxes.clear();
        std::vector<HitBox> newHitBoxes = graphicLib->getHitBoxesFromModel(objPath, position[0], position[1], position[2], scale);
        for (auto &newHitBox : newHitBoxes)
            hitBox->hitBoxes.push_back(newHitBox);
    } catch (const std::exception &e) {
        throw HitBoxUpdateHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new HitBoxUpdateHandler();
    }
}
