/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemDown
*/

#include "MoveSystemDown.hpp"

MoveSystemDown::MoveSystemDown(void) :
    ASystem("MovementUpSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemDown::getFunction(void)
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateDownPosition(reg, idxPacketEntities);
    };
}

void MoveSystemDown::updateDownPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

    Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
    SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

    position->y += speed->speedY;
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemDown();
}
