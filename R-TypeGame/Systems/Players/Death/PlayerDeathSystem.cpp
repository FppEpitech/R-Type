/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlayerDeathSystem.cpp
*/

#include "AEvent.hpp"
#include "LifeComponent.hpp"
#include "DrawComponent.hpp"
#include "PlayerComponent.hpp"
#include "PlayerDeathSystem.hpp"
#include "EntityListComponent.hpp"

#include <iostream>

PlayerDeathSystem::PlayerDeathSystem() :
    ASystem("PlayerDeathSystem")
{}

void PlayerDeathSystem::_playerDeathSystem(ECS::Registry& reg, int idxEntity)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> players = reg.get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> lives = reg.get_components<IComponent>("LifeComponent");
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");

        for (std::size_t entity = 0; entity < lives.size() && entity < players.size() && entity < draws.size(); entity++) {

            std::shared_ptr<LifeComponent> entityLife = std::dynamic_pointer_cast<LifeComponent>(lives[entity]);
            std::shared_ptr<PlayerComponent> entityPlayer = std::dynamic_pointer_cast<PlayerComponent>(players[entity]);
            std::shared_ptr<DrawComponent> entityDraw = std::dynamic_pointer_cast<DrawComponent>(draws[entity]);

            if (!entityLife || !entityPlayer || !entityDraw)
                continue;

            if (entityLife->life == 0 && entityDraw->draw) {

                entityDraw->draw = false;
                // reg.kill_entity(entity);

                std::vector<std::any> values = {};
                values.push_back(std::size_t(entity));
                values.push_back(uint32_t(entityPlayer->token));
                std::shared_ptr<IEvent> eventPlayerDeath = std::make_shared<AEvent>("PlayerDeath", values);
                reg.addEvent(eventPlayerDeath);
            }
        }
    } catch (const std::exception &e) {
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new PlayerDeathSystem();
    }
}
