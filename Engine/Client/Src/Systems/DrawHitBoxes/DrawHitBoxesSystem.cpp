/*
** EPITECH PROJECT, 2024
** DrawHitBoxesSystem
** File description:
** DrawHitBoxesSystem
*/

#include "AEvent.hpp"
#include "DrawHitBoxesSystem.hpp"
#include "Draw/DrawComponent.hpp"
#include "Scale/ScaleComponent.hpp"
#include "HitBox/HitBoxComponent.hpp"
#include "Position3D/Position3DComponent.hpp"

DrawHitBoxesSystem::DrawHitBoxesSystem() :
    ASystem("DrawHitBoxesSystem")
{
}

void DrawHitBoxesSystem::_drawHitBoxes(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> hitBoxes = reg.get_components<IComponent>("HitBoxComponent");
        ECS::SparseArray<IComponent> positions3D = reg.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");

        for (ECS::entity_t entity = 0; hitBoxes.size() >= entity + 1 && positions3D.size() >= entity + 1 && scales.size() >= entity + 1 && draws.size() >= entity + 1; entity++) {
            std::shared_ptr<HitBoxComponent> hitBox = std::dynamic_pointer_cast<HitBoxComponent>(hitBoxes[entity]);
            std::shared_ptr<Position3DComponent> position3D = std::dynamic_pointer_cast<Position3DComponent>(positions3D[entity]);
            std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(draws[entity]);

            if (!hitBox || !position3D || !scale || !draw || !draw->draw)
                continue;

            std::vector<std::any> values = {};
            values.push_back((std::vector<HitBox>)hitBox->hitBoxes);
            values.push_back((unsigned int)255);
            values.push_back((unsigned int)0);
            values.push_back((unsigned int)0);
            values.push_back((unsigned int)255);
            std::shared_ptr<IEvent> event = std::make_shared<AEvent>("HitBoxesDraw", values);
            reg.addEvent(event);
        }
    } catch (std::exception e) {
    }
}
