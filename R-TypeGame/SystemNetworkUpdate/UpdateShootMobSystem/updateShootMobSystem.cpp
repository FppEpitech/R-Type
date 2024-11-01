/*
** EPITECH PROJECT, 2024
** UpdateShootComponent
** File description:
** UpdateShootComponent
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "PlayerComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "MobComponent.hpp"
#include "ScaleComponent.hpp"
#include "TextureRectComponent.hpp"
#include "ShootTypeComponent.hpp"
#include "MobSpeOneShootInitSystem.hpp"
#include "MobSpeTwoShootInitSystem.hpp"
#include "../../../Engine/Ecs/Src/Events/AEvent.hpp"

#include "updateShootMobSystem.hpp"

void UpdateShootMobSystem::_updateShootMobSystem(ABINetwork::UDPPacket packet, ECS::Registry& reg)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

        std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

        std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> info = ABINetwork::getUpdateComponentInfoFromPacket(packet);

        if (info.second.empty() || info.second.size() < 1)
            return;

        int idxEntity = 0;
        int idxShoot = 0;
        if (std::holds_alternative<int>(info.second[0]))
                idxEntity = std::get<int>(info.second[0]);
        if (std::holds_alternative<int>(info.second[1]))
                idxShoot = std::get<int>(info.second[1]);

        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> mobs = reg.get_components<IComponent>("MobComponent");
        ECS::SparseArray<IComponent> shootTypes = reg.get_components<IComponent>("ShootTypeComponent");
        ECS::SparseArray<IComponent> TextRec = reg.get_components<IComponent>("TextureRectComponent");

        std::shared_ptr<Position2DComponent> positionMob = std::dynamic_pointer_cast<Position2DComponent>(positions[idxEntity]);
        ShootTypeComponent::ShootType shootType = std::dynamic_pointer_cast<ShootTypeComponent>(shootTypes[idxEntity])->type;
        std::string mobSpritePath = std::dynamic_pointer_cast<TextureRectComponent>(TextRec[idxEntity])->path;
        for (int i = 0; i < shootType + 1; i++) {
            ECS::entity_t shoot = reg.spawnEntityIdx(idxShoot);
            if (mobSpritePath == "./Assets/mob-spe-1.gif") {
                MobSpeOneShootInitSystem().getFunction()(reg, shoot);
            } else if (mobSpritePath == "./Assets/mob-1.gif") {
                ShootInitSystem().getFunction()(reg, shoot);
            } else if (mobSpritePath == "./Assets/mob-spe-2.gif") {
                MobSpeTwoShootInitSystem().getFunction()(reg, shoot);
            } else {
                continue;
            }
            positions = reg.get_components<IComponent>("Position2DComponent");
            std::shared_ptr <Position2DComponent> positionShoot = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
            ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
            std::shared_ptr <ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[idxEntity]);
            ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
            std::shared_ptr <TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[idxEntity]);
            if (mobSpritePath == "./Assets/mob-spe-1.gif") {
                positionShoot->x = positionMob->x + ((textureRect->width / 2) * scale->scale);
                positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale) + (((i - 3) * 45) * scale->scale);
            } else if (mobSpritePath == "./Assets/mob-1.gif") {
                positionShoot->x = positionMob->x + ((textureRect->width / 2) * scale->scale);
                positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale);
            } else if (mobSpritePath == "./Assets/mob-spe-2.gif") {
                positionShoot->x = positionMob->x + ((textureRect->left) * scale->scale);
                positionShoot->y = positionMob->y + ((textureRect->height / 2) * scale->scale);
            } else {
                continue;
            }
        }

    } catch (std::exception e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystemNetworkUpdate* loadUpdateInstance() {
        return new UpdateShootMobSystem();
    }
}
