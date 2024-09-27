/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** StringKeyMap
*/

#pragma once

#include <unordered_map>

#include "KeyMap.hpp"

/**
 * @brief A map of key strings to key codes.
 *
 * This map is used to convert key strings to key codes. It is used by the
 * InputManager class to convert key strings (used in json config files) to key codes (used in the code).
 */
const std::unordered_map<std::string, KEY_MAP> stringKeyMap = {
    {"KEY_NULL", KEY_NULL},                     /**< Key: NULL, used for no key pressed */
    // Alphanumeric keys
    {"KEY_APOSTROPHE", KEY_APOSTROPHE},         /**< Key: ' */
    {"KEY_COMMA", KEY_COMMA},                   /**< Key: , */
    {"KEY_MINUS", KEY_MINUS},                   /**< Key: - */
    {"KEY_PERIOD", KEY_PERIOD},                 /**< Key: . */
    {"KEY_SLASH", KEY_SLASH},                   /**< Key: / */
    {"KEY_ZERO", KEY_ZERO},                     /**< Key: 0 */
    {"KEY_ONE", KEY_ONE},                       /**< Key: 1 */
    {"KEY_TWO", KEY_TWO},                       /**< Key: 2 */
    {"KEY_THREE", KEY_THREE},                   /**< Key: 3 */
    {"KEY_FOUR", KEY_FOUR},                     /**< Key: 4 */
    {"KEY_FIVE", KEY_FIVE},                     /**< Key: 5 */
    {"KEY_SIX", KEY_SIX},                       /**< Key: 6 */
    {"KEY_SEVEN", KEY_SEVEN},                   /**< Key: 7 */
    {"KEY_EIGHT", KEY_EIGHT},                   /**< Key: 8 */
    {"KEY_NINE", KEY_NINE},                     /**< Key: 9 */
    {"KEY_SEMICOLON", KEY_SEMICOLON},           /**< Key: ; */
    {"KEY_EQUAL", KEY_EQUAL},                   /**< Key: = */
    {"KEY_A", KEY_A},                           /**< Key: A */
    {"KEY_B", KEY_B},                           /**< Key: B */
    {"KEY_C", KEY_C},                           /**< Key: C */
    {"KEY_D", KEY_D},                           /**< Key: D */
    {"KEY_E", KEY_E},                           /**< Key: E */
    {"KEY_F", KEY_F},                           /**< Key: F */
    {"KEY_G", KEY_G},                           /**< Key: G */
    {"KEY_H", KEY_H},                           /**< Key: H */
    {"KEY_I", KEY_I},                           /**< Key: I */
    {"KEY_J", KEY_J},                           /**< Key: J */
    {"KEY_K", KEY_K},                           /**< Key: K */
    {"KEY_L", KEY_L},                           /**< Key: L */
    {"KEY_M", KEY_M},                           /**< Key: M */
    {"KEY_N", KEY_N},                           /**< Key: N */
    {"KEY_O", KEY_O},                           /**< Key: O */
    {"KEY_P", KEY_P},                           /**< Key: P */
    {"KEY_Q", KEY_Q},                           /**< Key: Q */
    {"KEY_R", KEY_R},                           /**< Key: R */
    {"KEY_S", KEY_S},                           /**< Key: S */
    {"KEY_T", KEY_T},                           /**< Key: T */
    {"KEY_U", KEY_U},                           /**< Key: U */
    {"KEY_V", KEY_V},                           /**< Key: V */
    {"KEY_W", KEY_W},                           /**< Key: W */
    {"KEY_X", KEY_X},                           /**< Key: X */
    {"KEY_Y", KEY_Y},                           /**< Key: Y */
    {"KEY_Z", KEY_Z},                           /**< Key: Z */
    {"KEY_LEFT_BRACKET", KEY_LEFT_BRACKET},     /**< Key: [ */
    {"KEY_BACKSLASH", KEY_BACKSLASH},           /**< Key: \ */
    {"KEY_RIGHT_BRACKET", KEY_RIGHT_BRACKET},   /**< Key: ] */
    {"KEY_GRAVE", KEY_GRAVE},                   /**< Key: ` */
    // Function keys
    {"KEY_SPACE", KEY_SPACE},                   /**< Key: Space */
    {"KEY_ESCAPE", KEY_ESCAPE},                 /**< Key: Escape */
    {"KEY_ENTER", KEY_ENTER},                   /**< Key: Enter */
    {"KEY_TAB", KEY_TAB},                       /**< Key: Tab */
    {"KEY_BACKSPACE", KEY_BACKSPACE},           /**< Key: Backspace */
    {"KEY_INSERT", KEY_INSERT},                 /**< Key: Insert */
    {"KEY_DELETE", KEY_DELETE},                 /**< Key: Delete */
    {"KEY_RIGHT", KEY_RIGHT},                   /**< Key: Right Arrow */
    {"KEY_LEFT", KEY_LEFT},                     /**< Key: Left Arrow */
    {"KEY_DOWN", KEY_DOWN},                     /**< Key: Down Arrow */
    {"KEY_UP", KEY_UP},                         /**< Key: Up Arrow */
    {"KEY_PAGE_UP", KEY_PAGE_UP},               /**< Key: Page Up */
    {"KEY_PAGE_DOWN", KEY_PAGE_DOWN},           /**< Key: Page Down */
    {"KEY_HOME", KEY_HOME},                     /**< Key: Home */
    {"KEY_END", KEY_END},                       /**< Key: End */
    {"KEY_CAPS_LOCK", KEY_CAPS_LOCK},           /**< Key: Caps Lock */
    {"KEY_SCROLL_LOCK", KEY_SCROLL_LOCK},       /**< Key: Scroll Lock */
    {"KEY_NUM_LOCK", KEY_NUM_LOCK},             /**< Key: Num Lock */
    {"KEY_PRINT_SCREEN", KEY_PRINT_SCREEN},     /**< Key: Print Screen */
    {"KEY_PAUSE", KEY_PAUSE},                   /**< Key: Pause */
    {"KEY_F1", KEY_F1},                         /**< Key: F1 */
    {"KEY_F2", KEY_F2},                         /**< Key: F2 */
    {"KEY_F3", KEY_F3},                         /**< Key: F3 */
    {"KEY_F4", KEY_F4},                         /**< Key: F4 */
    {"KEY_F5", KEY_F5},                         /**< Key: F5 */
    {"KEY_F6", KEY_F6},                         /**< Key: F6 */
    {"KEY_F7", KEY_F7},                         /**< Key: F7 */
    {"KEY_F8", KEY_F8},                         /**< Key: F8 */
    {"KEY_F9", KEY_F9},                         /**< Key: F9 */
    {"KEY_F10", KEY_F10},                       /**< Key: F10 */
    {"KEY_F11", KEY_F11},                       /**< Key: F11 */
    {"KEY_F12", KEY_F12},                       /**< Key: F12 */
    {"KEY_LEFT_SHIFT", KEY_LEFT_SHIFT},         /**< Key: Left Shift */
    {"KEY_LEFT_CONTROL", KEY_LEFT_CONTROL},     /**< Key: Left Control */
    {"KEY_LEFT_ALT", KEY_LEFT_ALT},             /**< Key: Left Alt */
    {"KEY_LEFT_SUPER", KEY_LEFT_SUPER},         /**< Key: Left Super */
    {"KEY_RIGHT_SHIFT", KEY_RIGHT_SHIFT},       /**< Key: Right Shift */
    {"KEY_RIGHT_CONTROL", KEY_RIGHT_CONTROL},   /**< Key: Right Control */
    {"KEY_RIGHT_ALT", KEY_RIGHT_ALT},           /**< Key: Right Alt */
    {"KEY_RIGHT_SUPER", KEY_RIGHT_SUPER},       /**< Key: Right Super */
    {"KEY_MENU", KEY_MENU},                     /**< Key: Menu */
    // Keypad keys
    {"KEY_KP_0", KEY_KP_0},                     /**< Key: Keypad 0 */
    {"KEY_KP_1", KEY_KP_1},                     /**< Key: Keypad 1 */
    {"KEY_KP_2", KEY_KP_2},                     /**< Key: Keypad 2 */
    {"KEY_KP_3", KEY_KP_3},                     /**< Key: Keypad 3 */
    {"KEY_KP_4", KEY_KP_4},                     /**< Key: Keypad 4 */
    {"KEY_KP_5", KEY_KP_5},                     /**< Key: Keypad 5 */
    {"KEY_KP_6", KEY_KP_6},                     /**< Key: Keypad 6 */
    {"KEY_KP_7", KEY_KP_7},                     /**< Key: Keypad 7 */
    {"KEY_KP_8", KEY_KP_8},                     /**< Key: Keypad 8 */
    {"KEY_KP_9", KEY_KP_9},                     /**< Key: Keypad 9 */
    {"KEY_KP_DECIMAL", KEY_KP_DECIMAL},         /**< Key: Keypad Decimal */
    {"KEY_KP_DIVIDE", KEY_KP_DIVIDE},           /**< Key: Keypad Divide */
    {"KEY_KP_MULTIPLY", KEY_KP_MULTIPLY},       /**< Key: Keypad Multiply */
    {"KEY_KP_SUBTRACT", KEY_KP_SUBTRACT},       /**< Key: Keypad Subtract */
    {"KEY_KP_ADD", KEY_KP_ADD},                 /**< Key: Keypad Add */
    {"KEY_KP_ENTER", KEY_KP_ENTER},             /**< Key: Keypad Enter */
    {"KEY_KP_EQUAL", KEY_KP_EQUAL},             /**< Key: Keypad Equal */
};
