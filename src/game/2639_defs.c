#include <ultra64.h>
#include "engine/math_util.h"
#include "puppycam2.h"
#include "level_update.h"

u32 _2639_BoB_A1_ToadTalkLatch = 0;
u32 _2639_BoB_A1_CaneCollected = 0;
u32 _2639_BoB_A1_SunglassesCollected = 1;





void Cam2639_A1RoadCam(struct gPuppyStruct *pc, struct sPuppyAngles *a) {
	print_text(50, 50, "WOW");

    
}

void try_print_debug_mario_level_info(void) {
    print_text_fmt_int(50, 50, "X %d", (s32)gMarioState->pos[0]);
    print_text_fmt_int(50, 30, "Y %d", (s32)gMarioState->pos[1]);
    print_text_fmt_int(50, 10, "Z %d", (s32)gMarioState->pos[2]);
    // print_text_fmt_int(50, 90, "A %x", gMarioState->action);
}
