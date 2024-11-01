/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemLeft
*/

#include "AEvent.hpp"
#include "MoveSystemLeft.hpp"

MoveSystemLeft::MoveSystemLeft() :
    ASystem("MovementLeftSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemLeft::getFunction()
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateLeftPosition(reg, idxPacketEntities);
    };
}

void MoveSystemLeft::updateLeftPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(entityManager._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> DrawComponentArray = entityManager.get_components<IComponent>("DrawComponent");
        if (DrawComponentArray.size() <= idxPacketEntities)
            return;
        DrawComponent* draw = dynamic_cast<DrawComponent*>(DrawComponentArray[idxPacketEntities].get());
        if (!draw || !draw->draw)
            return;

        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

        if (PositionComponentArray.size() <= idxPacketEntities || SpeedComponentArray.size() <= idxPacketEntities)
            return;

        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

        if (!position || !speed)
            return;

        if (position->x - speed->speedX < 0)
            position->x = 0;
        else
            position->x = position->x - speed->speedX;

        std::vector<std::any> valuesMoveEntity = {};
        valuesMoveEntity.push_back(idxPacketEntities);
        valuesMoveEntity.push_back(position->x);
        valuesMoveEntity.push_back(position->y);
        std::shared_ptr<IEvent> eventMoveEntity = std::make_shared<AEvent>("MoveEntity", valuesMoveEntity);
        entityManager.addEvent(eventMoveEntity);
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new MoveSystemLeft();
}
}
