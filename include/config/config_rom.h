#pragma once

/****************
 * ROM SETTINGS *
 ****************/

// Internal ROM name. NEEDS TO BE **EXACTLY** 20 CHARACTERS. Can't be 19 characters, can't be 21 characters. You can fill it with spaces.
// The end quote should be here:               "
#define INTERNAL_ROM_NAME "DOG COLLAB          "

#define DOG_COLLAB_VERSION "1.0.0"

// Enables Rumble Pak Support.
// Currently not recommended, as it may cause random crashes.
// #define ENABLE_RUMBLE (1)

// Screen Size Defines.
#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

// Height of the black borders at the top and bottom of the screen for NTSC Versions. You can set it to different values for console and emulator.
// There is generally no reason to have a value other than 0 for emulator. As for console, it provides a (small) performance boost.
#define BORDER_HEIGHT_CONSOLE  0
#define BORDER_HEIGHT_EMULATOR 0

/**
 * Force the game to delete any existing save data originating from a different hack. This requires INTERNAL_ROM_NAME to be unique to work properly.
 * It is recommended to enable this if any significant changes to the save file are made that could cause issues with this or other hacks.
 * NOTE: Using save editors with this define will likely just end up wiping your save, since SM64 specific save editors most likely use hardcoded save magic.
 */
#define UNIQUE_SAVE_DATA

/**
 * The maximum number of supported controllers. 1-4.
 * This will save performance if the player has extra unused controllers plugged in.
 * NOTE: Default is 2, maximum is 4.
 * NOTE: Some flashcarts (eg. ED64p) don't let you start a ROM with a GameCube controller in port 1,
 *       so ports 1 and 2 get swapped if port 1 is an N64 controller and port 2 is a GC controller.
 *       This define should be at least 2 if you want to allow GC controllers on those flashcarts.
 */
#define NUM_SUPPORTED_CONTROLLERS 2

/**
 * Informs supported emulators to default to gamecube controller inputs.
 */
//  #define USE_GAMECUBE_CONTROLLER
