
struct ObjectHitbox sRainbowCloudHitbox = {
    /* interactType: */ INTERACT_DAMAGE,
    /* downOffset: */ 125,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 25,
    /* height: */ 125,
    /* hurtboxRadius: */ 25,
    /* hurtboxHeight: */ 125,
};

s32 notstatic_approach_f32_ptr(f32 *px, f32 target, f32 delta) {
    if (*px > target) {
        delta = -delta;
    }

    *px += delta;

    if ((*px - target) * delta >= 0) {
        *px = target;
        return TRUE;
    }
    return FALSE;
}

s32 Set_NPC_Dialog(s32 dialogId) {
    if (set_mario_npc_dialog(1) == 2) {
        o->activeFlags |= 0x20; /* bit 5 */
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialogId)
            != 0) {
            set_mario_npc_dialog(0);
            o->activeFlags &= ~0x20; /* bit 5 */
            o->oInteractStatus = 0;
            return TRUE;
        }
    }
    return FALSE;
}



//FWOOSH START
static s8 sMGCloudPartHeights[] = { 11, 8, 12, 8, 9, 9 };

void bhv_metal_crate_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvMinigameFwoosh);
    if (o->oObjF4 == NULL)
        o->activeFlags = 0;
}

void bhv_metal_crate_loop(void) {
    o->oAction = o->oObjF4->o104;
    switch (o->oAction) {
        case 0:
            o->oPosZ = approach_f32_asymptotic(o->oPosZ, o->oHomeZ, 0.05f);
            break;
        case 1:
            o->oPosZ = approach_f32_asymptotic(o->oPosZ, o->oHomeZ - 2000, 0.05f);
            break;
    }
}


void bhv_fwoosh_button_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o && !(gMarioStates[0].action & MARIO_UNKNOWN_13)) {
                o->oAction = 1;
            }
            break;
        case 1:
            cur_obj_scale_over_time(2, 3, 1.0f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = 3;
            }
            break;
        case 2:
            cur_obj_scale_over_time(2, 3, 0.2f, 1.0f);
            if (o->oTimer == 3) {
                o->oAction = 0;
            }
            break;
        case 3:
            if (!cur_obj_is_mario_on_platform()) {
                o->oAction = 2;
            }
            break;
    }
}



static void mg_fwoosh_spawn_parts(void) {
    struct Object *cloudPart;
    s32 i;

    // Spawn the pieces of the cloud itself
    for (i = 0; i < 5; i++) {
        cloudPart = spawn_object_relative(i, 0, 0, 0, o, MODEL_MIST, bhvCloudPart);

        if (cloudPart != NULL) {
            obj_set_billboard(cloudPart);
        }
    }

    if (o->oBehParams2ndByte == CLOUD_BP_FWOOSH) {
        // Spawn fwoosh's face
        spawn_object_relative(5, 0, 0, 0, o, MODEL_FWOOSH, bhvCloudPart);

        cur_obj_scale(5.0f);

        o->oCloudCenterX = o->oPosX;
        o->oCloudCenterY = o->oPosY;
    }

    o->oAction = CLOUD_ACT_MAIN;
}

/**
 * Move in a circle. Unload if mario moves far away. If mario stays close for
 * long enough, blow wind at him.
 */
static void mg_fwoosh_update(void) {
    struct Object *obj;
    obj = cur_obj_nearest_object_with_behavior(bhvFwooshButton);
    if (o->oCloudBlowing) {

        if (o->oCloudGrowSpeed > -0.18f) {
            o->header.gfx.scale[0] += o->oCloudGrowSpeed;
            o->oCloudGrowSpeed -= 0.05f;
        } else if (obj->oAction == 3) {
            cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
            cur_obj_spawn_strong_wind_particles(6, 3.0f, 0.0f, -50.0f, 120.0f);
            o->o104 = 1;
        } else {
            o->oCloudBlowing = o->oTimer = 0;
            o->o104 = 0;
        }
    } else {
        notstatic_approach_f32_ptr(&o->header.gfx.scale[0], 5.0f, 0.2f);

        if (obj->oAction == 3) {
            o->oCloudBlowing = TRUE;
            o->oCloudGrowSpeed = 0.24f;
        }

        //o->oCloudCenterX = o->oHomeX + 100.0f * coss(o->oCloudFwooshMovementRadius);
        //o->oPosZ = o->oHomeZ + 100.0f * sins(o->oCloudFwooshMovementRadius);
        o->oCloudCenterY = o->oHomeY;
    }

    cur_obj_scale(o->header.gfx.scale[0]);
}

/**
 * Main update function for bhvCloud. This controls the cloud's movement, when it
 * unloads, and when fwoosh blows wind.
 */
static void mg_fwoosh_act_main(void) {
    s16 localOffsetPhase;
    f32 localOffset;

    localOffsetPhase = 0x800 * gGlobalTimer;

    mg_fwoosh_update();

    localOffset = 2 * coss(localOffsetPhase) * o->header.gfx.scale[0];

    o->oPosX = o->oCloudCenterX + localOffset;
    o->oPosY = o->oCloudCenterY + localOffset + 12.0f * o->header.gfx.scale[0];
}


void bhv_mg_fwoosh_update(void) {
    switch (o->oAction) {
        case CLOUD_ACT_SPAWN_PARTS:
            mg_fwoosh_spawn_parts();
            break;
        case CLOUD_ACT_MAIN:
            mg_fwoosh_act_main();
            break;
    }
}

//FWOOSH END

void bhv_body_lakitu_init(void) {
    o->oGraphYOffset = -22.0f;
}


