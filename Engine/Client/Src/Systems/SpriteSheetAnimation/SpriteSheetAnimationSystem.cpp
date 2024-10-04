/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationSystem
** File description:
** SpriteSheetAnimationSystem
*/

#include "SpriteSheetAnimationSystem.hpp"
#include "TextureRectComponent.hpp"
#include "SpriteSheetAnimationComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SparseArray.hpp"

#include <exception>

SpriteSheetAnimationSystem::SpriteSheetAnimationSystem() :
    ASystem("SpriteSheetAnimationSystem")
{
}

void SpriteSheetAnimationSystem::_spriteSheetAnimation(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();

    ECS::SparseArray<IComponent> textureRectComponents = reg.get_components<IComponent>("TextureRectComponent");
    ECS::SparseArray<IComponent> spriteSheetAnimationComponents = reg.get_components<IComponent>("SpriteSheetAnimationComponent");

    for (ECS::entity_t entity = 0; textureRectComponents.size() >= entity + 1
    && spriteSheetAnimationComponents.size() >= entity + 1; entity++) {

        std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(textureRectComponents[entity]);
        std::shared_ptr<SpriteSheetAnimationComponent> spriteSheetAnimation = std::dynamic_pointer_cast<SpriteSheetAnimationComponent>(spriteSheetAnimationComponents[entity]);

        if (!textureRect || !spriteSheetAnimation)
            continue;

        clock_t time = clock();
        std::cout << spriteSheetAnimation->currentFrame << std::endl;
        float timeElapsed = float(time - spriteSheetAnimation->timeElapsed) / CLOCKS_PER_SEC * 10;
        if (spriteSheetAnimation->timeFrame < timeElapsed) {
            spriteSheetAnimation->timeElapsed = clock();
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
