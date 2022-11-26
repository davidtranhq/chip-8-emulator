/**
 * @file System.h
 * @author David Tran, Ben Asokanthan, Dhruv Panicker, Davis Mtui, Sean Hou
 * @brief Interface for the System class
 * @version 0.5
 * @date 2022-11-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>

#include "Display.h"
#include "Processor.h"
#include "Memory.h"
#include "Keyboard.h"
#include "Sound.h"

/**
 * @brief The full emulator consisting of the processor, memory, display, keyboard, and sound.
 * 
 */
class System
{
public:
    System();
    ~System() = default;

    /**
     * @brief Run the emulator.
     * 
     */
    void run();

    /**
     * @brief Load the ROM specified at the given path into memory.
    */
    void load_rom(const std::string &rom_path);

private:
    /**
     * @brief Run the emulator for one frame
     */
    void run_for_one_frame();

private:
    Processor processor;
    Memory memory;
    Display display;
    Keyboard keyboard;
    Sound sound;

    // flag indicating if the emulator is running
    bool is_running = true;
};

#endif