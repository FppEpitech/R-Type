/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemRight
*/

#include "MoveSystemRight.hpp"

MoveSystemRight::MoveSystemRight(void) :
    ASystem("MovementRightSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemRight::getFunction(void)
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateRightPosition(reg, idxPacketEntities);
    };
}

void MoveSystemRight::updateRightPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

        Position3DComponent* position = dynamic_cast<Position3DComponent*>(PositionComponentArray[idxPacketEntities].get());
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

        position->x += speed->speedX;
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemRight();
}
