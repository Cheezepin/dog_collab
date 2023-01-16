#include "src/game/hud.h"
#include "src/game/level_update.h"
#include "levels/pss/header.h"

void bhv_cheezeplat_loop(void) {
    if(cur_obj_is_mario_on_platform()) {
        o->oAction = 1;
    } else if(dist_between_objects(gMarioObject, o) > 1500.0f) {
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        o->oAction = 0;
    }
    if(o->oAction == 1) {
        if(o->oPlatformSpeed < 80.0f && o->oPosY < 500.0f) {
            o->oPlatformSpeed += 1.0f;
        }
        else if(o->oPlatformSpeed > 0.0f && o->oPosY > 500.0f) {
             o->oPlatformSpeed -= 2.0f;
             if(o->oPlatformSpeed <= 0.0f) {
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND);
             }
        }
        
        o->oVelZ = -o->oPlatformSpeed;
        o->oVelY = o->oPlatformSpeed;
        o->oPosY += o->oVelY;
        o->oPosZ += o->oVelZ;
        if(o->oPlatformSpeed > 0.0f) {
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
        }
    }
}

void explode(s16 dontDeactivate) {
    struct Object *explosion;
    explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
    explosion->oGraphYOffset += 100.0f;
    if(dontDeactivate == 0)
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
}

struct CollisionData *bombwallCols[2] = {
    &cheezebombwall_collision,
    &cheeze_bombwall2_collision
};

void bhv_cheezebombwall_loop(void) {
    f32 dist;
    if(o->collisionData == 0) {
        o->collisionData = segmented_to_virtual(bombwallCols[o->oBehParams2ndByte]);
    }
    if(lateral_dist_between_objects(o, cur_obj_find_nearest_object_with_behavior(bhvCheezeDog, &dist)) < 75.0f) {
        explode(0);
    }
    load_object_collision_model();
    o->oInteractStatus = 0;
}

static struct ObjectHitbox sKoopatrolHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ -1,
    /* radius:            */ 60,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 130,
};


static u8 sKoopatrolUnshelledAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_koopatrol_init(void) {
    obj_set_hitbox(o, &sKoopatrolHitbox);
    o->oKoopatrolCooldown = 0;
}

struct Surface *surf;
Vec3f dir;
Vec3f hitpos;
Vec3f pos;
f32 koopatrolViewRange = 2000.0f;

s32 check_if_mario_is_seen(void) {
    s32 searchAngle = o->oAngleToMario - o->oMoveAngleYaw;
    f32 distFromHit;
    f32 rayDist;
    
    while(searchAngle >= 0x10000) {searchAngle -= 0x10000;}
    while(searchAngle < 0x0) {searchAngle += 0x10000;}

    if(o->oKoopatrolCooldown > 0) {
        o->oKoopatrolCooldown--;
        return FALSE;
    }
    //print_text_fmt_int(220, 20, "0x%x", searchAngle);

    vec3f_set(pos, o->oPosX, o->oPosY + 150.0f, o->oPosZ);
    if(o->oDistanceToMario < koopatrolViewRange) {
        rayDist = o->oDistanceToMario;
    } else {
        rayDist = koopatrolViewRange;
    }
    vec3f_set(dir, sins(o->oAngleToMario)*rayDist, 0, coss(o->oAngleToMario)*rayDist);
    vec3f_set(hitpos, 0, 0, 0);
    find_surface_on_ray(pos, dir, &surf, hitpos, RAYCAST_FIND_FLOOR | RAYCAST_FIND_CEIL | RAYCAST_FIND_WALL);
    //print_text_fmt_int(180, 40, "%d", (s32)hitpos[0]);
    //print_text_fmt_int(250, 40, "%d", (s32)hitpos[2]);
    distFromHit = sqrtf(POW2(o->oPosX - hitpos[0]) + POW2(o->oPosZ - hitpos[2]));
    //print_text_fmt_int(180, 80, "%d", (s32)rayDist);
    //print_text_fmt_int(180, 60, "%d", (s32)distFromHit);
    if((searchAngle < 0x3800 || searchAngle > 0x0000C800) && o->oDistanceToMario < koopatrolViewRange && absf(gMarioState->pos[1] + 150.0f - o->oPosY) <= o->oDistanceToMario && distFromHit >= rayDist - 1.0f) {
        return TRUE;
    }
    return FALSE;
}

