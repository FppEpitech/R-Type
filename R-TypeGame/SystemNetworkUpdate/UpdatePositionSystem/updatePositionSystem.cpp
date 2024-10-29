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

        std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

        std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> info = ABINetwork::getUpdateComponentInfoFromPacket(packet);

        if (info.second.empty() || info.second.size() < 3)
            std::cout << "Vector vide" << std::endl;

        int idxEntities = 0;
        float PosX = 0.0;
        float PosY = 0.0;

        if (std::holds_alternative<int>(info.second[0]))
                idxEntities = std::get<int>(info.second[0]);
        if (std::holds_alternative<float>(info.second[1]))
                PosX = std::get<float>(info.second[1]);
        if (std::holds_alternative<float>(info.second[2]))
                PosY = std::get<float>(info.second[2]);


        ECS::SparseArray<IComponent> PlayerComponentArray = reg.get_components<IComponent>("PlayerComponent");
        if (idxEntities >= PlayerComponentArray.size())
            return;
        PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[idxEntities].get());
        if (!player)
            return;

        ECS::SparseArray<IComponent> PositionComponentArray = reg.get_components<IComponent>(componentType);
        if (PositionComponentArray.size() <= idxEntities)
            return;
        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxEntities].get());
        if (position) {
            position->x = PosX;
            position->y = PosY;
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
