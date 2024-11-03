/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GravitySystem.cpp
*/

#include <iostream>

#include "AEvent.hpp"
#include "GravitySystem.hpp"
#include "ScaleComponent.hpp"
#include "HitBoxComponent.hpp"
#include "ObjPathComponent.hpp"
#include "GravityComponent.hpp"
#include "Position3DComponent.hpp"

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

void GravitySystem::_handleGravity(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> positions3D = reg.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> gravities = reg.get_components<IComponent>("GravityComponent");
        ECS::SparseArray<IComponent> hitBoxes = reg.get_components<IComponent>("HitBoxComponent");
        ECS::SparseArray<IComponent> objPaths = reg.get_components<IComponent>("ObjPathComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");

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
                    break;
                }
            }
            if (isColliding) {
                position3D->x += gravity->gravityX;
                position3D->y += gravity->gravityY;
                position3D->z += gravity->gravityZ;
                break;
            }

            std::vector<std::any> values = {};
            values.push_back((float)position3D->x);
            values.push_back((float)position3D->y);
            values.push_back((float)position3D->z);
            std::shared_ptr<IEvent> event = std::make_shared<AEvent>("UpdateCamera", values);
            reg.addEvent(event);

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
