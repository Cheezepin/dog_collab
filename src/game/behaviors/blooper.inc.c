#define BLOOPER_IDLE 0
#define BLOOPER_RISE 1
#define BLOOPER_FALL 2

#include "engine/surface_collision.h"

struct Surface *surface;
f32 ceilHeight;

static struct ObjectHitbox sBlooperHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 80,
};

void bhv_blooper_init(void) {
    obj_set_hitbox(o, &sBlooperHitbox);
}

void blooper_act_idle(void) {
    o->oForwardVel = 0.0f;
        if (o->oDistanceToMario < 2500.0f) {
            o->oForwardVel = 7.5f;
            if(o->oPosY < gMarioState->pos[1] - 100) 
                o->oAction = BLOOPER_RISE;
            if(o->oPosY > gMarioState->pos[1] + 50) 
                o->oPosY -= 15.0f;
        }
}

void blooper_act_rise(void) {
    o->oForwardVel = 15.0f;
    //cur_obj_compute_vel_xz();
    //cur_obj_move_using_vel();
    if (o->oTimer == 2)
        cur_obj_play_sound_2(SOUND_GENERAL_MOVING_WATER);
    if(o->header.gfx.scale[0] > 0.75f)
        o->header.gfx.scale[0] = o->header.gfx.scale[2] = o->header.gfx.scale[0] - 0.05f;
    else
        o->header.gfx.scale[0] = o->header.gfx.scale[2] = 0.75f;
    if(o->oTimer < 30 && o->oPosY < find_water_level(o->oPosX, o->oPosZ) - 300) {
        o->oPosY = o->oPosY + (30 - o->oTimer);
        if(o->oPosY > gMarioState->pos[1] && o->oTimer < 25)
            o->oTimer = 25;
    } else {
        o->oAction = BLOOPER_FALL;
    }
}

void blooper_act_fall(void) {
    o->oForwardVel = 0.0f;
    if((o->oPosY > gMarioState->pos[1] - 250.0f && o->oPosY > o->oFloorHeight + 50) || o->oTimer < 30) {
        if(o->oTimer < 10)
            o->oPosY -= o->oTimer;
        else 
            o->oPosY -= 15.0f;
    } else {
        o->oAction = BLOOPER_IDLE;
    }
}

void bhv_blooper_update(void) {

    if (obj_update_standard_actions(1.0f)) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 
                0x400);

        switch(o->oAction) {
            case BLOOPER_IDLE:
                blooper_act_idle();
                break;
            case BLOOPER_RISE:
                blooper_act_rise();
                break;
            case BLOOPER_FALL:
                blooper_act_fall();
                break;
        }

        cur_obj_move_xz_using_fvel_and_yaw();

        if(o->oAction != BLOOPER_RISE) {
            if(o->header.gfx.scale[0] < 1.0f)
                o->header.gfx.scale[0] = o->header.gfx.scale[2] = o->header.gfx.scale[0] + 0.025f;
            else
                o->header.gfx.scale[0] = o->header.gfx.scale[2] = 1.0f;
        }

        o->oFloorHeight = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
        if (o->oPosY < o->oFloorHeight + 50) {
            o->oPosY = o->oFloorHeight + 50;
        }


        ceilHeight = find_ceil(o->oPosX, o->oPosY, o->oPosZ, &surface);
        if (o->oPosY > ceilHeight - 250)
            o->oPosY = ceilHeight - 250;

        if(o->oInteractStatus != 0 && gMarioState->flags & MARIO_METAL_CAP)
            obj_set_knockback_action(5);
        o->oInteractStatus = 0;
    }
}