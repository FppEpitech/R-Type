/*
** EPITECH PROJECT, 2024
** UpdatePlayerConnectionSystem
** File description:
** UpdatePlayerConnectionSystem
*/

#include "Draw/DrawComponent.hpp"
#include "updatePlayerConnectionSystem.hpp"

void UpdatePlayerConnectionSystem::_updatePlayerConnection(ABINetwork::UDPPacket packet, ECS::Registry& reg)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        uint32_t componentTypeLength = static_cast<size_t>(packet.getPayload()[0]);

        std::string componentType(packet.getPayload().begin() + 1, packet.getPayload().begin() + 1 + componentTypeLength);

        std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> info = ABINetwork::getUpdateComponentInfoFromPacket(packet);

        if (info.second.empty())
            return;

        int idxEntities = 0;
        bool drawable = false;

        for (const auto& elem : info.second) {
            if (std::holds_alternative<int>(elem))
                idxEntities = std::get<int>(elem);
            if (std::holds_alternative<bool>(elem))
                drawable = std::get<bool>(elem);
        }

        ECS::SparseArray<IComponent> DrawComponentArray = reg.get_components<IComponent>(componentType);
        if (DrawComponentArray.size() <= idxEntities)
            return;
        std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(DrawComponentArray[idxEntities]);
        if (draw)
            draw->draw = drawable;

    } catch (std::exception e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystemNetworkUpdate* loadUpdateInstance() {
        return new UpdatePlayerConnectionSystem();
    }
}
