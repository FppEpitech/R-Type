/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "PlayerComponent.hpp"
#include "MobComponent.hpp"
#include "ScaleComponent.hpp"
#include "TextureRectComponent.hpp"
#include "ShootTypeComponent.hpp"
#include "MobSpeOneShootInitSystem.hpp"
#include "MobSpeTwoShootInitSystem.hpp"

ShootSystem::ShootSystem() :
    ASystem("ShootSystemMob")
{
}

void ShootSystem::_shootIfNeeded(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> mobs = reg.get_components<IComponent>("MobComponent");
        std::cout << "BEFORE" << std::endl;
        ECS::SparseArray<IComponent> shootTypes = reg.get_components<IComponent>("ShootTypeComponent");
        std::cout << "AFTER" << std::endl;
        ECS::SparseArray<IComponent> TextRec = reg.get_components<IComponent>("TextureRectComponent");
        std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();

        for (auto entity: reg.getEntities()) {
            if (entity >= mobs.size() || entity >= positions.size() || entity >= shootTypes.size() || entity >= TextRec.size())
                continue;
            std::shared_ptr<MobComponent> mob = std::dynamic_pointer_cast<MobComponent>(mobs[entity]);
            if (!mob)
                continue;
            std::chrono::duration<float> elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - mob->clock);
            if (elapsedTime.count() >= mob->shootSpeed) {
                mob->clock = std::chrono::high_resolution_clock::now();
                std::shared_ptr<Position2DComponent> positionMob = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
                if (!positionMob)
                    continue;
                ShootTypeComponent::ShootType shootType = std::dynamic_pointer_cast<ShootTypeComponent>(shootTypes[entity])->type;
                if (shootType == ShootTypeComponent::ShootType::NONE)
                    continue;
                std::string mobSpritePath = std::dynamic_pointer_cast<TextureRectComponent>(TextRec[entity])->path;
                for (int i = 0; i < shootType + 1; i++) {
                    ECS::entity_t shoot = reg.spawn_entity();
                    if (mobSpritePath == "./Assets/mob-spe-shot-1.gif") {
                        MobSpeOneShootInitSystem().getFunction()(reg, shoot);
                    } else if (mobSpritePath == "./Assets/shots.gif") {
                        ShootInitSystem().getFunction()(reg, shoot);
                    } else {
                        MobSpeTwoShootInitSystem().getFunction()(reg, shoot);
                    }
                    positions = reg.get_components<IComponent>("Position2DComponent");
                    if (positions.size() <= shoot)
                        return;
                    std::shared_ptr <Position2DComponent> positionShoot = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
                    if (!positionShoot)
                        return;
                    ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
                    if (scales.size() <= entity)
                        return;
                    std::shared_ptr <ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
                    if (!scale)
                        return;
                    ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
                    if (texturesRect.size() <= entity)
                        return;
                    std::shared_ptr <TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
                    if (!textureRect)
                        return;
                    if (mobSpritePath == "./Assets/mob-spe-shot-1.gif") {
                        positionShoot->x = positionMob->x + ((textureRect->width / 2) * scale->scale);
                        positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale) + (((i - 3) * 45) * scale->scale);
                    } else if (mobSpritePath == "./Assets/shots.gif") {
                        positionShoot->x = positionMob->x + ((textureRect->width / 2) * scale->scale);
                        positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale);
                    } else {
                        positionShoot->x = positionMob->x + ((textureRect->left) * scale->scale);
                        positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale);
                    }
                }
            }
        }
    } catch (std::exception e) {
        std::cout << "Error in ShootSystemMobs: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new ShootSystem();
    }
}
