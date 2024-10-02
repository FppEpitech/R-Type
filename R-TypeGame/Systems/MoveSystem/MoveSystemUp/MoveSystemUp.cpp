/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemUp
*/

#include "MoveSystemUp.hpp"

MoveSystemUp::MoveSystemUp(void) :
    ASystem("MovementUpSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemUp::getFunction(void)
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateUpPosition(reg, idxPacketEntities);
    };
}

void MoveSystemUp::updateUpPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    std::cout << "HERE 1" << std::endl;
    try {
        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
        std::cout << "HERE 2" << std::endl;
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");
        std::cout << "HERE 3" << std::endl;

        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
        std::cout << "HERE 4" << std::endl;
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());
        std::cout << "HERE 5" << std::endl;

        position->y -= speed->speedY;
        std::cout << "After position->y: " << position->y << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemUp();
}
