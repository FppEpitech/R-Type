/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RegisterButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AEvent.hpp"
#include "TextComponent.hpp"
#include "ScaleComponent.hpp"
#include "AButtonInitSystem.hpp"
#include "ClickableComponent.hpp"
#include "Position2DComponent.hpp"
#include "DefaultTextComponent.hpp"
#include "TextureRectComponent.hpp"
#include "RegisterButtonInitSystem.hpp"
#include "ButtonTexturePathComponent.hpp"

RegisterButtonInitSystem::RegisterButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> clickables = reg.get_components<IComponent>("ClickableComponent");
    ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
    ECS::SparseArray<IComponent> buttonTexturePaths = reg.get_components<IComponent>("ButtonTexturePathComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");

    ECS::entity_t username = 0;
    ECS::entity_t password = 0;
    std::pair<bool, bool> isFilled = {false, false};

    for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && clickables.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1 && texts.size() >= entity + 1 && defaultTexts.size() >= entity + 1; entity++) {
        std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
        std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
        std::shared_ptr<ClickableComponent> clickable = std::dynamic_pointer_cast<ClickableComponent>(clickables[entity]);
        std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
        std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(texts[entity]);
        std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[entity]);
        if (!position || !textureRect || !clickable || !scale || !buttonTexturePath || !text || !defaultText)
            continue;
        if (defaultText->text == "Username") {
            username = entity;
            isFilled.first = true;
        } if (defaultText->text == "Password") {
            password = entity;
            isFilled.second = true;
        }
    }

    if (!isFilled.first || !isFilled.second)
        return;

    std::shared_ptr<TextComponent> usernameText = std::dynamic_pointer_cast<TextComponent>(texts[username]);
    std::shared_ptr<TextComponent> passwordText = std::dynamic_pointer_cast<TextComponent>(texts[password]);

    if (usernameText->text.empty() || passwordText->text.empty())
        return;
    if (usernameText->text == "Username" || passwordText->text == "Password")
        return;

    std::vector<std::any> values = {};
    values.push_back(std::string(REGISTER));
    values.push_back(usernameText->text);
    values.push_back(passwordText->text);
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("Register", values);
    reg.addEvent(event);
}

static void handleOther(ECS::Registry& reg, int idxPacketEntities)
{
}

void RegisterButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
        handleOther(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new RegisterButtonInitSystem();
    }
}
