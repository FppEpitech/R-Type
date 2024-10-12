/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootDamageSystem.cpp
*/

#include "MobComponent.hpp"
#include "LifeComponent.hpp"
#include "ScaleComponent.hpp"
#include "ShootComponent.hpp"
#include "PlayerComponent.hpp"
#include "ShootDamageSystem.hpp"
#include "Position2DComponent.hpp"
#include "TextureRectComponent.hpp"

ShootDamageSystem::ShootDamageSystem() :
    ASystem("ShootDamageSystem") {}

static bool isColliding(float rectRatio,
        std::shared_ptr<Position2DComponent> pos1, std::shared_ptr<ScaleComponent> scale1, std::shared_ptr<TextureRectComponent> texture1,
        std::shared_ptr<Position2DComponent> pos2, std::shared_ptr<ScaleComponent> scale2, std::shared_ptr<TextureRectComponent> texture2)
{
    if (!pos1 || !scale1 || !texture1 || !pos2 || !scale2 || !texture2)
        return false;
    std::vector<float> entity = {
        pos1->x + texture1->width * scale1->scale * (1 - rectRatio),
        pos1->x + texture1->width * scale1->scale * rectRatio,
        pos1->y + texture1->height * scale1->scale * (1 - rectRatio),
        pos1->y + texture1->height * scale1->scale * rectRatio
    };
    std::vector<float> shoot = {
        pos2->x,
        pos2->x + texture2->width * scale2->scale,
        pos2->y,
        pos2->y + texture2->height * scale2->scale
    };
    for (int i = 0; i < 2; ++i) {
        for (int j = 2; j < 4; ++j) {
            if ((entity[i] >= shoot[0] && entity[i] <= shoot[1] && entity[j] >= shoot[2] && entity[j] <= shoot[3]) ||
                (shoot[i] >= entity[0] && shoot[i] <= entity[1] && shoot[j] >= entity[2] && shoot[j] <= entity[3])) {
                return true;
            }
        }
    }
    return false;
}

template <typename TYPE>
static void areEntityShot(ECS::Registry &reg, ShootComponent::ShootType shootType, float rectRatio,
            ECS::SparseArray<IComponent> entities, ECS::SparseArray<IComponent> shoots,
            ECS::SparseArray<IComponent> positions, ECS::SparseArray<IComponent> textures,
            ECS::SparseArray<IComponent> scales, ECS::SparseArray<IComponent> lives)
{
    for (std::size_t entity = 0; entity < entities.size() && entity < lives.size() && entity < positions.size() && entity < textures.size() && entity < scales.size(); entity++) {
        std::shared_ptr<TYPE> entityComp = std::dynamic_pointer_cast<TYPE>(entities[entity]);
        std::shared_ptr<LifeComponent> entityLife = std::dynamic_pointer_cast<LifeComponent>(lives[entity]);
        std::shared_ptr<Position2DComponent> entityPos = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
        std::shared_ptr<TextureRectComponent> entityTexture = std::dynamic_pointer_cast<TextureRectComponent>(textures[entity]);
        std::shared_ptr<ScaleComponent> entityScale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
        if (!entityComp || !entityLife || !entityPos || !entityTexture || !entityScale)
            continue;
        for (std::size_t shoot = 0; shoot < shoots.size() && shoot < positions.size() && shoot < textures.size() && shoot < scales.size(); shoot++) {
            std::shared_ptr<ShootComponent> shootComp = std::dynamic_pointer_cast<ShootComponent>(shoots[shoot]);
            std::shared_ptr<Position2DComponent> shootPos = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
            std::shared_ptr<TextureRectComponent> shootTexture = std::dynamic_pointer_cast<TextureRectComponent>(textures[shoot]);
            std::shared_ptr<ScaleComponent> shootScale = std::dynamic_pointer_cast<ScaleComponent>(scales[shoot]);
            std::shared_ptr<TYPE> entityObject = std::dynamic_pointer_cast<TYPE>(entities[entity]);
            if (!shootComp || !shootPos || !shootTexture || !shootScale || !entityObject)
                continue;
            if (shootComp->type != shootType)
                continue;
            if (isColliding(rectRatio, entityPos, entityScale, entityTexture, shootPos, shootScale, shootTexture)) {
                if (entityLife->life - shootComp->damage <= 0)
                    entityLife->life = 0;
                else
                    entityLife->life -= shootComp->damage;
                if (entityLife->life == 0) {
                    if (std::is_same_v<TYPE,PlayerComponent>)
                        ((PlayerComponent *)entityObject.get())->isAlive = false;
                    else
                        reg.kill_entity(entity);
                }
                reg.kill_entity(shoot);
            }
        }
    }
}

void ShootDamageSystem::_shootDamage(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> mobs = reg.get_components<IComponent>("MobComponent");
        ECS::SparseArray<IComponent> players = reg.get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> shoots = reg.get_components<IComponent>("ShootComponent");
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> textures = reg.get_components<IComponent>("TextureRectComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> lives = reg.get_components<IComponent>("LifeComponent");

        areEntityShot<MobComponent>(reg, ShootComponent::ShootType::PLAYER, 0.8, mobs, shoots, positions, textures, scales, lives);
        areEntityShot<PlayerComponent>(reg, ShootComponent::ShootType::MOB, 1.0, players, shoots, positions, textures, scales, lives);
    } catch (const std::exception &e) {
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem *loadSystemInstance() {
        return new ShootDamageSystem();
    }
}
