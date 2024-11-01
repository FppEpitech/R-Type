/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemDown
*/

#include "AEvent.hpp"
#include "MoveSystemDown.hpp"

#include <fstream>
#include <json/json.h>

#define SETTINGS_PATH "./Config/Settings.json"

MoveSystemDown::MoveSystemDown() :
    ASystem("MovementUpSystem")
{
}

std::function<void(ECS::Registry& reg, int idxPacketEntities)> MoveSystemDown::getFunction()
{
    return [this](ECS::Registry& reg, int idxPacketEntities) {
        updateDownPosition(reg, idxPacketEntities);
    };
}

void MoveSystemDown::updateDownPosition(ECS::Registry& entityManager, int idxPacketEntities)
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

        if (position->y + speed->speedY + textureRect->height * scale->scale > root["window"]["resolutions"][index]["h"].asInt())
            position->y = root["window"]["resolutions"][index]["h"].asInt() - textureRect->height * scale->scale;
        else
            position->y += speed->speedY;
        speed->frameRate = std::chrono::high_resolution_clock::now();

        std::vector<std::any> valuesMoveEntity = {};
        valuesMoveEntity.push_back(idxPacketEntities);
        valuesMoveEntity.push_back(position->x);
        valuesMoveEntity.push_back(position->y);
        std::shared_ptr<IEvent> eventMoveEntity = std::make_shared<AEvent>("MoveEntity", valuesMoveEntity);
        entityManager.addEvent(eventMoveEntity);
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new MoveSystemDown();
}
}