void bhv_koopatrol_loop(void) {
    f32 koopatrolRange = 100.0f;
    f32 rayDist;
    f32 distFromHit;
    s32 angle;
    f32 x = 99999.9f;
    f32 z = 99999.9f;
    struct Surface *floor = 0;
    s32 searchAngle = o->oAngleToMario - o->oMoveAngleYaw;
    while(searchAngle >= 0x10000) {searchAngle -= 0x10000;}
    while(searchAngle < 0x0) {searchAngle += 0x10000;}

    if ((o->oRoom != -1 && gMarioCurrentRoom != o->oRoom) || (o->activeFlags & ACTIVE_FLAG_FAR_AWAY)) {
        o->oAction = 4;
    }

    switch(o->oAction) {
        case 0:
            x = 99999.9f;
            z = 99999.9f;
            floor = 0;
            while(sqrtf(POW2(x) + POW2(z)) > koopatrolRange || floor == 0) {
                x = (random_float() - 0.5f)*koopatrolRange*2;
                z = (random_float() - 0.5f)*koopatrolRange*2;
                find_floor(o->oHomeX + x, o->oHomeY, o->oHomeZ + z, &floor);
            }

            o->oKoopatrolTargetX = o->oHomeX + x;
            o->oKoopatrolTargetZ = o->oHomeZ + z;
            o->oAction = 1;
            o->oForwardVel = 0.0f;
            break;
        case 1:
            angle = atan2s((o->oKoopatrolTargetZ - o->oPosZ), (o->oKoopatrolTargetX - o->oPosX));
            o->oForwardVel = 20.0f;
            cur_obj_init_animation_with_accel_and_sound(1, 2.1f);
            koopa_play_footstep_sound(1, 21);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, angle, 0x400);
            if(o->oMoveAngleYaw == angle) {
                o->oForwardVel = 20.0f;
            } else {
                o->oForwardVel = 0.0f;
            }
            if(sqrtf(POW2(o->oKoopatrolTargetZ - o->oPosZ) + POW2(o->oKoopatrolTargetX - o->oPosX)) < 25.0f || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oTimer > 150) {
                o->oAction = 2;
            }
            if(check_if_mario_is_seen()) {
                o->oAction = 3;
                cur_obj_play_sound_2(SOUND_OBJ_KOOPA_TALK);
            }
            break;
        case 2:
            cur_obj_init_animation_with_accel_and_sound(1, 1.0f);
            if(o->oTimer > 150) {
                if((random_u16() % 10 == 0)) {
                    o->oAction = 0;
                }
            }
            //o->oMoveAngleYaw += 0x100;
            o->oForwardVel = 5.0f;
            if(check_if_mario_is_seen()) {
                o->oAction = 3;
                cur_obj_play_sound_2(SOUND_OBJ_KOOPA_TALK);
            }
            break;
        case 3:
            cur_obj_init_animation_with_accel_and_sound(2, 3.0f);
            koopa_play_footstep_sound(1, 21);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
            o->oForwardVel = 32.0f;
            vec3f_set(pos, o->oPosX, o->oPosY + 150.0f, o->oPosZ);
            vec3f_set(pos, o->oPosX, o->oPosY + 150.0f, o->oPosZ);
            if(o->oDistanceToMario < koopatrolViewRange) {
                rayDist = o->oDistanceToMario;
            } else {
                rayDist = koopatrolViewRange;
            }
            vec3f_set(dir, sins(o->oAngleToMario)*rayDist, 0, coss(o->oAngleToMario)*rayDist);
            vec3f_set(hitpos, 0, 0, 0);
            find_surface_on_ray(pos, dir, &surf, hitpos, RAYCAST_FIND_FLOOR | RAYCAST_FIND_CEIL | RAYCAST_FIND_WALL);
            distFromHit = sqrtf(POW2(o->oPosX - hitpos[0]) + POW2(o->oPosZ - hitpos[2]));
            if(o->oTimer > 60 && (o->oDistanceToMario > koopatrolViewRange || distFromHit < rayDist - 1.0f)) {
                o->oAction = 2;
                o->oKoopatrolCooldown = 75;
            }
            break;
        case 4:
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            if(gMarioCurrentRoom == o->oRoom || !(o->activeFlags & ACTIVE_FLAG_FAR_AWAY)) {
                o->oAction = 0;
            }
            break;
    }
    cur_obj_move_standard(78);
    cur_obj_update_floor_and_walls();
    if ((gCurrentObject->oMoveFlags & OBJ_MOVE_HIT_WALL) && gCurrentObject->oAction != 3) {
        gCurrentObject->oMoveAngleYaw = 0x8000 + gCurrentObject->oWallAngle * 2 - gCurrentObject->oMoveAngleYaw;
    }
    mtxf_align_terrain_triangle(gCurrentObject->transform, &gCurrentObject->oPosX, gCurrentObject->oMoveAngleYaw, 60.f);
}

