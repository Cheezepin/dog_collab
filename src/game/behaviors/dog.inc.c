#define DOG_ANIM_IDLE   0
#define DOG_ANIM_DIG    1
#define DOG_ANIM_RUN    2
#define DOG_ANIM_WALK   3
#define DOG_ANIM_POUNCE 4
#define DOG_ANIM_KB     5
#define DOG_ANIM_LASER  6
#define DOG_ANIM_BARK   7

#define OBJ_COL_FLAG_GROUNDED   (1 << 0)
#define OBJ_COL_FLAG_HIT_WALL   (1 << 1)
 #define DOG_SNAP_SPEED 40.0f
void dog_FollowMario(void) {
    struct MarioState *m = gMarioState;
    s16 colFlags = object_step();

    if ((o->oPosY + 300.0f < m->pos[1]) || (o->oDistanceToMario > 2000)) {
        obj_turn_toward_object(o, gMarioObject, 16, 0x1000);
        o->oPosX = approach_f32(o->oPosX, m->pos[0], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        o->oPosY = approach_f32(o->oPosY, m->pos[1], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        o->oPosZ = approach_f32(o->oPosZ, m->pos[2], DOG_SNAP_SPEED, DOG_SNAP_SPEED);

        if (colFlags & OBJ_COL_FLAG_HIT_WALL) {
            o->oPosX = m->pos[0];
            o->oPosY = m->pos[1];
            o->oPosZ = m->pos[2];
        }
        
    } else if (o->oDistanceToMario > 200) {
        cur_obj_init_animation(DOG_ANIM_RUN);
        o->oForwardVel = 20.0f;
        obj_turn_toward_object(o, gMarioObject, 16, 0x800);
    } else if (o->oDistanceToMario > 100) {
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
    // zoom to mario
    // if ((o->oPosY + 50.0f < m->pos[1]) && m->action & (ACT_FLAG_STATIONARY | ACT_FLAG_MOVING)) {
    //     // o->oPosX = approach_f32(o->oPosX, m->pos[0], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
    //     // o->oPosY = approach_f32(o->oPosY, m->pos[1], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
    //     // o->oPosZ = approach_f32(o->oPosZ, m->pos[2], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        
    //     if (colFlags & OBJ_COL_FLAG_HIT_WALL) {
    //         o->oPosX = m->pos[0];
    //         o->oPosY = m->pos[1];
    //         o->oPosZ = m->pos[2];
    //     }
    // }
}


s32 dog_rotate_to_intended_yaw(s32 target) {
    //return approach_s16_symmetric(o->oMoveAngleYaw, target, 0x1000);
    return target;
}

void bhv_dog_control_loop(void) {
    if(gPlayer1Controller->buttonPressed & L_TRIG) {
        gCurrentCharacter ^= 0x1;
        if(gCurrentCharacter == 0) {
#ifdef PUPPYCAM
            gPuppyCam.targetObj = gMarioObject;
#endif
            set_mario_action(gMarioState, ACT_IDLE, 0);
        }
    }


    if(gCurrentCharacter == 0x1) {
        f32 controllerMagnitude = sqrtf(POW2(gPlayer1Controller->stickX) + POW2(gPlayer1Controller->stickY));
#ifdef PUPPYCAM
        gPuppyCam.targetObj = o;
#endif
        set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);

        switch(o->oAction) {
            case 0:
                if(controllerMagnitude > 5.0f) {
                    o->oMoveAngleYaw = dog_rotate_to_intended_yaw(atan2s(-gPlayer1Controller->stickY, gPlayer1Controller->stickX) + gMarioState->area->camera->yaw);
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

void bhv_cheezeskidog_loop(void) {
    /*switch(o->oAction) {
        case 0:
            cur_obj_init_animation(DOG_ANIM_IDLE);
            switch (o->oHeldState) {
                case HELD_FREE:
                    o->oPosZ = gMarioState->pos[2];
                    if(gMarioState->action == ACT_SKIING) {
                        o->oPosX += (128.0f) * 0.75f;
                        o->oPosY += (128.0f) * 0.45f;
                    }
                    if(o->oPosX >= gMarioState->pos[0]) {
                        gMarioState->heldObj = o;
                        obj_set_held_state(gMarioState->heldObj, bhvCarrySomethingHeld);
                        gMarioState->heldObj->oMoveAngleYaw = 0x4000;
                    }
                    break;

                case HELD_HELD:
                    cur_obj_disable_rendering();
                    cur_obj_become_intangible();
                    o->oVelY = 40.0f;
                    o->oTimer = 0;
                    break;

                case HELD_THROWN:
                    o->oMoveAngleYaw = 0x4000;
                    o->oMoveAnglePitch = 0;
                    cur_obj_become_tangible();
                    cur_obj_enable_rendering();
                    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                    o->oPosX += 40.0f;
                    o->oPosY += o->oVelY;
                    o->oVelY -= 2.0f;
                    if(lateral_dist_between_objects(o, find_any_object_with_behavior(bhvBowserSnow)) < 250.0f) {
                        o->oAction = 2;
                        o->oHeldState = HELD_FREE;
                    } else
                    if(o->oTimer >= 20) {
                        o->oAction = 1;
                        o->oTimer = 0;
                        o->oHeldState = HELD_FREE;
                    }
                    print_text_fmt_int(20, 20, "%d", o->oTimer);
                    print_text_fmt_int(20, 40, "%d", (s32)lateral_dist_between_objects(o, find_any_object_with_behavior(bhvBowserSnow)));
                    break;
            }
            break;
        case 1:
            if(o->oTimer < 45) {
                o->oPosX += (-96.0f) * 0.75f;
                o->oPosY += (-96.0f) * 0.45f;
            } else {
                o->oAction = 0;
            }
            break;
        case 2:
            o->oPosY = 0.6f*o->oPosX + 125.0f;
            if(o->oTimer >= 45) {
                cur_obj_init_animation(DOG_ANIM_IDLE);
                o->oPosY = 0.6f*o->oPosX;
                if(o->oTimer < 105) {
                    o->oPosX += (-96.0f) * 0.75f;
                    o->oPosY += (-96.0f) * 0.45f;
                } else {
                    o->oAction = 0;
                }
            } else {
                cur_obj_init_animation(DOG_ANIM_DIG);
            }
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;*/

    o->oGravity = -4.0f;
    if(lateral_dist_between_objects(gMarioObject, o) > 350.0f) {
        o->oForwardVel = 20.0f;
        o->oMoveAngleYaw = o->oAngleToMario;
    } else {
        o->oForwardVel = 0.0f;
    }
    cur_obj_move_standard(78);
}

void bhv_b3_dog_loop(void) {
    switch(o->oAction) {
        case 0:
            switch (o->oHeldState) {
                struct Object *lol;
                case HELD_FREE:
                    o->oGravity = -4.0f;
                    if(find_any_object_with_behavior(bhvDogLaser)) {
                        obj_mark_for_deletion(find_any_object_with_behavior(bhvDogLaser));
                    }
                    if(lateral_dist_between_objects(gMarioObject, o) > 350.0f) {
                        o->oForwardVel = 10.0f + (lateral_dist_between_objects(gMarioObject, o) / 25.0f);
                        o->oMoveAngleYaw = o->oAngleToMario;
                        cur_obj_init_animation(DOG_ANIM_WALK);
                    } else {
                        approach_f32_ptr(&o->oForwardVel, 0.0f, 2.0f);
                        cur_obj_init_animation(DOG_ANIM_IDLE);
                    }
                    cur_obj_move_standard(-78);
                    cur_obj_update_floor_and_walls_and_ceil(100.0f);
                    if(o->oSubAction == 1) {
                        lol = spawn_object(o, MODEL_DOG_ARROW, bhvLaserGlow);
                        lol->oPosY += 250.0f + ((f32)(sins(gGlobalTimer * 0x800)))*50.0f;
                    }
                    break;

                case HELD_HELD:
                    cur_obj_disable_rendering();
                    cur_obj_become_intangible();
                    if(o->oSubAction > 0) {
                        cur_obj_init_animation(DOG_ANIM_LASER);
                        if(!find_any_object_with_behavior(bhvDogLaser)) {
                            spawn_object(o, MODEL_DOG_LASER, bhvDogLaser);
                        }
                        o->oSubAction = 2;
                    }
                    break;

                case HELD_THROWN:
                    o->oVelY = 5.0f;
                case HELD_DROPPED:
                    cur_obj_become_tangible();
                    cur_obj_enable_rendering();
                    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                    o->oHeldState = HELD_FREE;
                    break;
            }
            break;
    }
    if(o->oSubAction == 0 && find_any_object_with_behavior(bhvBowser) && find_any_object_with_behavior(bhvBowser)->oAction == BOWSER_ACT_WALK_TO_MARIO) {
        o->oSubAction = 1;
    }

    if(o->oPosY < -200.0f) {
        o->oPosY = gMarioState->pos[1] + 500.0f;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

//-125, 0
//125, 0
//-125, 4000
//125, 4000
void bhv_dog_laser_loop(void) {
    struct Object *cc = find_any_object_with_behavior(bhvChainChompBowser);
    o->parentObj = find_any_object_with_behavior(bhvB3Dog);
    vec3f_copy(&o->oPosX, dogLaserLocation);
    if(o->parentObj->oHeldState == HELD_HELD) {
        o->oMoveAngleYaw = gMarioState->faceAngle[1];
    } else {
        o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
    }
    o->oMoveAngleRoll += 0x611;
    if(cc && cc->oSubAction != CHAIN_CHOMP_SUB_ACT_BURNED) {
        f32 unrotatedCircleX, unrotatedCircleY, closestX, closestY, a, b;
        f32 rectX = o->oPosX;
        f32 rectY = o->oPosZ;
        f32 rectWidth = 125.0f; //on both sides
        f32 rectHeight = 4000.0f; //just from 0, 0
        f32 circleX = cc->oPosX;
        f32 circleY = cc->oPosZ;
        f32 radius = 300.0f;
        s32 angle = o->oMoveAngleYaw;
        unrotatedCircleX = coss(angle) * (circleX - rectX) - sins(angle) * (circleY - rectY) + rectX;
        unrotatedCircleY = sins(angle) * (circleX - rectX) + coss(angle) * (circleY - rectY) + rectY;

        // Find the unrotated closest x point from center of unrotated circle
        if (unrotatedCircleX  < (rectX - rectWidth))
            closestX = (rectX - rectWidth);
        else if (unrotatedCircleX  > (rectX + rectWidth))
            closestX = (rectX + rectWidth);
        else
            closestX = unrotatedCircleX;
        
        // Find the unrotated closest y point from center of unrotated circle
        if (unrotatedCircleY < rectY)
            closestY = rectY;
        else if (unrotatedCircleY > rectY + rectHeight)
            closestY = rectY + rectHeight;
        else
            closestY = unrotatedCircleY;
 
        a = absf(unrotatedCircleX - closestX);
        b = absf(unrotatedCircleY - closestY);
        if (o->oPosY > cc->oPosY - 50.0f && o->oPosY < cc->oPosY + 500.0f && sqrtf((a * a) + (b * b)) < radius) {
            //true
            cc->oChainChompHeated = 1;
            spawn_object(cc, MODEL_LASER_GLOW, bhvLaserGlow);
        } else {
            //false
            //cc->oChainChompHeated = 0;
        }
    }
    cur_obj_shake_screen(SHAKE_POS_SMALL);
}
