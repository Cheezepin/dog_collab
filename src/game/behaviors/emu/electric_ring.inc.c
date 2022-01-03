// electric_ring.c.inc
//#include "levels/bowser_1/electric_ring/collision_header.h"

/**
 * Bowser's shockwave attack main loop
 */
s32 hurt = 0;
void bhv_bowser_electric_ring_loop(void) {
    s16 fadeFrames = 70;
   
    // Scale shockwave as the timer goes on
    o->header.gfx.scale[0] = o->header.gfx.scale[0] + 0.05f;
    o->header.gfx.scale[1] = 0.5f;
    o->header.gfx.scale[2] = o->header.gfx.scale[2] + 0.05f;
    // Slightly reduce opacity each 3 frames
    if (gGlobalTimer % 3)
        o->oOpacity -= 1;
    // Reduce opacity faster after 70 frames have passed
    if (o->oTimer > fadeFrames)
        o->oOpacity -= 5;
    // Delete object when it's fully transparent
    if (o->oOpacity <= 0)
        obj_mark_for_deletion(o);
    // If object times is less than 70 frame and Mario is not in the air...
    if (o->oTimer < fadeFrames) {
        if (gMarioState->wall) {hurt = TRUE;} else {hurt = FALSE;}
        //if (gMarioState->ceil) {if (gMarioState->ceil->object == o) {hurt = TRUE;print_text(100,100, "hurt");} else {hurt = FALSE;}}
        //if (gMarioState->floor) {if (gMarioState->floor->object == o) {hurt = TRUE;print_text(100,100, "hurt");} else {hurt = FALSE;}}
        switch (hurt) {
            case TRUE:
            gMarioObject->oInteractStatus |= INT_STATUS_MARIO_SHOCKWAVE;
            o->oInteractStatus = 0;
            break;
            case FALSE:
            break;
        }
    }
}
