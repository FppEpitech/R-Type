/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#include "SpeedComponent.hpp"
#include "PlayerComponent.hpp"
#include "PlayerInitSystem.hpp"
#include "ObjPathComponent.hpp"
#include "Position3DComponent.hpp"
#include "../../Components/Life/LifeComponent.hpp"

PlayerInitSystem::PlayerInitSystem() :
    ASystem("PlayerInitSystem")
{
}

void PlayerInitSystem::_initPlayer(ECS::Registry& reg, int idxPacketEntities)
{
    LifeComponent lifeComponent;
    reg.register_component<IComponent>(lifeComponent.getType());
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<LifeComponent>(100), lifeComponent.getType());

    Position3DComponent pos;
    reg.register_component<IComponent>(pos.getType());
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<Position3DComponent>(0,0,0), pos.getType());

    ObjPathComponent obj;
    reg.register_component<IComponent>(obj.getType());
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<ObjPathComponent>("../R-TypeGame/Assets/player.glb"), obj.getType());

    PlayerComponent player;
    reg.register_component<IComponent>(player.getType());
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<PlayerComponent>(), player.getType());

    SpeedComponent speed;
    reg.register_component<IComponent>(speed.getType());
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<SpeedComponent>(), speed.getType());
}

extern "C" ISystem* loadSystemInstance()
{
    return new PlayerInitSystem();
}
