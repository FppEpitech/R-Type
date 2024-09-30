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

        std::function<void(ECS::Registry& reg, Network::UDPPacket& packet)> getFunction()
        {
            return [this](ECS::Registry& reg, Network::UDPPacket& packet) {
                updatePosition(reg, packet);
            };
        }

        void updatePosition(ECS::Registry& entityManager, Network::UDPPacket& packet)
        {
            std::cout << "Hello" << std::endl;
        };

    private:

        std::string _type = "Movement";
};
