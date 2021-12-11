#define DOG_ANIM_IDLE 0
#define DOG_ANIM_DIG  1
#define DOG_ANIM_RUN  2
#define DOG_ANIM_WALK 3
#define DOG_ANIM_POUNCE 4

#define OBJ_COL_FLAG_GROUNDED   (1 << 0)

void dog_FollowMario(void) {
    s16 colFlags = object_step();
    if (o->oDistanceToMario > 1000) {
        cur_obj_init_animation(DOG_ANIM_RUN);
        o->oForwardVel = 20.0f;
        obj_turn_toward_object(o, gMarioObject, 16, 0x800);
    } else if (o->oDistanceToMario > 500) {
        if (o->oTimer > 18) {
            cur_obj_init_animation(DOG_ANIM_WALK);
            o->oForwardVel = 10.0f;
            obj_turn_toward_object(o, gMarioObject, 16, 0x800);
        }
    } else {
        o->oTimer = 0;
        cur_obj_init_animation(DOG_ANIM_IDLE);
        o->oForwardVel = 0.0f;
    }
    struct MarioState *m = gMarioState;
    // zoom to mario
    if ((o->oPosY + 50.0f < m->pos[1]) && m->action & (ACT_FLAG_STATIONARY | ACT_FLAG_MOVING)) {
        #define DOG_SNAP_SPEED 25.0f
        o->oPosX = approach_f32(o->oPosX, m->pos[0], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        o->oPosY = approach_f32(o->oPosY, m->pos[1], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        o->oPosZ = approach_f32(o->oPosZ, m->pos[2], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
    }
}


s32 dog_rotate_to_intended_yaw(s32 target) {
    //return approach_s16_symmetric(o->oMoveAngleYaw, target, 0x1000);
    return target;
}

void bhv_cheezedog_loop(void) {
    if(gPlayer1Controller->buttonPressed & L_TRIG) {
        gCurrentCharacter ^= 0x1;
        if(gCurrentCharacter == 0) {
            gPuppyCam.targetObj = gMarioObject;
            set_mario_action(gMarioState, ACT_IDLE, 0);
        }
    }


    if(gCurrentCharacter == 0x1) {
        f32 controllerMagnitude = sqrtf(POW2(gPlayer1Controller->stickX) + POW2(gPlayer1Controller->stickY));
        gPuppyCam.targetObj = o;
        set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);

        switch(o->oAction) {
            case 0:
                if(controllerMagnitude > 5.0f) {
                    o->oMoveAngleYaw = dog_rotate_to_intended_yaw(atan2s(-gPlayer1Controller->stickY, gPlayer1Controller->stickX) + gPuppyCam.yaw);
                    o->oForwardVel = controllerMagnitude / 1.5f;
                    cur_obj_init_animation_with_accel_and_sound(DOG_ANIM_RUN, o->oForwardVel / 20.0f);
                } else {
                    o->oForwardVel = 0.0f;
                    cur_obj_init_animation(DOG_ANIM_IDLE);
                }
                o->oWallHitboxRadius = 50.0f;
                if(o->oMoveFlags & OBJ_MOVE_IN_AIR) {
                    cur_obj_init_animation(DOG_ANIM_RUN);
                    o->oGravity = -4.0f;
                } else {
                    mtxf_align_terrain_triangle(gCurrentObject->transform, &gCurrentObject->oPosX, gCurrentObject->oMoveAngleYaw, 60.0f);
                    gCurrentObject->header.gfx.throwMatrix = &gCurrentObject->transform;
                    if(gPlayer1Controller->buttonPressed & A_BUTTON) {o->oVelY = 48.0f; o->oGravity = -4.0f;}
                    if(gPlayer1Controller->buttonPressed & B_BUTTON) {o->oAction = 1; o->oVelY = 24.0f; o->oGravity = -4.0f;}
                }

                if(o->oVelY < -64.0f) {o->oVelY = -64.0f;}

                break;
            case 1:
                cur_obj_init_animation(DOG_ANIM_POUNCE);
                o->oForwardVel = 100.0f;
                if(!(o->oMoveFlags & OBJ_MOVE_IN_AIR)) {
                   o->oAction = 0;
                }
                break;
        }
        cur_obj_move_standard(78);
        cur_obj_update_floor_and_walls_and_ceil(100.0f);
        if(o->oVelY < -64.0f) {o->oVelY = -64.0f;}
        if(o->oPosY - o->oFloorHeight >= 0.0f && o->oPosY - o->oFloorHeight < 20.0f) {
            o->oMoveFlags &= ~OBJ_MOVE_IN_AIR;
            o->oPosY = o->oFloorHeight;
            o->oVelY = 0;
        }
    }
}
