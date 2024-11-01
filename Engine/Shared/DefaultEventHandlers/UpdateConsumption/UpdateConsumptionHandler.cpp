/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** UpdateConsumptionHandler.cpp
*/

#include "UpdateConsumptionHandler.hpp"
#include "../DefaultComponents/Text/TextComponent.hpp"
#include "../DefaultComponents/DefaultText/DefaultTextComponent.hpp"

UpdateConsumptionHandler::UpdateConsumptionHandler(std::string eventType)
    : AEventHandler("DefaultUpdateConsumption") {}

bool UpdateConsumptionHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (!graphicLib)
            return true;
        std::shared_ptr<ECS::Registry> reg = sceneManager->getRegistry();
        std::lock_guard<std::mutex> lock(reg->_myBeautifulMutex);
        ECS::SparseArray<IComponent> Text = reg->get_components<IComponent>("TextComponent");
        ECS::SparseArray<IComponent> DefaultText = reg->get_components<IComponent>("DefaultTextComponent");
        for (ECS::entity_t entity = 0; entity < Text.size() && entity < DefaultText.size(); entity++) {
            std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(DefaultText[entity]);
            std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(Text[entity]);
            if (!defaultText || !text || defaultText->text != "999")
                continue;
            std::ostringstream consumption;
            consumption << "CPU: " << sceneManager->GetConsumptionCompute().ComputeCPUInfo() << "%\nRAM: " << sceneManager->GetConsumptionCompute().ComputeRAMInfo() << "MB";
            text->text = consumption.str();
        }
    } catch (const std::exception &e) {
        throw UpdateConsumptionHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new UpdateConsumptionHandler();
    }
}
