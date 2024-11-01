/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "Draw/DrawComponent.hpp"

ShootSystem::ShootSystem() :
    ASystem("ShootSystem")
{
}

void ShootSystem::_shoot(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");

        if (draws.size() <= idxPacketEntities)
            return;
        std::shared_ptr<DrawComponent> drawPlayer = std::dynamic_pointer_cast<DrawComponent>(draws[idxPacketEntities]);
        if (!drawPlayer || !drawPlayer->draw)
            return;

        reg.messageType = 0x02;
        reg.payload.clear();

        std::string componentType = "ShootSystem";
        reg.payload.push_back(static_cast<uint8_t>(componentType.size()));
        reg.payload.insert(reg.payload.end(), componentType.begin(), componentType.end());

        reg.payload.push_back(static_cast<uint8_t>(idxPacketEntities >> 24) & 0xFF);
        reg.payload.push_back(static_cast<uint8_t>((idxPacketEntities >> 16) & 0xFF));
        reg.payload.push_back(static_cast<uint8_t>((idxPacketEntities >> 8) & 0xFF));
        reg.payload.push_back(static_cast<uint8_t>((idxPacketEntities) & 0xFF));

    } catch (std::exception e){
        std::cerr << "Error in Shoot system: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new ShootSystem();
    }
}
