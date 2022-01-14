// electric_ring.c.inc
//#include "levels/bowser_1/electric_ring/collision_header.h"

/**
 * Bowser's shockwave attack main loop
 */
s32 expansionPhase = 0;
void bhv_bowser_electric_ring_loop(void) {
    if (expansionPhase == 0){
    o->header.gfx.scale[0] = o->header.gfx.scale[0] + 0.2f;
    o->header.gfx.scale[1] = o->header.gfx.scale[1] + 0.2f;
    o->header.gfx.scale[2] = o->header.gfx.scale[2] + 0.2f;
    if (o->header.gfx.scale[0] > 20.0f){
        expansionPhase = 1;
    }
    }
    if (expansionPhase == 1){
    o->header.gfx.scale[0] = o->header.gfx.scale[0] - 0.2f;
    o->header.gfx.scale[1] = o->header.gfx.scale[1] - 0.2f;
    o->header.gfx.scale[2] = o->header.gfx.scale[2] - 0.2f;
    if (o->header.gfx.scale[0] < 15.0f){
       expansionPhase = 2; 
    }
    }
    if (expansionPhase == 2){
    o->header.gfx.scale[0] = o->header.gfx.scale[0] + 1.0f;
    o->header.gfx.scale[1] = o->header.gfx.scale[1] + 1.0f;
    o->header.gfx.scale[2] = o->header.gfx.scale[2] + 1.0f;
    if (o->header.gfx.scale[0] > 45.0f){
        expansionPhase = 3;
    }
    }
   
    if (expansionPhase == 3){
        if (o->oTimer > 500){
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
    }
}
