#include "MoveSystem.hpp"

extern "C" ISystem* loadSystemInstance() {
    return new MovementSystem();
}
