/*
** EPITECH PROJECT, 2024
** UpdatePlayerConnectionSystem
** File description:
** UpdatePlayerConnectionSystem
*/

#include "../../../Engine/Shared/DefaultComponent/Draw/DrawComponent.hpp"
#include "updatePlayerConnectionSystem.hpp"

void UpdatePlayerConnectionSystem::_updatePlayerConnection(Network::UDPPacket packet, ECS::Registry& reg)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

        if (packet.getPayload().size() < 1 + componentTypeLength + 4 + sizeof(bool)) {
            std::cerr << "Payload is too small." << std::endl;
            return;
        }

        std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

        int idxPacketEntities = (packet.getPayload()[1 + componentTypeLength] << 24) |
                            (packet.getPayload()[2 + componentTypeLength] << 16) |
                            (packet.getPayload()[3 + componentTypeLength] << 8)  |
                            packet.getPayload()[4 + componentTypeLength];

        bool drawable;
        std::memcpy(&drawable, &packet.getPayload()[5 + componentTypeLength], sizeof(bool));

        ECS::SparseArray<IComponent> DrawComponentArray = reg.get_components<IComponent>(componentType);
        if (DrawComponentArray.size() <= idxPacketEntities)
            return;
        DrawComponent* draw = dynamic_cast<DrawComponent*>(DrawComponentArray[idxPacketEntities].get());
        if (draw) {
            draw->draw = drawable;
        }
    } catch (std::exception e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystemNetworkUpdate* loadUpdateInstance() {
        return new UpdatePlayerConnectionSystem();
    }
}