void bhv_bowser_snowball_loop(void) {
    if(o->header.gfx.scale[0] < 0.5f) {
        cur_obj_scale(o->header.gfx.scale[0] + 0.0625f);
        o->oGraphYOffset = o->header.gfx.scale[0]*400.0f;
    }
    o->oPosX += (-64.0f) * 0.75f;
    o->oPosY += (-64.0f) * 0.45f;
    o->oMoveAnglePitch += 0x1000;
    if(o->oTimer > 150) {
        obj_mark_for_deletion(o);
        spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
        return set_mario_action(gMarioState, ACT_SKIING, 0);
    }
    o->oPosY += o->oGraphYOffset;
    print_text_fmt_int(20, 20, "%d", (s32)dist_between_objects(gMarioObject, o));
    if(dist_between_objects(gMarioObject, o) < 250.0f && gMarioState->action != ACT_ROLLED_UP) {
        o->oTimer = 120;
        set_mario_action(gMarioState, ACT_ROLLED_UP, 0);
        vec3f_set(gMarioState->pos, o->oPosX, o->oPosY - 150.0f, o->oPosZ);
    }
    o->oPosY -= o->oGraphYOffset;
}

Vec3f warpBoxScaleFrames[] = {
    {0.6f, 0.4f, 0.6f},
    {0.525f, 0.475f, 0.525f},
    {0.495f, 0.525f, 0.495f},
    {0.45f, 0.575f, 0.45f},
    {0.4625f, 0.5625f, 0.4625f},
    {0.475f, 0.55f, 0.475f},
    {0.525f, 0.525f, 0.525f},
    {0.575f, 0.575f, 0.575f},
    {0.625f, 0.625f, 0.625f},
};

void bhv_warp_box_init(void) {
    o->collidedObjs[0] = 0;
    o->oAction = 0;
    o->oSubAction = 0;
}

void bhv_warp_box_loop(void) {
    if((o->oBehParams >> 24) == 0) {
        if(o->oAction == 1) {
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            if(o->oPosY > o->oHomeY && o->oSubAction == 0) {
                o->oSubAction = 1;
            }
            if(o->oSubAction == 1 && o->oPosY <= o->oHomeY - 20.0f) {
                o->oVelY = 0;
                o->oPosY = o->oHomeY - 20.0f;
            } else {
                o->oPosY += o->oVelY;
                o->oVelY -= 4.0f;
            }

            if(o->oSubAction == 1) {
                if(o->oWarpBoxInnerScale < 1.0f) {
                    o->oWarpBoxInnerScale += .125f;
                    o->oTimer = 0;
                }
                else {
                    if(o->oTimer < 9) {
                        s32 idx = o->oTimer - 1;
                        idx = CLAMP(idx, 0, ARRAY_COUNT(warpBoxScaleFrames));
                        vec3f_copy(o->header.gfx.scale, warpBoxScaleFrames[idx]);
                    }
                    if(o->oTimer == 15) {
                        sDelayedWarpOp = 1;
                        sDelayedWarpArg = 0x00000002;
                        sDelayedWarpTimer = 2;
                        sSourceWarpNodeId = o->oBehParams2ndByte;
                    }
                }
            }
        }

        if(o->collidedObjs[0] == gMarioObject && o->oAction == 0) {
            gMarioState->action = ACT_WAITING_FOR_DIALOG;
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            o->oAction = 1;
            o->oTimer = 0;
            o->oPosY -= 50.0f;
            o->oVelY = 25.0f;
            stop_shell_music();
            play_sound(SOUND_CUSTOM_WARP_BOX_IN, gGlobalSoundSource);
        }
        if(o->oWarpBoxInnerScale >= 1.0f) {
            o->oAnimState = 0;
        } else {
            o->oAnimState = 1;
        }
    } else if(gCurrCreditsEntry == NULL) {
        if(sSourceWarpNodeId != 0xF1) {
            if(o->oTimer < 9) {
                s32 idx = o->oTimer - 1;
                idx = CLAMP(idx, 0, ARRAY_COUNT(warpBoxScaleFrames));
                vec3f_copy(o->header.gfx.scale, warpBoxScaleFrames[idx]);
                o->oWarpBoxInnerScale = 1.0f;
            }
            if(o->oTimer == 4) {
                set_mario_action(gMarioState, ACT_EMERGE_FROM_PIPE, 1);
            }
            if(o->oTimer == 17) {
                play_sound(SOUND_CUSTOM_WARP_BOX_OUT, gGlobalSoundSource);
            }
            if(o->oTimer >= 15) {
                if(o->oWarpBoxInnerScale > 0.001f) {
                    o->oWarpBoxInnerScale -= 0.125f;
                }
            } else {
                gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            }
            if(o->oTimer == 30) {
                struct Object *explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                explosion->oGraphYOffset += 100.0f;
                obj_mark_for_deletion(o);
            }
        } else {
            obj_mark_for_deletion(o);
        }
    } else if(o->oTimer == 2) {
        // level_set_transition(2, NULL);
        // warp_special(WARP_SPECIAL_INTRO_SPLASH_SCREEN);
    }
    if(o->oWarpBoxInnerScale < 0.001f) {
        o->oWarpBoxInnerScale = 0.001f;
    }
}

