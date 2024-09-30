/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemRight
*/

#include "MoveSystemRight.hpp"

#include "Position2DComponent.hpp"

MoveSystemRight::MoveSystemRight(void) :
    ASystem("MovementRightSystem")
{
}

std::function<void(ECS::Registry& reg)> MoveSystemRight::getFunction(void)
{
    return [this](ECS::Registry& reg) {
        updateRightPosition(reg);
    };
}

void MoveSystemRight::updateRightPosition(ECS::Registry& entityManager)
{
    std::cout << "START" << std::endl;
    std::cout << entityManager.get_components<IComponent>("Position2DComponent").size() << std::endl;
    ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
    for (int index = 0; index < PositionComponentArray.size(); index++) {
        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[index].get());
        std::cout << "X: [" << position->x << "]" << std::endl;
        std::cout << "Y: [" << position->y << "]" << std::endl;
        position->x = 4;
        position->y = 144;
    }
    std::cout << "END" << std::endl;
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveSystemRight();
}
