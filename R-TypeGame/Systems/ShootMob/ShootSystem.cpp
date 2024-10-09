/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "Position2DComponent.hpp"
#include "PlayerComponent.hpp"
#include <MobComponent.hpp>
#include <ScaleComponent.hpp>
#include <TextureRectComponent.hpp>

ShootSystem::ShootSystem() :
    ASystem("ShootSystemMob")
{
}

void ShootSystem::_shootIfNeeded(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> mobs = reg.get_components<IComponent>("MobComponent");
        std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();

        for (auto entity: reg.getEntities()) {
            if (entity >= mobs.size() || entity >= positions.size())
                continue;
            std::shared_ptr<MobComponent> mob = std::dynamic_pointer_cast<MobComponent>(mobs[entity]);
            if (!mob)
                continue;
            std::chrono::duration<float> elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - mob->clock);

            if (elapsedTime.count() >= mob->shootSpeed) {
                mob->clock = std::chrono::high_resolution_clock::now();
                std::shared_ptr<Position2DComponent> positionMob = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
                ECS::entity_t shoot = reg.spawn_entity();
                ShootInitSystem().getFunction()(reg, shoot);
                positions = reg.get_components<IComponent>("Position2DComponent");
                std::shared_ptr<Position2DComponent> positionShoot = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
                if (!positionShoot)
                    return;
                ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
                if (scales.size() <= entity)
                    return;
                std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
                ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
                std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
                positionShoot->x = positionMob->x + ((textureRect->width / 2) * scale->scale);
                positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale);
            }
        }
    } catch (std::exception e) {
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new ShootSystem();
}