void bhv_peach_cutscene_loop(void) {
    if(gCurrCreditsEntry != NULL) {o->oMoveAngleYaw = o->oFaceAngleYaw = 0xD000; return cur_obj_init_animation(PEACH_ANIM_WAVING);}
    set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
    gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_STAR_COUNT;
    switch(gIntroCutsceneState) {
        case 0:
            if(gDialogResponse == 0) {create_dialog_box(CHEEZE_DIALOG_1); o->oSubAction = 1;}
            if(gDialogResponse != 0 && o->oSubAction == 1) {
                gIntroCutsceneState++;
                o->oSubAction = 0;
                gKeyboard = 1;
            }
            break;
        case 1:
            if(gKeyboard == 0) {
                gIntroCutsceneState++;
                o->oSubAction = 0;
            }
            break;
        case 2:
            if(gDialogResponse == 0) {create_dialog_box(CHEEZE_DIALOG_2); o->oSubAction = 1;}
            if(gDialogResponse != 0 && o->oSubAction == 1) {
                struct Object *bows = spawn_object_abs_with_rot(o, 0, MODEL_BOWSER, bhvBowserCutscene, 2300, 0, -65, 0, 0xC000, 0);
                bows->oForwardVel = 80.0f;
                gIntroCutsceneState++;
                o->oSubAction = 0;
                o->oTimer = 0;
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(0, SEQ_LEVEL_BOSS_KOOPA), 0);
            }
            break;
        case 3:
            if(gDialogResponse == 0 && o->oTimer > 15) {create_dialog_box(CHEEZE_DIALOG_3); o->oSubAction = 1;}
            if(gDialogResponse != 0 && o->oSubAction == 1) {
                gIntroCutsceneState++;
                o->oSubAction = 0;
            }
            break;
        case 4:
            if(gDialogResponse == 0) {create_dialog_box(CHEEZE_DIALOG_4); o->oSubAction = 1;}
            if(gDialogResponse != 0 && o->oSubAction == 1) {
                gIntroCutsceneState++;
                o->oSubAction = 0;
            }
            break;
        case 5:
            if(gDialogResponse == 0) {create_dialog_box(CHEEZE_DIALOG_5); o->oSubAction = 1;}
            if(gDialogResponse != 0 && o->oSubAction == 1) {
                gIntroCutsceneState++;
                o->oSubAction = 0;
                o->oTimer = 0;
            }
            break;
        case 6:
            if(o->oTimer >= 25) {vec3f_copy(&o->oPosX, bowserRightHandLocation);}
            if(o->oTimer == 65) {
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
            }
            if(o->oTimer >= 75) {
                gIntroCutsceneState++;
                o->oTimer = 0;
            }
            break;
        case 7:
            if(o->oTimer == 60) {
                sDelayedWarpOp = 1;
                sDelayedWarpArg = 0x00000002;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 15, 0x00, 0x00, 0x00);
                sDelayedWarpTimer = 15;
                sSourceWarpNodeId = 0x01;
            }
            break;
    }
}

