/*
** EPITECH PROJECT, 2024
** UpdateShootComponent
** File description:
** UpdateShootComponent
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "PlayerComponent.hpp"
#include "updateShootSystem.hpp"
#include "Position2D/Position2DComponent.hpp"

void UpdateShootSystem::_updateShootSystem(Network::UDPPacket packet, ECS::Registry& reg)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

        if (packet.getPayload().size() < 1 + componentTypeLength + 1 * sizeof(int)) {
            std::cerr << "Payload is too small." << std::endl;
            return;
        }

        std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

        int idxPacketEntities = (packet.getPayload()[1 + componentTypeLength] << 24) |
                            (packet.getPayload()[2 + componentTypeLength] << 16) |
                            (packet.getPayload()[3 + componentTypeLength] << 8)  |
                            packet.getPayload()[4 + componentTypeLength];

        ECS::entity_t shoot = reg.spawn_entity();
        ShootInitSystem().getFunction()(reg, shoot);

        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");

        if (positions.size() > shoot && positions.size() > idxPacketEntities) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
            std::shared_ptr<Position2DComponent> positionPlayer = std::dynamic_pointer_cast<Position2DComponent>(positions[idxPacketEntities]);

            if (position && positionPlayer) {
                position->x = positionPlayer->x + POS_PLAYER_X;
                position->y = positionPlayer->y + POS_PLAYER_Y;
            }
        }

    } catch (std::exception e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystemNetworkUpdate* loadUpdateInstance() {
        return new UpdateShootSystem();
    }
}
