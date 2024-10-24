/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AEventHandler.hpp
*/

#pragma once

#include "IEventHandler.hpp"

class AEventHandler : public IEventHandler {

    public:
        AEventHandler(std::string eventType = "");

        ~AEventHandler() = default;

        std::string getEventType() override;

        virtual bool processEvent(std::shared_ptr<IEvent> event, std::shared_ptr <SceneManager::ISceneManager> sceneManager, std::shared_ptr <ABINetwork::INetworkUnit> networkUnit, std::shared_ptr <IGraphic> graphicLib) override = 0;

    protected:

        std::string _eventType;
};
