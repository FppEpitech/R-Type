/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** JumpSystem
*/

#include "AEvent.hpp"
#include "JumpSystem.hpp"
#include "ScaleComponent.hpp"
#include "HitBoxComponent.hpp"
#include "CanJumpComponent.hpp"
#include "ObjPathComponent.hpp"

JumpSystem::JumpSystem() :
    ASystem("JumpSystem") {}

std::function<void(ECS::Registry& reg, int idxEntity)> JumpSystem::getFunction()
{
    return [this](ECS::Registry& reg, int idxEntity) {
        updatePosition(reg, idxEntity);
    };
}

void JumpSystem::updatePosition(ECS::Registry& reg, int idxEntity)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> speeds = reg.get_components<IComponent>("Speed3DComponent");
        ECS::SparseArray<IComponent> player = reg.get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> hitBoxes = reg.get_components<IComponent>("HitBoxComponent");
        ECS::SparseArray<IComponent> objPaths = reg.get_components<IComponent>("ObjPathComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> canJumps = reg.get_components<IComponent>("CanJumpComponent");

        for (ECS::entity_t entity = 0; entity < draws.size() && entity < positions.size() && entity < speeds.size() && entity < player.size() && entity < canJumps.size(); entity++) {
            std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(draws[entity]);
            std::shared_ptr<Position3DComponent> position = std::dynamic_pointer_cast<Position3DComponent>(positions[entity]);
            std::shared_ptr<Speed3DComponent> speed = std::dynamic_pointer_cast<Speed3DComponent>(speeds[entity]);
            std::shared_ptr<PlayerComponent> playerComponent = std::dynamic_pointer_cast<PlayerComponent>(player[entity]);
            std::shared_ptr<CanJumpComponent> canJump = std::dynamic_pointer_cast<CanJumpComponent>(canJumps[entity]);

            if (!position || !speed || !draw || !playerComponent)
                return;

            if (!canJump->canJump)
                continue;

            position->y += speed->speedY;

            std::vector<std::any> values = {};
            values.push_back(position->x);
            values.push_back(position->y);
            values.push_back(position->z);
            std::shared_ptr<IEvent> event = std::make_shared<AEvent>("UpdateCamera", values);
            reg.addEvent(event);

            if (entity < hitBoxes.size() && entity < objPaths.size() && entity < scales.size()) {
                std::shared_ptr<HitBoxComponent> hitBox = std::dynamic_pointer_cast<HitBoxComponent>(hitBoxes[entity]);
                std::shared_ptr<ObjPathComponent> objPath = std::dynamic_pointer_cast<ObjPathComponent>(objPaths[entity]);
                std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
                if (hitBox && objPath && scale) {
                    std::vector<std::any> hitBoxValues = {};
                    hitBoxValues.push_back((float)position->x);
                    hitBoxValues.push_back((float)position->y);
                    hitBoxValues.push_back((float)position->z);
                    hitBoxValues.push_back((float)scale->scale);
                    hitBoxValues.push_back((std::string)objPath->path);
                    hitBoxValues.push_back((int)entity);
                    std::shared_ptr<IEvent> hitBoxEvent = std::make_shared<AEvent>("UpdateHitBox", hitBoxValues);
                    reg.addEvent(hitBoxEvent);
                }
            }
        }

    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new JumpSystem();
}
}