void bhv_cutscenedog_loop(void) {
    gCamera->cutscene = CUTSCENE_INTRO;

    if(gIntroCutsceneState < 3) {
        o->oPosX = o->oHomeX + 125.0f*coss(o->oTimer * 0x400);
        o->oPosZ = o->oHomeZ - 125.0f*sins(o->oTimer * 0x400);
        o->oMoveAngleYaw = (o->oTimer * 0x400) - 0x7800;
    } else {
        f32 targetX = gMarioState->pos[0] + 125.0f*coss(gMarioState->faceAngle[1] + 0x4000);
        f32 targetZ = gMarioState->pos[2] - 125.0f*sins(gMarioState->faceAngle[1] + 0x4000);
        if(POW2(targetX - o->oPosX) + POW2(targetZ - o->oPosZ) < 400.0f) {
            o->oMoveAngleYaw = 0x2000;
            cur_obj_init_animation(DOG_ANIM_IDLE);
            o->oPosX = targetX + 5.0f*(random_float() - 0.5f);
            o->oPosZ = targetZ + 5.0f*(random_float() - 0.5f);
        } else {
            o->oMoveAngleYaw = atan2s(targetZ - o->oPosZ, targetX - o->oPosX);
            o->oForwardVel = 40.0f;
            cur_obj_compute_vel_xz();
            cur_obj_move_xz_using_fvel_and_yaw();
        }
    }
}

void bhv_bowser_cutscene_loop(void) {
    if(o->oForwardVel > 0.0f) {
        cur_obj_compute_vel_xz();
        cur_obj_move_xz_using_fvel_and_yaw();
        o->oForwardVel -= 4.0f;
        if(o->oForwardVel <= 0.0f) {
            cur_obj_init_animation(BOWSER_ANIM_IDLE);
        }
    } else {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, 0xA000, 0x400);
    }

    if(gIntroCutsceneState == 6) {
        if(o->oTimer < 35) {cur_obj_init_animation(BOWSER_ANIM_DANCE);}
        else {cur_obj_init_animation(BOWSER_ANIM_JUMP_START);}
        if(o->oTimer == 30) {create_sound_spawner(SOUND_OBJ2_BOWSER_ROAR);}
        if(o->oTimer == 60) {create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);}
        if(o->oTimer > 45) {
            o->oPosY += 40.0f;
            o->oForwardVel = 10.0f;
            cur_obj_compute_vel_xz();
            cur_obj_move_xz_using_fvel_and_yaw();
        }
    } else if(gIntroCutsceneState == 7) {
        o->oPosY = 50000.0f;
    } else {
        o->oTimer = 0;
    }
}

void bhv_door_cutscene_loop(void) {
    if(gIntroCutsceneState == 3) {
        if(o->oTimer == 5) {
            create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
            obj_mark_for_deletion(o);
        }
    } else {
        o->oTimer = 0;
    }
}

void bhv_spiresdog_loop(void) {
    switch(o->oAction) {
        s32 dialogResponse;
        case 0:
            if(lateral_dist_between_objects(gMarioObject, o) < 200.0f) {
                dialogResponse = cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, CHEEZE_DIALOG_7);
                if(dialogResponse == 0x03) {
                    o->oAction++;
                    if(gCurrLevelNum == LEVEL_PSS) {
                        o->oPathedStartWaypoint = o->oPathedPrevWaypoint = segmented_to_virtual(pss_area_2_spline_dogpath);
                    } else if(o->oBehParams2ndByte == 1) {
                        o->oPathedStartWaypoint = o->oPathedPrevWaypoint = segmented_to_virtual(ssl_area_1_spline_dogpath2);
                    } else {
                        o->oPathedStartWaypoint = o->oPathedPrevWaypoint = segmented_to_virtual(ssl_area_1_spline_dogpath1);
                    }
                }
            }
            break;
        case 1:
            if (cur_obj_follow_path() == PATH_REACHED_END) {
                o->oAction++;
                cur_obj_init_animation(DOG_ANIM_IDLE);
            } else {
                o->oGravity = -4.0f;
                cur_obj_update_floor_and_walls();
                cur_obj_rotate_yaw_toward(o->oPathedTargetYaw, 0x800);
                cur_obj_move_standard(-78);
                if ((o->oMoveFlags & OBJ_MOVE_HIT_EDGE)) {
                    o->oVelY = 60.0f;
                    o->oSubAction = 1;
                }
                if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                    o->oSubAction = 0;
                    o->oForwardVel = 12.0f;
                } else {
                    o->oForwardVel = 22.0f;
                }
                if(o->oSubAction == 0) {
                    cur_obj_init_animation(DOG_ANIM_RUN);
                } else {
                    cur_obj_init_animation(DOG_ANIM_POUNCE);
                }
            }
            break;
    }
    if(gMarioState->action == ACT_FLOOR_CHECKPOINT_WARP_IN) {vec3f_copy(&o->oPosX, &o->oHomeX); o->oAction = 0; o->oSubAction = 0;}
}

