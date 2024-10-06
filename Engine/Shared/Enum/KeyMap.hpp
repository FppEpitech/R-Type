/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

/**
 * @enum KEY_MAP
 * @brief Enumeration for key mappings.
 *
 * This enumeration defines key codes for various keys, including alphanumeric keys,
 * function keys, keypad keys, and Android key buttons. Each key is associated with
 * a unique integer value.
 */
enum KEY_MAP
{
    KEY_NULL            = 0,        /**< Key: NULL, used for no key pressed */
    // Alphanumeric keys
    KEY_APOSTROPHE      = 39,       /**< Key: ' */
    KEY_COMMA           = 44,       /**< Key: , */
    KEY_MINUS           = 45,       /**< Key: - */
    KEY_PERIOD          = 46,       /**< Key: . */
    KEY_SLASH           = 47,       /**< Key: / */
    KEY_ZERO            = 48,       /**< Key: 0 */
    KEY_ONE             = 49,       /**< Key: 1 */
    KEY_TWO             = 50,       /**< Key: 2 */
    KEY_THREE           = 51,       /**< Key: 3 */
    KEY_FOUR            = 52,       /**< Key: 4 */
    KEY_FIVE            = 53,       /**< Key: 5 */
    KEY_SIX             = 54,       /**< Key: 6 */
    KEY_SEVEN           = 55,       /**< Key: 7 */
    KEY_EIGHT           = 56,       /**< Key: 8 */
    KEY_NINE            = 57,       /**< Key: 9 */
    KEY_SEMICOLON       = 59,       /**< Key: ; */
    KEY_EQUAL           = 61,       /**< Key: = */
    KEY_A               = 65,       /**< Key: A */
    KEY_B               = 66,       /**< Key: B */
    KEY_C               = 67,       /**< Key: C */
    KEY_D               = 68,       /**< Key: D */
    KEY_E               = 69,       /**< Key: E */
    KEY_F               = 70,       /**< Key: F */
    KEY_G               = 71,       /**< Key: G */
    KEY_H               = 72,       /**< Key: H */
    KEY_I               = 73,       /**< Key: I */
    KEY_J               = 74,       /**< Key: J */
    KEY_K               = 75,       /**< Key: K */
    KEY_L               = 76,       /**< Key: L */
    KEY_M               = 77,       /**< Key: M */
    KEY_N               = 78,       /**< Key: N */
    KEY_O               = 79,       /**< Key: O */
    KEY_P               = 80,       /**< Key: P */
    KEY_Q               = 81,       /**< Key: Q */
    KEY_R               = 82,       /**< Key: R */
    KEY_S               = 83,       /**< Key: S */
    KEY_T               = 84,       /**< Key: T */
    KEY_U               = 85,       /**< Key: U */
    KEY_V               = 86,       /**< Key: V */
    KEY_W               = 87,       /**< Key: W */
    KEY_X               = 88,       /**< Key: X */
    KEY_Y               = 89,       /**< Key: Y */
    KEY_Z               = 90,       /**< Key: Z */
    KEY_LEFT_BRACKET    = 91,       /**< Key: [ */
    KEY_BACKSLASH       = 92,       /**< Key: '\' */
    KEY_RIGHT_BRACKET   = 93,       /**< Key: ] */
    KEY_GRAVE           = 96,       /**< Key: ` */
    // Function keys
    KEY_SPACE           = 32,       /**< Key: Space */
    KEY_ESCAPE          = 256,      /**< Key: Esc */
    KEY_ENTER           = 257,      /**< Key: Enter */
    KEY_TAB             = 258,      /**< Key: Tab */
    KEY_BACKSPACE       = 259,      /**< Key: Backspace */
    KEY_INSERT          = 260,      /**< Key: Ins */
    KEY_DELETE          = 261,      /**< Key: Del */
    KEY_RIGHT           = 262,      /**< Key: Cursor right */
    KEY_LEFT            = 263,      /**< Key: Cursor left */
    KEY_DOWN            = 264,      /**< Key: Cursor down */
    KEY_UP              = 265,      /**< Key: Cursor up */
    KEY_PAGE_UP         = 266,      /**< Key: Page up */
    KEY_PAGE_DOWN       = 267,      /**< Key: Page down */
    KEY_HOME            = 268,      /**< Key: Home */
    KEY_END             = 269,      /**< Key: End */
    KEY_CAPS_LOCK       = 280,      /**< Key: Caps lock */
    KEY_SCROLL_LOCK     = 281,      /**< Key: Scroll down */
    KEY_NUM_LOCK        = 282,      /**< Key: Num lock */
    KEY_PRINT_SCREEN    = 283,      /**< Key: Print screen */
    KEY_PAUSE           = 284,      /**< Key: Pause */
    KEY_F1              = 290,      /**< Key: F1 */
    KEY_F2              = 291,      /**< Key: F2 */
    KEY_F3              = 292,      /**< Key: F3 */
    KEY_F4              = 293,      /**< Key: F4 */
    KEY_F5              = 294,      /**< Key: F5 */
    KEY_F6              = 295,      /**< Key: F6 */
    KEY_F7              = 296,      /**< Key: F7 */
    KEY_F8              = 297,      /**< Key: F8 */
    KEY_F9              = 298,      /**< Key: F9 */
    KEY_F10             = 299,      /**< Key: F10 */
    KEY_F11             = 300,      /**< Key: F11 */
    KEY_F12             = 301,      /**< Key: F12 */
    KEY_LEFT_SHIFT      = 340,      /**< Key: Shift left */
    KEY_LEFT_CONTROL    = 341,      /**< Key: Control left */
    KEY_LEFT_ALT        = 342,      /**< Key: Alt left */
    KEY_LEFT_SUPER      = 343,      /**< Key: Super left */
    KEY_RIGHT_SHIFT     = 344,      /**< Key: Shift right */
    KEY_RIGHT_CONTROL   = 345,      /**< Key: Control right */
    KEY_RIGHT_ALT       = 346,      /**< Key: Alt right */
    KEY_RIGHT_SUPER     = 347,      /**< Key: Super right */
    KEY_KB_MENU         = 348,      /**< Key: KB menu */
    // Keypad keys
    KEY_KP_0            = 320,      /**< Key: Keypad 0 */
    KEY_KP_1            = 321,      /**< Key: Keypad 1 */
    KEY_KP_2            = 322,      /**< Key: Keypad 2 */
    KEY_KP_3            = 323,      /**< Key: Keypad 3 */
    KEY_KP_4            = 324,      /**< Key: Keypad 4 */
    KEY_KP_5            = 325,      /**< Key: Keypad 5 */
    KEY_KP_6            = 326,      /**< Key: Keypad 6 */
    KEY_KP_7            = 327,      /**< Key: Keypad 7 */
    KEY_KP_8            = 328,      /**< Key: Keypad 8 */
    KEY_KP_9            = 329,      /**< Key: Keypad 9 */
    KEY_KP_DECIMAL      = 330,      /**< Key: Keypad . */
    KEY_KP_DIVIDE       = 331,      /**< Key: Keypad / */
    KEY_KP_MULTIPLY     = 332,      /**< Key: Keypad * */
    KEY_KP_SUBTRACT     = 333,      /**< Key: Keypad - */
    KEY_KP_ADD          = 334,      /**< Key: Keypad + */
    KEY_KP_ENTER        = 335,      /**< Key: Keypad Enter */
    KEY_KP_EQUAL        = 336,      /**< Key: Keypad = */
    // Mouse buttons
    MOUSE_LEFT_CLICK    = 501,        /**< Mouse button: Left click */
    MOUSE_RIGHT_CLICK   = 502,        /**< Mouse button: Right click */
    MOUSE_MIDDLE_CLICK  = 503,        /**< Mouse button: Middle click */
};
