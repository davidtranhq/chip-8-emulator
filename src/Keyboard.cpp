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

#include "Keyboard.h"

Keyboard::Keyboard()
    : keymap {
        {SDLK_1, 0x1},
        {SDLK_2, 0x2},
        {SDLK_3, 0x3},
        {SDLK_c, 0xC},
        
        {SDLK_4, 0x4},
        {SDLK_5, 0x5},
        {SDLK_6, 0x6},
        {SDLK_d, 0xD},
        
        {SDLK_7, 0x7},
        {SDLK_8, 0x8},
        {SDLK_9, 0x9},
        {SDLK_e, 0xE},
        
        {SDLK_a, 0xA},
        {SDLK_0, 0x0},
        {SDLK_b, 0xB},
        {SDLK_f, 0xF}
    } {
    
}

void Keyboard::press_key(SDL_Keycode code) {
    if (keymap.count(code) == 0) {
        // not a registered key
        return;
    }
    uint8_t chip8_key = keymap.at(code);
    key_pressed[chip8_key] = true;
}

void Keyboard::release_key(SDL_Keycode code) {
    if (keymap.count(code) == 0) {
        // not a registered key
        return;
    }
    uint8_t chip8_key = keymap.at(code);
    key_pressed[chip8_key] = false;
}

bool Keyboard::is_pressed(uint8_t chip8_key) {
    return key_pressed[chip8_key];
}