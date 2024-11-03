/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBoxComponent.hpp
*/

#pragma once

#include "../IComponent.hpp"
#include "../../../Client/Src/GetGraphicalLibrary/IGraphic.hpp"

/**
 * @brief HitBox component.
 */
class HitBoxComponent : public AComponent {
    public:

        std::vector<HitBox> hitBoxes; //< HitBoxes of the entity.

        /**
         * @brief Construct a new HitBox Component object.
         *
         * @param hitBoxes HitBoxes of the entity.
         */
        HitBoxComponent(std::vector<HitBox> hitBoxes = {});

        /**
         * @brief Check if the entity is colliding with another entity.
         *
         * @param otherHitBoxes HitBoxes of the other entity.
         * @return true if the entity is colliding with the other entity.
         * @return false if the entity is not colliding with the other entity.
         */
        bool isColliding(std::vector<HitBox> otherHitBoxes);
};
