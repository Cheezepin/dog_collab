#define DOG_ANIM_IDLE   0
#define DOG_ANIM_DIG    1
#define DOG_ANIM_RUN    2
#define DOG_ANIM_WALK   3
#define DOG_ANIM_POUNCE 4

s32 dog_rotate_to_intended_yaw(s32 target) {
    //return approach_s16_symmetric(o->oMoveAngleYaw, target, 0x1000);
    return target;
}

void bhv_dog_control_loop(void) {
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

void bhv_cheezedog_loop(void) {
    struct Object *obj;
    f32 dist;

    //debug remove later
    // if(o->oAction < 1) {
    //     o->oAction = 1;
    // }

    o->oGravity = -2.0f;
    switch(o->oAction) {
        case 0:
            obj = cur_obj_find_nearest_object_with_behavior(bhvCheezeBombWall, &dist);
            o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
            if(lateral_dist_between_objects(o, gMarioObject) < 500.0f) {
                o->oAction = 1;
                o->oVelY = 32.0f;
                o->oMoveAngleYaw = obj_angle_to_object(o, obj);
                o->oPosY += 10.0f;
                o->oMoveFlags |= OBJ_MOVE_IN_AIR;
            }
            break;
        case 1:
            if((o->oMoveFlags & OBJ_MOVE_IN_AIR)) {
                cur_obj_init_animation(DOG_ANIM_POUNCE);
                o->oForwardVel = 40.0f;
            } else {
                o->oForwardVel = 0.0f;
                o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
                cur_obj_init_animation(DOG_ANIM_IDLE);
            }
            cur_obj_move_standard(78);
            cur_obj_update_floor_and_walls_and_ceil(100.0f);

            if(gMarioCurrentRoom == 7) {
                o->oAction = 2;
                o->oPosX = 7827.0f;
                o->oPosY = 7867.0f;
                o->oPosZ = -2954.0f;
            }
            break;
        case 2:
            obj = cur_obj_find_nearest_object_with_behavior(bhvCheezeBombWall, &dist);
            cur_obj_init_animation(DOG_ANIM_IDLE);
            o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
            if(dist_between_objects(o, gMarioObject) < 500.0f) {
                o->oAction = 3;
                o->oVelY = 32.0f;
                o->oMoveAngleYaw = obj_angle_to_object(o, obj);
                o->oPosY += 10.0f;
                o->oMoveFlags |= OBJ_MOVE_IN_AIR;
            }
            break;
        case 3:
            if((o->oMoveFlags & OBJ_MOVE_IN_AIR)) {
                cur_obj_init_animation(DOG_ANIM_POUNCE);
                o->oForwardVel = 40.0f;
            } else if((POW2(8747.0f - o->oPosX) + POW2(-182.0f - o->oPosZ)) > 100000.0f) {
                //x 8747
                //z -182
                o->oMoveAngleYaw = atan2s((-182.0f - o->oPosZ), (8474.0f - o->oPosX));
                o->oForwardVel = 40.0f;
                cur_obj_init_animation(DOG_ANIM_RUN);
            } else {
                o->oForwardVel = 0.0f;
                o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
                cur_obj_init_animation(DOG_ANIM_IDLE);
            }
            cur_obj_move_standard(78);
            cur_obj_update_floor_and_walls_and_ceil(100.0f);

            if(gMarioState->action == ACT_VERTICAL_WIND) {
                o->oAction = 4;
            }
            break;
        case 4:
            o->oForwardVel = 0;
            o->oVelY += 10.0f;
            cur_obj_move_standard(78);
            cur_obj_update_floor_and_walls_and_ceil(100.0f);
            if(gMarioState->pos[1] > 12000.0f && o->oSubAction == 0) {
                o->oSubAction = 1;
                sDelayedWarpOp = 1;
                sDelayedWarpArg = 0x00000002;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 15, 0xFF, 0xFF, 0xFF);
                sDelayedWarpTimer = 15;
                sSourceWarpNodeId = 0x01;
            }
            break;
    }
}
