/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** test.cpp
*/

#include "KeyMap.hpp"
#include "raylib.h"

KEY_MAP getKeyInput() {
    for (KEY_MAP key = KEY_NULL; key <= KEY_KP_EQUAL; key = static_cast<KEY_MAP>(key + 1)) {
        if (IsKeyDown(key))
            return key;
    }
    return KEY_NULL;
}
