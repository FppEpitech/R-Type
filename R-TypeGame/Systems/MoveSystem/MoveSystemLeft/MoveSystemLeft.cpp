/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemLeft
*/

#include "MoveSystemLeft.hpp"

MoveSystemLeft::MoveSystemLeft(void) :
    ASystem("MovementLeftSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemLeft::getFunction(void)
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateLeftPosition(reg, idxPacketEntities);
    };
}

void MoveSystemLeft::updateLeftPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
    ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

    Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
    SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

    position->x = position->x - speed->speedX;
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemLeft();
}
