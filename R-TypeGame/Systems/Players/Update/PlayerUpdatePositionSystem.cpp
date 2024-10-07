/*
** EPITECH PROJECT, 2024
** PlayerUpdatePositionSystem
** File description:
** PlayerUpdatePositionSystem
*/

#include "PlayerUpdatePositionSystem.hpp"
#include "PlayerComponent.hpp"
#include "Position2DComponent.hpp"

PlayerUpdatePositionSystem::PlayerUpdatePositionSystem() :
    ASystem("PlayerUpdatePositionSystem")
{
}

void PlayerUpdatePositionSystem::_updatePlayerPosition(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> players = reg.get_components<IComponent>("PlayerComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && players.size() >= entity + 1; entity++) {
            std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(players[entity]);
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            if (!position || !player)
                continue;
            position->x = 0;
            position->y = 0;
        }
    } catch (std::exception e) {
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new PlayerUpdatePositionSystem();
}
