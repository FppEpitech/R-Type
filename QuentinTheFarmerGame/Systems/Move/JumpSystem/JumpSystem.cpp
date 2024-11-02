/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** JumpSystem
*/

#include "AEvent.hpp"
#include "JumpSystem.hpp"

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

        for (ECS::entity_t entity = 0; entity < draws.size() && entity < positions.size() && entity < speeds.size() && entity < player.size(); entity++) {
            std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(draws[entity]);
            std::shared_ptr<Position3DComponent> position = std::dynamic_pointer_cast<Position3DComponent>(positions[entity]);
            std::shared_ptr<Speed3DComponent> speed = std::dynamic_pointer_cast<Speed3DComponent>(speeds[entity]);
            std::shared_ptr<PlayerComponent> playerComponent = std::dynamic_pointer_cast<PlayerComponent>(player[entity]);

            if (!position || !speed || !draw || !playerComponent)
                return;

            position->y += speed->speedY;

            /*std::vector<std::any> values = {};
            values.push_back(idxEntity);
            values.push_back(position->x);
            values.push_back(position->y);
            values.push_back(position->z);
            std::shared_ptr<IEvent> eventMoveEntity = std::make_shared<AEvent>("MoveEntity", values);
            reg.addEvent(eventMoveEntity);*/
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
