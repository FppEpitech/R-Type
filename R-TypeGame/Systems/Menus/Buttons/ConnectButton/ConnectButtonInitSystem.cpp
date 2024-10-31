/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ConnectToServerButtonSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../../../../Engine/Ecs/Src/Events/AEvent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/TextParser/TextParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Scale/ScaleComponent.hpp"
#include "../AButton/AButtonInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultParser/DefaultTextParser/DefaultTextParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Clickable/ClickableComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Position2D/Position2DComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/TextureRect/TextureRectComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/ButtonState/ButtonStateComponent.hpp"
#include "ConnectButtonInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/NetworkConnection/NetworkConnectionComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/ButtonTexturePath/ButtonTexturePathComponent.hpp"

ConnectButtonInitSystem::ConnectButtonInitSystem() :
    ASystem("ButtonInitSystem")
{}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> clickables = reg.get_components<IComponent>("ClickableComponent");
    ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> buttonTexturePaths = reg.get_components<IComponent>("ButtonTexturePathComponent");
    ECS::SparseArray<IComponent> buttonText = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> buttonDefaultText = reg.get_components<IComponent>("DefaultTextComponent");
    ECS::SparseArray<IComponent> buttonNetworkConnection = reg.get_components<IComponent>("NetworkConnectionComponent");

    std::string ipServer = "";
    std::string portServer = "";
    ECS::entity_t entityConnection = 0;

    for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && clickables.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1 && buttonText.size() >= entity + 1 && buttonDefaultText.size() >= entity + 1; entity++) {
        std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
        std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
        std::shared_ptr<ClickableComponent> clickable = std::dynamic_pointer_cast<ClickableComponent>(clickables[entity]);
        std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
        std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(buttonText[entity]);
        std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(buttonDefaultText[entity]);
        if (!position || !textureRect || !clickable || !scale || !buttonTexturePath || !text || !defaultText)
            continue;
        if (defaultText->text == "Write the server IP") {
            if (defaultText->text == text->text)
                return;
            ipServer = text->text;
        }
        if (defaultText->text == "Write the server Port") {
            if (defaultText->text == text->text)
                return;
            portServer = text->text;
        }
    }
    for (ECS::entity_t entity = 0; buttonNetworkConnection.size() >= entity + 1; entity++) {
        std::shared_ptr<NetworkConnectionComponent> connection = std::dynamic_pointer_cast<NetworkConnectionComponent>(buttonNetworkConnection[entity]);
        if (!connection)
            continue;
        entityConnection = entity;
    }
    if (buttonNetworkConnection.size() <= entityConnection)
        return;
    std::shared_ptr<NetworkConnectionComponent> network = std::dynamic_pointer_cast<NetworkConnectionComponent>(buttonNetworkConnection[entityConnection]);
    if (!network)
        return;
    network->connect = true;
    network->serverPort = portServer;
    network->serverIp = ipServer;

    std::vector<std::any> values = {};
    values.push_back(std::string(ipServer));
    values.push_back(std::string(portServer));
    values.push_back(std::string(ACCOUNT_MANAGEMENT));
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("ConnectServer", values);
    reg.addEvent(event);
}

void ConnectButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);

    reg.register_component<IComponent>("NetworkConnectionComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<NetworkConnectionComponent>(), "NetworkConnectionComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new ConnectButtonInitSystem();
    }
}
