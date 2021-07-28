#pragma once

#include <ultra64.h>

// Given an empty texture table (t_array), ROM location (rom_loc),
// and params (width, height, g_img_siz, texture count), fills out the table with pointers
void dmat_init(u32 **t_array, u8 *rom, u32 width, u32 height, u32 g_img_siz, u32 count);

// Performs a DMA from t_array[idx] to t_pointer. Wraps around based on count
void dmat_copy(u8 *t_pointer, u32 **t_array, u32 idx, u32 count);


