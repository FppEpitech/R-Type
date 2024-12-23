/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationSystem
** File description:
** SpriteSheetAnimationSystem
*/

#include "SpriteSheetAnimationSystem.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "SpriteSheetAnimation/SpriteSheetAnimationComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SparseArray.hpp"

SpriteSheetAnimationSystem::SpriteSheetAnimationSystem() :
    ASystem("SpriteSheetAnimationSystem")
{
}

void SpriteSheetAnimationSystem::_spriteSheetAnimation(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> textureRectComponents = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> spriteSheetAnimationComponents = reg.get_components<IComponent>("SpriteSheetAnimationComponent");

    for (ECS::entity_t entity = 0; textureRectComponents.size() >= entity + 1
    && spriteSheetAnimationComponents.size() >= entity + 1; entity++) {

        std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(textureRectComponents[entity]);
        std::shared_ptr<SpriteSheetAnimationComponent> spriteSheetAnimation = std::dynamic_pointer_cast<SpriteSheetAnimationComponent>(spriteSheetAnimationComponents[entity]);

        if (!textureRect || !spriteSheetAnimation)
            continue;

        auto time = std::chrono::high_resolution_clock::now();
        auto timeElapsed = std::chrono::duration<float>(time - spriteSheetAnimation->timeElapsed).count() * 10;
        if (spriteSheetAnimation->timeFrame < timeElapsed) {
            spriteSheetAnimation->timeElapsed = std::chrono::high_resolution_clock::now();
            spriteSheetAnimation->currentFrame++;
            if (spriteSheetAnimation->currentFrame > spriteSheetAnimation->nbFrame) {
                spriteSheetAnimation->currentFrame = 2;
                if (!spriteSheetAnimation->reverseMod) {
                    textureRect->left = spriteSheetAnimation->startX;
                    textureRect->top = spriteSheetAnimation->startY;
                    continue;
                } else {
                    spriteSheetAnimation->vx = spriteSheetAnimation->vx * (-1);
                    spriteSheetAnimation->vy = spriteSheetAnimation->vy * (-1);
                }
            }
            textureRect->left += spriteSheetAnimation->vx;
            textureRect->top += spriteSheetAnimation->vy;
        }
    }
}
