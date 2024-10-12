/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemRight
*/

#include "MoveSystemRight.hpp"

MoveSystemRight::MoveSystemRight() :
    ASystem("MovementRightSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemRight::getFunction()
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateRightPosition(reg, idxPacketEntities);
    };
}

void MoveSystemRight::updateRightPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");

        if (PositionComponentArray.size() <= idxPacketEntities || SpeedComponentArray.size() <= idxPacketEntities)
            return;

        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());

        if (!position || !speed)
            return;
        position->x += speed->speedX;

        entityManager.messageType = 0x01;
        entityManager.payload.clear();

        std::string componentType = "Position2DComponent";
        entityManager.payload.push_back(static_cast<uint8_t>(componentType.size()));
        entityManager.payload.insert(entityManager.payload.end(), componentType.begin(), componentType.end());


        entityManager.payload.push_back(static_cast<uint8_t>(idxPacketEntities >> 24) & 0xFF);
        entityManager.payload.push_back(static_cast<uint8_t>((idxPacketEntities >> 16) & 0xFF));
        entityManager.payload.push_back(static_cast<uint8_t>((idxPacketEntities >> 8) & 0xFF));
        entityManager.payload.push_back(static_cast<uint8_t>((idxPacketEntities) & 0xFF));

        float x = position->x;
        uint8_t* xBytes = reinterpret_cast<uint8_t*>(&x);
        entityManager.payload.insert(entityManager.payload.end(), xBytes, xBytes + sizeof(float));

        float y = position->y;
        uint8_t* yBytes = reinterpret_cast<uint8_t*>(&y);
        entityManager.payload.insert(entityManager.payload.end(), yBytes, yBytes + sizeof(float));

    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new MoveSystemRight();
}
}
