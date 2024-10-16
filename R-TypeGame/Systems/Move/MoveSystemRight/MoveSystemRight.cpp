/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemRight
*/

#include "MoveSystemRight.hpp"

#include <fstream>
#include <json/json.h>

#define SETTINGS_PATH "./Config/Settings.json"

MoveSystemRight::MoveSystemRight() :
    ASystem("MovementRightSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemRight::getFunction()
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateRightPosition(reg, idxPacketEntities);
    };
}

void MoveSystemRight::updateRightPosition(ECS::Registry& entityManager, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(entityManager._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> DrawComponentArray = entityManager.get_components<IComponent>("DrawComponent");
        if (DrawComponentArray.size() <= idxPacketEntities)
            return;
        DrawComponent* draw = dynamic_cast<DrawComponent*>(DrawComponentArray[idxPacketEntities].get());
        if (!draw || !draw->draw)
            return;

        ECS::SparseArray<IComponent> PositionComponentArray = entityManager.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> SpeedComponentArray = entityManager.get_components<IComponent>("SpeedComponent");
        ECS::SparseArray<IComponent> texturesRectComponents = entityManager.get_components<IComponent>("TextureRectComponent");
        ECS::SparseArray<IComponent> ScaleComponents = entityManager.get_components<IComponent>("ScaleComponent");

        if (PositionComponentArray.size() <= idxPacketEntities || SpeedComponentArray.size() <= idxPacketEntities ||
        texturesRectComponents.size() <= idxPacketEntities || ScaleComponents.size() <= idxPacketEntities)
            return;

        Position2DComponent* position = dynamic_cast<Position2DComponent*>(PositionComponentArray[idxPacketEntities].get());
        SpeedComponent* speed = dynamic_cast<SpeedComponent*>(SpeedComponentArray[idxPacketEntities].get());
        TextureRectComponent* textureRect = dynamic_cast<TextureRectComponent*>(texturesRectComponents[idxPacketEntities].get());
        ScaleComponent* scale = dynamic_cast<ScaleComponent*>(ScaleComponents[idxPacketEntities].get());

        if (!position || !speed || !textureRect || !scale)
            return;

        Json::Value root;
        Json::Reader reader;
        std::ifstream file(SETTINGS_PATH);
        std::vector<std::pair<int, int>> allResolutions;
        if (!reader.parse(file, root, false))
            return;
        int index = root["window"]["resolutionIndex"].asInt();
        if (root["window"]["resolutions"].size() <= index)
            return;

        if (position->x + speed->speedX + textureRect->width * scale->scale > root["window"]["resolutions"][index]["w"].asInt())
            position->x = root["window"]["resolutions"][index]["w"].asInt() - textureRect->width * scale->scale;
        else
            position->x += speed->speedX;

        entityManager.messageType = 0x01;
        entityManager.payload.clear();

        std::string componentType = "Position2DComponent";
        entityManager.payload.push_back(static_cast<uint8_t>(componentType.size()));
        entityManager.payload.insert(entityManager.payload.end(), componentType.begin(), componentType.end());


        entityManager.payload.push_back(static_cast<uint8_t>(idxPacketEntities >> 24) & 0xFF);
        entityManager.payload.push_back(static_cast<uint8_t>((idxPacketEntities >> 16) & 0xFF));
        entityManager.payload.push_back(static_cast<uint8_t>((idxPacketEntities >> 8) & 0xFF));
        entityManager.payload.push_back(static_cast<uint8_t>((idxPacketEntities) & 0xFF));

        float x = position->x;
        uint8_t* xBytes = reinterpret_cast<uint8_t*>(&x);
        entityManager.payload.insert(entityManager.payload.end(), xBytes, xBytes + sizeof(float));

        float y = position->y;
        uint8_t* yBytes = reinterpret_cast<uint8_t*>(&y);
        entityManager.payload.insert(entityManager.payload.end(), yBytes, yBytes + sizeof(float));

    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new MoveSystemRight();
}
}
