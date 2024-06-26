/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_key_code
*/

#include "rpg_header.h"

const char *keyCodeStrings[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Num0", "Num1",
    "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "Escape",
    "LControl", "LShift", "LAlt", "LSystem", "RControl", "RShift", "RAlt",
    "RSystem", "Menu", "LBracket", "RBracket", "SemiColon", "Comma", "Period",
    "Apostrophe", "Slash", "BackSlash", "Grave", "Equal", "Hyphen", "Space",
    "Enter", "BackSpace", "Tab", "PageUp", "PageDown", "End", "Home",
    "Insert", "Delete", "Add", "Subtract", "Multiply", "Divide", "Left",
    "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2", "Numpad3",
    "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1",
    "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13",
    "F14", "F15", "Pause"
};

const char *key_code_to_string(sfKeyCode key)
{
    return keyCodeStrings[(int)key];
}
