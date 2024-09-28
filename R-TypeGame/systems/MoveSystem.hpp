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

        std::function<void(ECS::Registry& reg)> getFunction()
        {
            return [this](ECS::Registry& reg) {
                updatePosition(reg);
            };
        }

        void updatePosition(ECS::Registry& entityManager)
        {
            std::cout << "Hello" << std::endl;
        };

    private:

        std::string _type = "Movement";
};
