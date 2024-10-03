/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemUp
*/

#include "MoveSystemUp.hpp"

MoveSystemUp::MoveSystemUp() :
    ASystem("MovementUpSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemUp::getFunction()
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateUpPosition(reg, idxPacketEntities);
    };
}

void MoveSystemUp::updateUpPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

        position->y -= speed->speedY;
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemUp();
}
