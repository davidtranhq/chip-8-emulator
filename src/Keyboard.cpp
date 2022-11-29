/**
 * @file Keyboard.cpp
 * @author David Tran, Ben Asokanthan, Dhruv Panicker, Davis Mtui, Sean Hou
 * @brief Implementation file for the Keyboard class
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>

#include "json.h"
using json = nlohmann::json;

#include <SDL2/SDL.h>

#include "Keyboard.h"

Keyboard::Keyboard() 
{
    std::ifstream f("./chip8.config.json");
    json json1 = json::parse(f);
    json json2 = json1["custom_keymap"];

    for (auto& el : json2.items()) {
        SDL_Keycode key = SDL_GetKeyFromName(el.key().c_str());
        uint8_t value = el.value();
        keymap.insert_or_assign(key, value);
    }
}

void Keyboard::press_key(SDL_Keycode code) {
    if (!is_mapped_key(code)) {
        // not a registered key
        return;
    }
    uint8_t chip8_key = keymap.at(code);
    key_pressed[chip8_key] = true;
}

void Keyboard::release_key(SDL_Keycode code) {
    if (!is_mapped_key(code)) {
        // not a registered key
        return;
    }
    uint8_t chip8_key = keymap.at(code);
    key_pressed[chip8_key] = false;
}

bool Keyboard::is_pressed(uint8_t chip8_key) {
    return key_pressed[chip8_key];
}

bool Keyboard::is_mapped_key(SDL_Keycode code) {
    return keymap.count(code) != 0;
}

/**
 * @brief Get the mapped CHIP-8 key (0x0 to 0xF) of this key.
 */
uint8_t Keyboard::chip8_keycode(SDL_Keycode keycode) {
    return keymap.at(keycode);
}