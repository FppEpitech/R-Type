/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** InitConsumptionSystem.cpp
*/

#include <iostream>

#include "InitConsumptionSystem.hpp"
#include "Draw/DrawComponent.hpp"
#include "Text/TextComponent.hpp"
#include "TextPosition2D/TextPosition2DComponent.hpp"
#include "DefaultText/DefaultTextComponent.hpp"
#include "Size1D/Size1DComponent.hpp"
#include "FontPath/FontPathComponent.hpp"
#include "Colour/ColourComponent.hpp"

InitConsumptionSystem::InitConsumptionSystem() : ASystem("InitConsumptionSystem") {}

void InitConsumptionSystem::_handlePlaySounds(ECS::Registry &reg, int idxPacketEntities)
{
    reg.register_component<IComponent>("DefaultTextComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DefaultTextComponent>("UpdateConsumption"), "DefaultTextComponent");
    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(false), "DrawComponent");
    reg.register_component<IComponent>("TextComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<TextComponent>(), "TextComponent");
    reg.register_component<IComponent>("TextPosition2DComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<TextPosition2DComponent>(2,2), "TextPosition2DComponent");
    reg.register_component<IComponent>("Size1DComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<Size1DComponent>(10), "Size1DComponent");
    reg.register_component<IComponent>("FontPathComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<FontPathComponent>(), "FontPathComponent");
    reg.register_component<IComponent>("ColourComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<ColourComponent>(255, 255, 255, 255), "ColourComponent");
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new InitConsumptionSystem();
}
}
