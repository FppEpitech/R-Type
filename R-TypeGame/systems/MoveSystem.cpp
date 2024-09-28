/**
 * This file is a System test file to check if SceneManagers work correctly
 *
 */

#include "MoveSystem.hpp"

extern "C" ISystem* loadSystemInstance() {
    return new MovementSystem();
}
