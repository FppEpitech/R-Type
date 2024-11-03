/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SinglePlayerHandler.cpp
*/
#include "ABIClient.hpp"
#include "ABIServer.hpp"
#include "AEvent.hpp"
#include "SinglePlayerHandler.hpp"
#include "IComponent.hpp"
#include "PlayerComponent.hpp"
#include "DrawComponent.hpp"

#include <iostream>

SinglePlayerHandler::SinglePlayerHandler(std::string eventType)
    : AEventHandler("SinglePlayer") {}

bool SinglePlayerHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        std::string sceneName = std::any_cast<std::string>(event->getValues()[0]);
        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, sceneName);
        sceneManager->changeScene(scenePair);

        std::shared_ptr<ECS::Registry> registry = sceneManager->getRegistry();
        if (!registry)
            return true;

        ECS::SparseArray<IComponent> PlayerComponentArray = registry->get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> DrawComponentArray = registry->get_components<IComponent>("DrawComponent");

        for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
            std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(PlayerComponentArray[index]);
            if (player && player->token == 0) {
                player->token = 1;

                networkUnit->setToken(1);
                sceneManager->setIndexPlayer(index);
                sceneManager->getRegistry()->identity = ECS::Registry::Identity::Serveur;

                if (index < DrawComponentArray.size()) {
                    std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(DrawComponentArray[index]);
                    if (draw)
                        draw->draw = true;
                }
                return true;
            }
        }
    } catch (const std::exception &e) {
        throw SinglePlayerHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new SinglePlayerHandler();
    }
}
