/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GravitySystem.cpp
*/

#include <iostream>

#include "AEvent.hpp"
#include "GravitySystem.hpp"
#include "LifeComponent.hpp"
#include "DrawComponent.hpp"
#include "ScaleComponent.hpp"
#include "HitBoxComponent.hpp"
#include "PlayerComponent.hpp"
#include "CanJumpComponent.hpp"
#include "ObjPathComponent.hpp"
#include "GravityComponent.hpp"
#include "Position3DComponent.hpp"
#include "ColliderDamageComponent.hpp"

GravitySystem::GravitySystem() : ASystem("GravitySystem") {}

static void updateHitBox(ECS::Registry &reg, ECS::entity_t entity, ECS::SparseArray<IComponent> &hitBoxes, ECS::SparseArray<IComponent> &objPaths, ECS::SparseArray<IComponent> &scales, std::shared_ptr<Position3DComponent> position3D)
{
    if (entity < hitBoxes.size() && entity < objPaths.size() && entity < scales.size()) {
        std::shared_ptr<HitBoxComponent> hitBox = std::dynamic_pointer_cast<HitBoxComponent>(hitBoxes[entity]);
        std::shared_ptr<ObjPathComponent> objPath = std::dynamic_pointer_cast<ObjPathComponent>(objPaths[entity]);
        std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
        if (hitBox && objPath && scale) {
            std::vector<std::any> hitBoxValues = {};
            hitBoxValues.push_back((float)position3D->x);
            hitBoxValues.push_back((float)position3D->y);
            hitBoxValues.push_back((float)position3D->z);
            hitBoxValues.push_back((float)scale->scale);
            hitBoxValues.push_back((std::string)objPath->path);
            hitBoxValues.push_back((int)entity);
            std::shared_ptr<IEvent> hitBoxEvent = std::make_shared<AEvent>("UpdateHitBox", hitBoxValues);
            reg.addEvent(hitBoxEvent);
        }
    }
}

static void applyCollisionDamage(ECS::Registry &reg, ECS::entity_t entity, ECS::entity_t entity2, ECS::SparseArray<IComponent> &colliderDamages, ECS::SparseArray<IComponent> &lives, ECS::SparseArray<IComponent> &draws)
{
    for (int i = 0; i < 2; ++i) {
        ECS::entity_t e1 = (i == 0) ? entity : entity2;
        ECS::entity_t e2 = (i == 0) ? entity2 : entity;
        if (e1 < colliderDamages.size() && e2 < lives.size()) {
            std::shared_ptr<ColliderDamageComponent> colliderDamage = std::dynamic_pointer_cast<ColliderDamageComponent>(colliderDamages[e1]);
            std::shared_ptr<LifeComponent> life = std::dynamic_pointer_cast<LifeComponent>(lives[e2]);
            if (!colliderDamage || !life)
                continue;
            if (life->life <= colliderDamage->damage) {
                life->life = 0;
                if (e2 < draws.size()) {
                    std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(draws[e2]);
                    if (draw)
                        draw->draw = false;
                }
            } else
                life->life -= colliderDamage->damage;
        }
    }
}

void GravitySystem::_handleGravity(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");
        ECS::SparseArray<IComponent> positions3D = reg.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> gravities = reg.get_components<IComponent>("GravityComponent");
        ECS::SparseArray<IComponent> hitBoxes = reg.get_components<IComponent>("HitBoxComponent");
        ECS::SparseArray<IComponent> objPaths = reg.get_components<IComponent>("ObjPathComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> players = reg.get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> colliderDamages = reg.get_components<IComponent>("ColliderDamageComponent");
        ECS::SparseArray<IComponent> lives = reg.get_components<IComponent>("LifeComponent");
        ECS::SparseArray<IComponent> canJumps = reg.get_components<IComponent>("CanJumpComponent");

        for (ECS::entity_t entity = 0; entity < positions3D.size() && entity < gravities.size(); entity++) {
            std::shared_ptr<Position3DComponent> position3D = std::dynamic_pointer_cast<Position3DComponent>(positions3D[entity]);
            std::shared_ptr<GravityComponent> gravity = std::dynamic_pointer_cast<GravityComponent>(gravities[entity]);

            if (!position3D || !gravity)
                continue;
            bool isColliding = false;

            position3D->x -= gravity->gravityX;
            position3D->y -= gravity->gravityY;
            position3D->z -= gravity->gravityZ;

            for (ECS::entity_t entity2 = 0; entity2 < hitBoxes.size() && entity < hitBoxes.size(); entity2++) {
                if (entity == entity2)
                    continue;
                std::shared_ptr<HitBoxComponent> hitBox = std::dynamic_pointer_cast<HitBoxComponent>(hitBoxes[entity]);
                std::shared_ptr<HitBoxComponent> hitBox2 = std::dynamic_pointer_cast<HitBoxComponent>(hitBoxes[entity2]);
                if (!hitBox || !hitBox2)
                    continue;
                if (hitBox->isColliding(hitBox2->hitBoxes)) {
                    isColliding = true;
                    applyCollisionDamage(reg, entity, entity2, colliderDamages, lives, draws);
                    break;
                }
            }
            if (isColliding) {
                position3D->x += gravity->gravityX;
                position3D->y += gravity->gravityY;
                position3D->z += gravity->gravityZ;
                if (entity < canJumps.size()) {
                    std::shared_ptr<CanJumpComponent> canJump = std::dynamic_pointer_cast<CanJumpComponent>(canJumps[entity]);
                    if (!canJump)
                        continue;
                    canJump->canJump = true;
                }
            }
            if (entity < players.size()) {
                std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(players[entity]);
                if (!player)
                    continue;
                std::vector<std::any> values = {};
                values.push_back((float)position3D->x);
                values.push_back((float)position3D->y);
                values.push_back((float)position3D->z);
                std::shared_ptr<IEvent> event = std::make_shared<AEvent>("UpdateCamera", values);
                reg.addEvent(event);
            }
            if (isColliding)
                continue;
            if (entity < canJumps.size()) {
                std::shared_ptr<CanJumpComponent> canJump = std::dynamic_pointer_cast<CanJumpComponent>(canJumps[entity]);
                if (!canJump)
                    continue;
                canJump->canJump = false;
            }
            updateHitBox(reg, entity, hitBoxes, objPaths, scales, position3D);
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new GravitySystem();
}
}