void bhv_body_lakitu_loop(void) {
    switch (o->oAction) {
        case 0:
            if(o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 1;
                play_toads_jingle();
            }
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x640);
            if (Set_NPC_Dialog(o->oBehParams2ndByte)) {
                o->oAction = 0;
            }
            break;
    }
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1C0);
    o->oInteractStatus = 0;
}


void bhv_fade_cloud_init(void) {
    o->oBehParams2ndByte = random_u16() & 0x3;
    if (o->oBehParams2ndByte == 3) {
        o->oBehParams2ndByte = 0;
    }
}


void bhv_fade_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 20)
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x6);
            if (o->oOpacity == 0) {
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->oTimer > 45) {
                 o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x8);
            }
            if (o->oOpacity == 255) {
                o->oAction = 0;
            }
            break;
    }
    if (o->oOpacity > 20) {
        load_object_collision_model();
    }
}







void bhv_rain_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                if (o->oTimer > 10) {
                    o->oAction = 1;
                }
                o->oPosY = approach_f32(o->oPosY, o->oHomeY - 30.0f, 4.0f, 4.0f);
                o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.88f, 0.02f, 0.02f);
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            if (o->oPosY - (o->oHomeY + 1000.0f) > -200.0f) {
                o->oFloatF4 = approach_f32(o->oFloatF4, 8.0f, 4.0f, 4.0f);
            } else {
                o->oFloatF4 = approach_f32(o->oFloatF4, 30.0f, 3.0f, 3.0f);
            }
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 1000.0f, o->oFloatF4, o->oFloatF4);

            if (o->oPosY == o->oHomeY + 1000.0f) {
                if (o->oTimer > 30 && gMarioObject->platform != o) {
                    o->oAction = 2;
                    o->oFloatF4 = 0;
                }
                o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 1.0f, 0.02f, 0.02f);
            } else {
                o->oTimer = 0;
            }
            break;
        case 2:
            if (o->oPosY - o->oHomeY < 200.0f) {
                o->oFloatF4 = approach_f32(o->oFloatF4, 8.0f, 4.0f, 4.0f);
            } else {
                o->oFloatF4 = approach_f32(o->oFloatF4, 30.0f, 3.0f, 3.0f);
            }
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, o->oFloatF4, o->oFloatF4);
            if (o->oPosY == o->oHomeY) {
                o->oAction = 0;
                o->oFloatF4 = 0;
            }
            break;
    }
}



void bhv_cloud_rainbow_loop(void) {
    switch (o->oAction) {
        case 0:
            o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 100.0f, 1.5f, 1.5f);
            if (o->header.gfx.scale[2] > 99.0f) {
                o->header.gfx.scale[2] = 100.0f;
                o->oAction = 1;
                o->oForwardVel = 15.0f;
            }
            break;
        case 1:
            cur_obj_move_using_fvel_and_gravity();
            if (o->oTimer > 99) {
                o->oAction = 2;
                o->oForwardVel = 30.0f;
            }
            break;
        case 2:
            cur_obj_move_using_fvel_and_gravity();
            o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 0.0f, 1.5f, 1.5f);
            if (o->header.gfx.scale[2] == 0) {
                o->activeFlags = 0;
            }
            break;
    }
}

void bhv_rainbow_cloud_init(void) {
    obj_set_hitbox(o, &sRainbowCloudHitbox);
}


void bhv_rainbow_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 2000.0f && absf(o->oPosY - gMarioState->pos[1]) < 1500.0f) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(0);
            }
            break;
        case 1:
            if (o->header.gfx.animInfo.animFrame == 16) {
                o->oAnimState = 1;
                o->oObjF4 = spawn_object(o, MODEL_CLOUD_RAINBOW, bhvCloudRainbow);
                o->oObjF4->oPosY -= 70.0f;
            } else if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 0;
                o->oAnimState = 0;
                cur_obj_init_animation_with_sound(1);
            }
            break;
    }
    o->oInteractStatus = 0;
}




void bhv_stretch_cloud_init(void) {  
    o->oFloatF4 = 1.0f;
}


void bhv_stretch_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 2.5f, 0.15f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->header.gfx.scale[0] - 2.5f < -0.1f) {
                o->oTimer = 0;
            }
            if (o->oTimer > 55) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 1.0f, 0.15f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->header.gfx.scale[0] - 1.0f > 0.1f) {
                o->oTimer = 0;
            }
            if (o->oTimer > 55) {
                o->oAction = 0;
            }
            break;
    }
}




void bhv_bounce_cloud_init(void) {  
    o->oFloatF4 = 1.0f;
}


void bhv_bounce_cloud_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m->marioObj->header.gfx.cameraToObject);
                m->pos[1] = m->floorHeight + 20.0f;
                m->vel[1] = 80.0f;
                m->flags & MARIO_UNKNOWN_08;
                reset_mario_pitch(m);
                play_sound(SOUND_MARIO_TWIRL_BOUNCE, m->marioObj->header.gfx.cameraToObject);
                drop_and_set_mario_action(m, ACT_TWIRLING, 0);
                o->oAction = 1;
            }
            o->oFC += 0x400;
            o->oPosY = o->oHomeY + (20.0f * sins(o->oFC));
            o->oFaceAngleYaw += 0xC0;
            break;
        case 1:
            o->oFloatF4 -= 0.15f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.1f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 0.6f) {
                o->oFloatF4 = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatF4 += 0.18f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.07f, 0.07f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 >= 1.4f) {
                o->oFloatF4 = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF4 -= 0.08f;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.0f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 1.0f) {
                o->header.gfx.scale[0] = (o->header.gfx.scale[2] = 1.0f);
                o->oFloatF4 = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatF4;
            break;
    }
}