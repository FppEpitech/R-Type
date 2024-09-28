/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** StringKeyMap
*/

#pragma once

#include <unordered_map>
#include <string>

#include "KeyMap.hpp"

/**
 * @brief A map of key strings to key codes.
 *
 * This map is used to convert key strings to key codes. It is used by the
 * InputManager class to convert key strings (used in json config files) to key codes (used in the code).
 */
const std::unordered_map<std::string, KEY_MAP> stringKeyMap = {
    {"KEY_NULL", KEY_MAP::KEY_NULL},                     /**< Key: NULL, used for no key pressed */
    // Alphanumeric keys
    {"KEY_APOSTROPHE", KEY_MAP::KEY_APOSTROPHE},         /**< Key: ' */
    {"KEY_COMMA", KEY_MAP::KEY_COMMA},                   /**< Key: , */
    {"KEY_MINUS", KEY_MAP::KEY_MINUS},                   /**< Key: - */
    {"KEY_PERIOD", KEY_MAP::KEY_PERIOD},                 /**< Key: . */
    {"KEY_SLASH", KEY_MAP::KEY_SLASH},                   /**< Key: / */
    {"KEY_ZERO", KEY_MAP::KEY_ZERO},                     /**< Key: 0 */
    {"KEY_ONE", KEY_MAP::KEY_ONE},                       /**< Key: 1 */
    {"KEY_TWO", KEY_MAP::KEY_TWO},                       /**< Key: 2 */
    {"KEY_THREE", KEY_MAP::KEY_THREE},                   /**< Key: 3 */
    {"KEY_FOUR", KEY_MAP::KEY_FOUR},                     /**< Key: 4 */
    {"KEY_FIVE", KEY_MAP::KEY_FIVE},                     /**< Key: 5 */
    {"KEY_SIX", KEY_MAP::KEY_SIX},                       /**< Key: 6 */
    {"KEY_SEVEN", KEY_MAP::KEY_SEVEN},                   /**< Key: 7 */
    {"KEY_EIGHT", KEY_MAP::KEY_EIGHT},                   /**< Key: 8 */
    {"KEY_NINE", KEY_MAP::KEY_NINE},                     /**< Key: 9 */
    {"KEY_SEMICOLON", KEY_MAP::KEY_SEMICOLON},           /**< Key: ; */
    {"KEY_EQUAL", KEY_MAP::KEY_EQUAL},                   /**< Key: = */
    {"KEY_A", KEY_MAP::KEY_A},                           /**< Key: A */
    {"KEY_B", KEY_MAP::KEY_B},                           /**< Key: B */
    {"KEY_C", KEY_MAP::KEY_C},                           /**< Key: C */
    {"KEY_D", KEY_MAP::KEY_D},                           /**< Key: D */
    {"KEY_E", KEY_MAP::KEY_E},                           /**< Key: E */
    {"KEY_F", KEY_MAP::KEY_F},                           /**< Key: F */
    {"KEY_G", KEY_MAP::KEY_G},                           /**< Key: G */
    {"KEY_H", KEY_MAP::KEY_H},                           /**< Key: H */
    {"KEY_I", KEY_MAP::KEY_I},                           /**< Key: I */
    {"KEY_J", KEY_MAP::KEY_J},                           /**< Key: J */
    {"KEY_K", KEY_MAP::KEY_K},                           /**< Key: K */
    {"KEY_L", KEY_MAP::KEY_L},                           /**< Key: L */
    {"KEY_M", KEY_MAP::KEY_M},                           /**< Key: M */
    {"KEY_N", KEY_MAP::KEY_N},                           /**< Key: N */
    {"KEY_O", KEY_MAP::KEY_O},                           /**< Key: O */
    {"KEY_P", KEY_MAP::KEY_P},                           /**< Key: P */
    {"KEY_Q", KEY_MAP::KEY_Q},                           /**< Key: Q */
    {"KEY_R", KEY_MAP::KEY_R},                           /**< Key: R */
    {"KEY_S", KEY_MAP::KEY_S},                           /**< Key: S */
    {"KEY_T", KEY_MAP::KEY_T},                           /**< Key: T */
    {"KEY_U", KEY_MAP::KEY_U},                           /**< Key: U */
    {"KEY_V", KEY_MAP::KEY_V},                           /**< Key: V */
    {"KEY_W", KEY_MAP::KEY_W},                           /**< Key: W */
    {"KEY_X", KEY_MAP::KEY_X},                           /**< Key: X */
    {"KEY_Y", KEY_MAP::KEY_Y},                           /**< Key: Y */
    {"KEY_Z", KEY_MAP::KEY_Z},                           /**< Key: Z */
    {"KEY_LEFT_BRACKET", KEY_MAP::KEY_LEFT_BRACKET},     /**< Key: [ */
    {"KEY_BACKSLASH", KEY_MAP::KEY_BACKSLASH},           /**< Key: \ */
    {"KEY_RIGHT_BRACKET", KEY_MAP::KEY_RIGHT_BRACKET},   /**< Key: ] */
    {"KEY_GRAVE", KEY_MAP::KEY_GRAVE},                   /**< Key: ` */
    // Function keys
    {"KEY_SPACE", KEY_MAP::KEY_SPACE},                   /**< Key: Space */
    {"KEY_ESCAPE", KEY_MAP::KEY_ESCAPE},                 /**< Key: Escape */
    {"KEY_ENTER", KEY_MAP::KEY_ENTER},                   /**< Key: Enter */
    {"KEY_TAB", KEY_MAP::KEY_TAB},                       /**< Key: Tab */
    {"KEY_BACKSPACE", KEY_MAP::KEY_BACKSPACE},           /**< Key: Backspace */
    {"KEY_INSERT", KEY_MAP::KEY_INSERT},                 /**< Key: Insert */
    {"KEY_DELETE", KEY_MAP::KEY_DELETE},                 /**< Key: Delete */
    {"KEY_RIGHT", KEY_MAP::KEY_RIGHT},                   /**< Key: Right Arrow */
    {"KEY_LEFT", KEY_MAP::KEY_LEFT},                     /**< Key: Left Arrow */
    {"KEY_DOWN", KEY_MAP::KEY_DOWN},                     /**< Key: Down Arrow */
    {"KEY_UP", KEY_MAP::KEY_UP},                         /**< Key: Up Arrow */
    {"KEY_PAGE_UP", KEY_MAP::KEY_PAGE_UP},               /**< Key: Page Up */
    {"KEY_PAGE_DOWN", KEY_MAP::KEY_PAGE_DOWN},           /**< Key: Page Down */
    {"KEY_HOME", KEY_MAP::KEY_HOME},                     /**< Key: Home */
    {"KEY_END", KEY_MAP::KEY_END},                       /**< Key: End */
    {"KEY_CAPS_LOCK", KEY_MAP::KEY_CAPS_LOCK},           /**< Key: Caps Lock */
    {"KEY_SCROLL_LOCK", KEY_MAP::KEY_SCROLL_LOCK},       /**< Key: Scroll Lock */
    {"KEY_NUM_LOCK", KEY_MAP::KEY_NUM_LOCK},             /**< Key: Num Lock */
    {"KEY_PRINT_SCREEN", KEY_MAP::KEY_PRINT_SCREEN},     /**< Key: Print Screen */
    {"KEY_PAUSE", KEY_MAP::KEY_PAUSE},                   /**< Key: Pause */
    {"KEY_F1", KEY_MAP::KEY_F1},                         /**< Key: F1 */
    {"KEY_F2", KEY_MAP::KEY_F2},                         /**< Key: F2 */
    {"KEY_F3", KEY_MAP::KEY_F3},                         /**< Key: F3 */
    {"KEY_F4", KEY_MAP::KEY_F4},                         /**< Key: F4 */
    {"KEY_F5", KEY_MAP::KEY_F5},                         /**< Key: F5 */
    {"KEY_F6", KEY_MAP::KEY_F6},                         /**< Key: F6 */
    {"KEY_F7", KEY_MAP::KEY_F7},                         /**< Key: F7 */
    {"KEY_F8", KEY_MAP::KEY_F8},                         /**< Key: F8 */
    {"KEY_F9", KEY_MAP::KEY_F9},                         /**< Key: F9 */
    {"KEY_F10", KEY_MAP::KEY_F10},                       /**< Key: F10 */
    {"KEY_F11", KEY_MAP::KEY_F11},                       /**< Key: F11 */
    {"KEY_F12", KEY_MAP::KEY_F12},                       /**< Key: F12 */
    {"KEY_LEFT_SHIFT", KEY_MAP::KEY_LEFT_SHIFT},         /**< Key: Left Shift */
    {"KEY_LEFT_CONTROL", KEY_MAP::KEY_LEFT_CONTROL},     /**< Key: Left Control */
    {"KEY_LEFT_ALT", KEY_MAP::KEY_LEFT_ALT},             /**< Key: Left Alt */
    {"KEY_LEFT_SUPER", KEY_MAP::KEY_LEFT_SUPER},         /**< Key: Left Super */
    {"KEY_RIGHT_SHIFT", KEY_MAP::KEY_RIGHT_SHIFT},       /**< Key: Right Shift */
    {"KEY_RIGHT_CONTROL", KEY_MAP::KEY_RIGHT_CONTROL},   /**< Key: Right Control */
    {"KEY_RIGHT_ALT", KEY_MAP::KEY_RIGHT_ALT},           /**< Key: Right Alt */
    {"KEY_RIGHT_SUPER", KEY_MAP::KEY_RIGHT_SUPER},       /**< Key: Right Super */
    {"KEY_KB_MENU", KEY_MAP::KEY_KB_MENU},               /**< Key: Menu */
    // Keypad keys
    {"KEY_KP_0", KEY_MAP::KEY_KP_0},                     /**< Key: Keypad 0 */
    {"KEY_KP_1", KEY_MAP::KEY_KP_1},                     /**< Key: Keypad 1 */
    {"KEY_KP_2", KEY_MAP::KEY_KP_2},                     /**< Key: Keypad 2 */
    {"KEY_KP_3", KEY_MAP::KEY_KP_3},                     /**< Key: Keypad 3 */
    {"KEY_KP_4", KEY_MAP::KEY_KP_4},                     /**< Key: Keypad 4 */
    {"KEY_KP_5", KEY_MAP::KEY_KP_5},                     /**< Key: Keypad 5 */
    {"KEY_KP_6", KEY_MAP::KEY_KP_6},                     /**< Key: Keypad 6 */
    {"KEY_KP_7", KEY_MAP::KEY_KP_7},                     /**< Key: Keypad 7 */
    {"KEY_KP_8", KEY_MAP::KEY_KP_8},                     /**< Key: Keypad 8 */
    {"KEY_KP_9", KEY_MAP::KEY_KP_9},                     /**< Key: Keypad 9 */
    {"KEY_KP_DECIMAL", KEY_MAP::KEY_KP_DECIMAL},         /**< Key: Keypad Decimal */
    {"KEY_KP_DIVIDE", KEY_MAP::KEY_KP_DIVIDE},           /**< Key: Keypad Divide */
    {"KEY_KP_MULTIPLY", KEY_MAP::KEY_KP_MULTIPLY},       /**< Key: Keypad Multiply */
    {"KEY_KP_SUBTRACT", KEY_MAP::KEY_KP_SUBTRACT},       /**< Key: Keypad Subtract */
    {"KEY_KP_ADD", KEY_MAP::KEY_KP_ADD},                 /**< Key: Keypad Add */
    {"KEY_KP_ENTER", KEY_MAP::KEY_KP_ENTER},             /**< Key: Keypad Enter */
    {"KEY_KP_EQUAL", KEY_MAP::KEY_KP_EQUAL},             /**< Key: Keypad Equal */
};
