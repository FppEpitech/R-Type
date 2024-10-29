/*
** EPITECH PROJECT, 2024
** UpdatePositionComponent
** File description:
** UpdatePositionComponent
*/

#include "PlayerComponent.hpp"
#include "VelocityComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "updatePositionSystem.hpp"

void UpdatePositionComponent::_updatePosition(ABINetwork::UDPPacket packet, ECS::Registry& reg)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

        if (packet.getPayload().size() < 1 + componentTypeLength + 4 + 2 * sizeof(float)) {
            std::cerr << "Payload is too small." << std::endl;
            return;
        }

        std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

        int idxPacketEntities = (packet.getPayload()[1 + componentTypeLength] << 24) |
                            (packet.getPayload()[2 + componentTypeLength] << 16) |
                            (packet.getPayload()[3 + componentTypeLength] << 8)  |
                            packet.getPayload()[4 + componentTypeLength];

        ECS::SparseArray<IComponent> PlayerComponentArray = reg.get_components<IComponent>("PlayerComponent");
        if (idxPacketEntities >= PlayerComponentArray.size())
            return;
        PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[idxPacketEntities].get());
        if (!player)
            return;

        float x;
        std::memcpy(&x, &packet.getPayload()[5 + componentTypeLength], sizeof(float));

        float y;
        std::memcpy(&y, &packet.getPayload()[9 + componentTypeLength], sizeof(float));

        ECS::SparseArray<IComponent> PositionComponentArray = reg.get_components<IComponent>(componentType);
        if (PositionComponentArray.size() <= idxPacketEntities)
            return;
        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
        if (position) {
            position->x = x;
            position->y = y;
        }
    } catch (std::exception e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystemNetworkUpdate* loadUpdateInstance() {
        return new UpdatePositionComponent();
    }
}
