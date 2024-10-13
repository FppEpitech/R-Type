/*
** EPITECH PROJECT, 2024
** HitboxPlayerSystem
** File description:
** HitboxPlayerSystem
*/

#include "HitboxPlayerSystem.hpp"
#include "PlayerComponent.hpp"
#include "PlanetComponent.hpp"
#include "Position2DComponent.hpp"
#include "TextureRectComponent.hpp"
#include "ScaleComponent.hpp"
#include "VelocityComponent.hpp"
#include "LifeComponent.hpp"
#include "UpdatePlanet.hpp"

#define REDUCE_SCALE 0.8
#define PLANET_DAMAGE 20

HitboxPlayerSystem::HitboxPlayerSystem() :
    ASystem("HitboxPlayerSystem")
{
}

void HitboxPlayerSystem::_hitboxPlayer(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> players = reg.get_components<IComponent>("PlayerComponent");
        ECS::SparseArray<IComponent> planets = reg.get_components<IComponent>("PlanetComponent");
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> textureRects = reg.get_components<IComponent>("TextureRectComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> velocities = reg.get_components<IComponent>("VelocityComponent");
        ECS::SparseArray<IComponent> lifes = reg.get_components<IComponent>("LifeComponent");

        for (ECS::entity_t entity = 0; planets.size() >= entity + 1 && positions.size() >= entity + 1 &&
        textureRects.size() >= entity + 1 && scales.size() >= entity && velocities.size() >= entity; entity++) {

            std::shared_ptr<PlanetComponent> planet = std::dynamic_pointer_cast<PlanetComponent>(planets[entity]);
            std::shared_ptr<Position2DComponent> positionPlanet = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<TextureRectComponent> textureRectPlanet = std::dynamic_pointer_cast<TextureRectComponent>(textureRects[entity]);
            std::shared_ptr<ScaleComponent> scalePlanet = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            std::shared_ptr<VelocityComponent> velocityPlanet = std::dynamic_pointer_cast<VelocityComponent>(velocities[entity]);
            if (!planet || !positionPlanet || !textureRectPlanet || !velocityPlanet)
                continue;

            for (ECS::entity_t entityPlayer = 0; players.size() >= entityPlayer + 1 && positions.size() >= entityPlayer + 1 &&
            textureRects.size() >= entityPlayer + 1 && scales.size() >= entityPlayer; entityPlayer++) {

                std::shared_ptr<PlayerComponent> player = std::dynamic_pointer_cast<PlayerComponent>(players[entityPlayer]);
                std::shared_ptr<Position2DComponent> positionPlayer = std::dynamic_pointer_cast<Position2DComponent>(positions[entityPlayer]);
                std::shared_ptr<TextureRectComponent> textureRectPlayer = std::dynamic_pointer_cast<TextureRectComponent>(textureRects[entityPlayer]);
                std::shared_ptr<ScaleComponent> scalePlayer = std::dynamic_pointer_cast<ScaleComponent>(scales[entityPlayer]);
                std::shared_ptr<LifeComponent> lifePlayer = std::dynamic_pointer_cast<LifeComponent>(lifes[entityPlayer]);

                if (!player || !positionPlayer || !textureRectPlayer || !lifePlayer)
                    continue;

                float scalePlanetToUse = (scalePlanet) ? scalePlanet->scale : 1;
                float scalePlayerToUse = (scalePlayer) ? scalePlayer->scale : 1;

                scalePlanetToUse *= REDUCE_SCALE;
                scalePlayerToUse *= REDUCE_SCALE;

                if (positionPlayer->x < positionPlanet->x + textureRectPlanet->width * scalePlanetToUse &&
                positionPlayer->x + textureRectPlayer->width * scalePlayerToUse > positionPlanet->x &&
                positionPlayer->y < positionPlanet->y + textureRectPlanet->height * scalePlanetToUse &&
                positionPlayer->y + textureRectPlayer->height * scalePlayerToUse > positionPlanet->y) {
                    updateNewPositions(velocityPlanet, positionPlanet);
                    if (lifePlayer->life <= PLANET_DAMAGE)
                        reg.kill_entity(entityPlayer);
                    else
                        lifePlayer->life -= PLANET_DAMAGE;
                }
            }
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new HitboxPlayerSystem();
}
}
