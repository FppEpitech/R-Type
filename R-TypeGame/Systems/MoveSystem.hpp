/**
 * This file is a System test file to check if SceneManagers work correctly
 *
 */

#include "ISystem.hpp"
#include <iostream>

class MovementSystem : public ISystem {

    public:

        const std::string &getType()
        {
            return _type;
        }

        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                updatePosition(reg, idxPacketEntities);
            };
        }

        void updatePosition(ECS::Registry& entityManager, int idxPacketEntities)
        {
            std::cout << "Hello" << std::endl;
        };

    private:

        std::string _type = "Movement";
};
