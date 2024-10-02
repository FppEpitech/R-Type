/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemDown
*/

#include "MoveSystemDown.hpp"

MoveSystemDown::MoveSystemDown() :
    ASystem("MovementUpSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemDown::getFunction()
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateDownPosition(reg, idxPacketEntities);
    };
}

void MoveSystemDown::updateDownPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

        Position3DComponent* position = dynamic_cast<Position3DComponent*>(PositionComponentArray[idxPacketEntities].get());
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

        position->y += speed->speedY;
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemDown();
}