void bhv_cheeze_lightning_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    if(gCurrLevelNum == LEVEL_CASTLE_GROUNDS) {
        cur_obj_scale(0.125f);
        if((o->oBehParams & 0xFF) == 1) {
            cur_obj_scale(0.05f);
        }
    } else {
        obj_set_billboard(o);
    }
}

void bhv_cheeze_lightning_loop(void) {
    o->oMoveAngleYaw = o->oAngleToMario;
    if((gGlobalTimer % 3) == 0) {
        o->oAnimState++;
    }
    if(o->oAnimState == 3) {
        cur_obj_hide();
    }
    if(o->oAnimState == 25) {
        o->oAnimState = 0;
        cur_obj_unhide();
    }
}

void bhv_peach_ending_loop(void) {
    set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
    switch(gEndingCutsceneState) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 2);
            if(o->oOpacity < 255) {
                o->oPosY -= o->oPosY < 150.0f ? o->oPosY / 37.5f : 8.0f;
                o->oVelY = 0;
            } else {
                o->oVelY -= 0.5f;
                o->oPosY += o->oVelY;
                cur_obj_init_animation(PEACH_ANIM_KISS);
            }
            if(o->oPosY <= 0.0f) {gEndingCutsceneState++;}
            vec3f_set(gMarioState->pos, -375.0f, 0.0f, 0.0f);
            vec3f_set(&find_any_object_with_behavior(bhvB3Dog)->oPosX, -500.0f, 0.0f, 0.0f);
            gMarioState->faceAngle[1] = 0x4000;
            find_any_object_with_behavior(bhvB3Dog)->oMoveAngleYaw = obj_angle_to_object(find_any_object_with_behavior(bhvB3Dog), o);
            break;
        case 1:
            if(gDialogResponse == 0) {create_dialog_box(CHEEZE_DIALOG_8); o->oSubAction = 1;}
            if(gDialogResponse != 0 && o->oSubAction == 1) {
                gEndingCutsceneState++;
                o->oSubAction = 0;
            }
            break;
        case 2:
            gCurrCreditsEntry = &sCreditsSequence[0];
            play_cutscene_music(SEQUENCE_ARGS(0, SEQ_CREDITS));
            level_trigger_warp(gMarioState, WARP_OP_CREDITS_NEXT);
            gEndingCutsceneState++;
            o->oTimer = 0;
            break;
        case 3:
            if(o->oTimer == 59) {gCamera->cutscene = 0;}
            break;
    }
    /*if(o->oTimer == 30) {
        gCurrCreditsEntry = &sCreditsSequence[0];
        play_cutscene_music(SEQUENCE_ARGS(0, SEQ_CREDITS));
        level_trigger_warp(gMarioState, WARP_OP_CREDITS_NEXT);
    }*/
}

void bhv_dog_bone_init(void) {
    if(save_file_check_dog_bone_collected(gCurrSaveFileNum - 1, gCurrAreaIndex, gCurrLevelNum)) {
        obj_mark_for_deletion(o);
    }
}

void bhv_dog_bone_loop(void) {
    o->oFaceAngleYaw += 0x400;
    o->oPosY = o->oHomeY + 10.0f*sins(o->oTimer * 0x500);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        s32 numBones;

        save_file_set_dog_bone_bit(gCurrSaveFileNum - 1, gCurrAreaIndex, gCurrLevelNum);
        numBones = save_file_get_dog_bone_count(gCurrSaveFileNum - 1);
        spawn_orange_number(numBones, 0, 0, 0);

        // On all versions but the JP version, each coin collected plays a higher noise.
        play_sound(SOUND_MENU_COLLECT_RED_COIN
                    + (((u8) numBones - 1) << 16),
                    gGlobalSoundSource);

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

void bhv_save_switch_loop(void) {
    save_file_set_flags(SAVE_FLAG_B3_CHECKPOINT_REACHED);
    if(o->oAction == PURPLE_SWITCH_ACT_PRESSED && o->oTimer == 1) {
        gSaveFileModified = TRUE;
        save_file_do_save(gCurrSaveFileNum - 1);
    }
}

void bhv_special_warp_box_init(void) {
    if(!(save_file_get_flags() & SAVE_FLAG_B3_CHECKPOINT_REACHED)) {
        obj_mark_for_deletion(o);
    }
}


