
extern u8 sGoombaAttackHandlers[][6];
extern struct ModeTransitionInfo sModeInfo;
extern s16 sInvulnerable;

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

struct ObjectHitbox sLightningBoltHitbox = {
    /* interactType: */ INTERACT_DAMAGE,
    /* downOffset: */ 125,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 150,
    /* height: */ 125,
    /* hurtboxRadius: */ 150,
    /* hurtboxHeight: */ 125,
};


static struct ObjectHitbox sLightningHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 200,
    /* height:            */ 800,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sComitCoinHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 150,
    /* height: */ 64,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

s8 gComitCam = 0;
Vec3f gComitCamPos[2] = {
    {0, 0, 0},
    {0, 0, 0},
};

struct FwooshMG
{
    s16 timeCode;
    s16 type;
};

#define MINIGAME_SECONDS 120
#define MINIGAME_GOAL 80

struct FwooshMG sMGSpawnersRow1[] = {
    {0, 0,},
    {60, 0,},
    {120, 0,},
    {200, 0,},
    {230, 0,},
    {260, 0,},
    {290, 0,},
    {350, 0,},

    {480, 0,},
    {510, 0,},
    {540, 0,},
    {600, 0,},
    {630, 0,},

    {700, 0,},
    {730, 0,},
    {760, 0,},

    {850, 0,},
    {880, 0,},
    {910, 0,},

    {1000, 0,},
    {1100, 0,},
    {1190, 0,},
    {1280, 0,},
    {1370, 0,},
    {1460, 0,},
    {1550, 0,},
    {1580, 1,},
    {1640, 0,},
    {1730, 0,},
    {1820, 0,},
    {1850, 1,},
    {1880, 0,},
    {1940, 0,},
    {1970, 1,},
    {2000, 0,},
    {2060, 0,},
    {2090, 1,},
    {2110, 1,},
    {2120, 0,},
    {2180, 0,},
    {2240, 0,},
    {2270, 1,},
    {2300, 0,},
    {2360, 0,},
    {2420, 0,},
    {2440, 1,},
    {2480, 0,},
    {2540, 0,},

    //LAST GOOMBA AT 2600
    {2600, 0,},
    {-1, 0,},
};


struct FwooshMG sMGSpawnersRow2[] = {
    {390, 1,},
    {440, 1,},
    {550, 1,},
    {580, 1,},
    {730, 1,},
    {750, 0,},

    {800, 0,},
    {860, 0,},
    {920, 0,},

    {1000, 0,},

    {1150, 1,},
    {1180, 0,},
    {1350, 1,},
    {1400, 1,},
    {1450, 1,},
    {1600, 1,},
    {1630, 1,},
    {1750, 1,},
    {1800, 1,},
    {2000, 1,},
    {2015, 0,},
    {2030, 1,},
    {2060, 1,},
    {2075, 0,},
    {2100, 1,},
    {2105, 0,},
    {2200, 1,},
    {2400, 1,},
    {2410, 0,},
    {2440, 0,},
    {2470, 0,},
    {2500, 0,},
    {2700, 1,},
    {2900, 1,},
    {2950, 1,},
    //LAST KOOPA AT 3000
    {3000, 1,},
    {-1, 0,},
};

struct FwooshMG sMGSpawnersRow3[] = {
    //introduce 3rd row
    {1350, 1,},
    {1380, 0,},
    {1440, 0,},
    {1500, 0,},
    {1650, 1,},

    {1800, 1,},
    {1900, 0,},
    {1930, 0,},
    {2000, 0,},
    {2040, 1,},
    {2080, 1,},
    {2100, 1,},

    //introduce big goomba
    {2250, 2,},
    {2475, 2,},
    {2700, 2,},
    {2925, 2,},

    //LAST BIG GOOMBA AT 3150
    {3150, 2,},
    {-1, 0,},
};

Gfx *geo_comit_set_brightness(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectBrightness;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectBrightness = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);

        gDPSetEnvColor(dlHead++, objectBrightness, objectBrightness, objectBrightness, 255);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}



void CL_set_camera_pos(Vec3f pos, Vec3f foc) {
    struct MarioState *marioStates = &gMarioStates[0];
    struct LinearTransitionPoint *start = &sModeInfo.transitionStart;
    struct LinearTransitionPoint *end = &sModeInfo.transitionEnd;

    vec3f_copy(gLakituState.curPos, pos);
    vec3f_copy(gLakituState.curFocus, foc);
    vec3f_copy(gLakituState.goalPos, pos);
    vec3f_copy(gLakituState.goalFocus, foc);
    vec3f_copy(start->focus, foc);
    vec3f_copy(start->pos, pos);
    vec3f_copy(end->focus, foc);
    vec3f_copy(end->pos, pos);
}


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




void bhv_floor_door_button_loop(void) {
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
                o->oAction = 2;
            }
            break;
    }
}




void bhv_floor_door_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvFloorDoorButton);
            if (obj == NULL || obj->oAction == 2) {
                o->oAction = 1;
                vec3f_copy(gComitCamPos[1], &o->oPosX);
                vec3f_set(gComitCamPos[0], o->oPosX, o->oHomeY + 500.0f, o->oPosZ + 800.0f);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gComitCam = 1;
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 50.0f, 2.5f, 2.5f);
            if (o->oPosY == o->oHomeY - 50.0f) {
                o->oAction = 2;
            }
            break;
        case 2:
            set_mario_npc_dialog(1);
            gComitCam = 1;
            if (o->oTimer > 5) {
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
                o->oPosZ = approach_f32(o->oPosZ, o->oHomeZ - 600.0f, 12.0f, 12.0f);
                if (o->oPosZ == o->oHomeZ - 600.0f) {
                    play_puzzle_jingle();
                    o->activeFlags = 0;
                    set_mario_npc_dialog(0);
                }
            }
            break;
    }
}







//BOSS CODE START
void bhv_comit_coin_init(void) {
    cur_obj_set_behavior(bhvYellowCoin);
    obj_set_hitbox(o, &sComitCoinHitbox);
    bhv_init_room();
    if (o->oFloorHeight < FLOOR_LOWER_LIMIT_MISC)
        obj_mark_for_deletion(o);
}

void bhv_lightning_button_loop(void) {
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


void center_platform_restrict_mario(void) {
    f32 dist = o->oDistanceToMario - 2200.0f;
    if (dist > 0) {
        gMarioState->pos[0] -= dist * sins(o->oAngleToMario);
        gMarioState->pos[2] -= dist * coss(o->oAngleToMario);
    }
}


void bhv_center_platform_loop(void) {
    struct Object *obj;
    s32 i;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 2200.0f)
                o->oAction = 4;
            break;
        case 1:
            center_platform_restrict_mario();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 20, 2);
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 9000.0f, 15.0f, 15.0f);
            if (o->oPosY == o->oHomeY + 9000.0f) {
                cur_obj_shake_screen(0);
                o->oAction = 2;
                o->oF4 = 0;

                obj = cur_obj_nearest_object_with_behavior(bhvYellowCoin);
                while (obj != NULL) {
                    obj->activeFlags = 0;
                    obj = cur_obj_nearest_object_with_behavior(bhvYellowCoin);
                }
            }
            break;
        case 2:
            o->oOpacity = 0;
            obj = cur_obj_nearest_object_with_behavior(bhvLightningCloud);
            if (obj != NULL && obj->os16104 == 4) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 20, 2);
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 60.0f, 60.0f);

            gMarioState->pos[0] = approach_f32(gMarioState->pos[0], o->oPosX, 50.0f, 50.0f);
            gMarioState->pos[1] = approach_f32(gMarioState->pos[1], o->oPosY + 67.0f, 50.0f, 50.0f);
            gMarioState->pos[2] = approach_f32(gMarioState->pos[2], o->oPosZ, 50.0f, 50.0f);

            gComitCam = 1;
            vec3f_set(gComitCamPos[0], 0.0f, gMarioState->pos[1] + 600.0f, gMarioState->pos[2] + 1500.0f);
            vec3f_copy(gComitCamPos[1], gMarioState->pos);


            if (o->oPosY == o->oHomeY) {
                cur_obj_shake_screen(0);
                o->oAction = 0;
                o->oF4 = 0;
            }
            break;
        case 4:
            o->oOpacity = 0;
            center_platform_restrict_mario();
            if (o->oF4 == 1) {
                o->oAction = 1;

                for (i = 0; i < 25; i++) {
                    obj = spawn_object(o, MODEL_YELLOW_COIN, bhvComitCoin);

                    obj->oPosX = (random_float() - 0.5f) * 3000.0f;
                    obj->oPosZ = (random_float() - 0.5f) * 3000.0f;
                    obj->oPosY = 2000.0f + (random_float() * 6000.0f);
                }
            }
            break;
    }
}



void bhv_lightning_blast_loop(void) {
    u32 actionArg;
    o->oPosY = o->parentObj->oPosY - 210.0f;
    o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 80.0f, 5.0f, 5.0f);
    if (o->oBehParams2ndByte == 0) {
        o->oPosX = o->parentObj->oPosX;
        if (absf(o->oPosX - gMarioState->pos[0]) < 50.0f && absf(o->oPosY - (gMarioState->pos[1] + 50.0f)) < 80.0f
            && o->oTimer > 6 && !sInvulnerable) {
            actionArg = (gMarioState->action & ACT_FLAG_AIR) == 0;
            set_mario_action(gMarioState, ACT_SHOCKED, actionArg);
            gMarioState->hurtCounter += 8;
            o->oTimer = 0;
        }
    } else {
        o->oPosZ = o->parentObj->oPosZ;
        if (absf(o->oPosZ - gMarioState->pos[2]) < 50.0f && absf(o->oPosY - (gMarioState->pos[1] + 50.0f)) < 80.0f
            && o->oTimer > 6 && !sInvulnerable) {
            actionArg = (gMarioState->action & ACT_FLAG_AIR) == 0;
            set_mario_action(gMarioState, ACT_SHOCKED, actionArg);
            gMarioState->hurtCounter += 8;
            o->oTimer = 0;
        }
        if (o->parentObj->o110 != 2) {
            o->parentObj->oObjF4 = NULL;
            o->activeFlags = 0;
        }
    }
}


void bhv_lightning_strike_init(void) {
    o->oOpacity = 0;
    obj_set_hitbox(o, &sLightningHitbox);
}

void bhv_lightning_strike_loop(void) {
    u32 actionArg, chance;
    struct Object *obj;
    if (o->oInteractStatus) {
        actionArg = (gMarioState->action & ACT_FLAG_AIR) == 0;
        set_mario_action(gMarioState, ACT_SHOCKED, actionArg);
        gMarioState->hurtCounter += 8;
    }
    o->oInteractStatus = 0;
    switch (o->oAction) {
        case 0:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 220, 30);
            if (o->oF4) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 10) {
                o->oAction = 2;
                o->oOpacity = 255;
                cur_obj_shake_screen(0);
                cur_obj_play_sound_1(SOUND_OBJ_THWOMP);
                cur_obj_play_sound_1(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                chance = o->oNumLootCoins * 0xC00;
                if (random_u16() < chance) {
                    obj_spawn_loot_yellow_coins(o, 1, 35.0f);
                }
            }
            break;
        case 2:
            cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
            cur_obj_become_tangible();
            if (o->oTimer > 20) {
                o->oAction = 3;
            }
            break;
        case 3:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 200, 60);
            if (o->oOpacity == 200) {
                o->oAction = 0;
                o->oF4 = 0;
            }
            break;
    }
    obj = cur_obj_nearest_object_with_behavior(bhvCenterPlatform);
    o->oPosY = obj->oPosY + 67.0f;
    o->oPosX = o->parentObj->oPosX;
    o->oPosZ = o->parentObj->oPosZ;

    if (obj_has_behavior(o->parentObj, bhvBonusLightningCloud) && o->parentObj->o110 != 1) {
        o->parentObj->oObjF4 = NULL;
        o->activeFlags = 0;
    }
}



void bhv_lightning_bolt_init(void) {
    obj_set_hitbox(o, &sLightningBoltHitbox);    
    o->oForwardVel = 60.0f;
}

void bhv_lightning_bolt_loop(void) {
    u32 actionArg;
    cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
    if (o->oTimer < 15) {
        if (absi(o->oMoveAngleYaw - o->oAngleToMario) < 0x1000) {
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x200);
        }
    }
    cur_obj_move_using_fvel_and_gravity();
    if (o->oInteractStatus) {
        actionArg = (gMarioState->action & ACT_FLAG_AIR) == 0;
        set_mario_action(gMarioState, ACT_SHOCKED, actionArg);
        gMarioState->hurtCounter += 8;
    }
    if (o->oInteractStatus || o->oTimer > 120 || (o->parentObj->os16104 > 3 || o->parentObj->o110 > 3)) {
        spawn_mist_particles();
        o->parentObj->oObjF4 = NULL;
        o->activeFlags = 0;
    }
}


void lightning_cloud_bolt_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->oPosX = approach_f32(o->oPosX, 0, 100.0f, 100.0f);
            o->oPosZ = approach_f32(o->oPosZ, gMarioState->pos[2] - 4500.0f, 100.0f, 100.0f);
            if (o->oPosX == 0 && o->oPosZ == gMarioState->pos[2] - 4500.0f) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(1);
            }
            break;
        case 1:
            if (o->header.gfx.animInfo.animFrame == 16) {
                o->oAnimState = 1;
                o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_BOLT, bhvLightningBolt);
                o->oObjF4->oPosY -= 170.0f;
                cur_obj_play_sound_1(SOUND_OBJ_MONTY_MOLE_ATTACK);
            } else if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 2;
                o->oAnimState = 0;
                cur_obj_init_animation_with_sound(2);
            }
            break;
        case 2:
            if (o->oDistanceToMario < 15000.0f && o->oTimer > 10) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(1);
            }
            break;
    }
    if (o->oAction) {
        o->os16102 += 0xC0;
        o->oPosX = sins(o->os16102) * 1500.0f;
        o->oPosZ = gMarioState->pos[2] - 4500.0f;
        o->oMoveAngleYaw = o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0x400);
    }
    obj = cur_obj_nearest_object_with_behavior(bhvLightningButton);
    if (obj != NULL && obj->oAction == 3) {
        cur_obj_init_animation_with_sound(2);
        o->oAction = 0;
        o->os16102 = 0;
        o->os16104 = 4;

        if (o->os16106 == 0) {
            spawn_object(o, MODEL_LIGHTNING_CLOUD, bhvBonusLightningCloud);
            o->os16106 = 1;
        } else if (o->os16106 == 1) {
            o->os16106 = 2;
            obj = spawn_object(o, MODEL_LIGHTNING_CLOUD, bhvBonusLightningCloud);
            obj->oBehParams2ndByte = 1;
        } else {
            o->os16106 = 3;
            spawn_default_star(0.0f, 9700.0f, 0.0f);
            o->os16104 = 5;
        }
    }
}


void lightning_cloud_strike_loop(void) {
    f32 dist, dist2;
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, 1000.0f, 10.0f, 10.0f);
            if (o->oDistanceToMario < 15000.0f && o->oPosY == 1000.0f) {
                o->oAction = 1;
                //cur_obj_init_animation_with_sound(0);

                /* RANDOM LOCATION
                o->os16100 = cur_obj_angle_to_home() + (s32)((random_float() - 0.5f) * 0x1000);
                o->oFloatF8 = sins(o->os16100) * 1000.0f;
                o->oFloatFC = coss(o->os16100) * 1000.0f;*/

                //o->os16100 = o->oAngleToMario;// + (s32)((random_float() - 0.5f) * 0x400);
                if (lateral_dist_between_objects(o, gMarioObject) > 500.0f) {
                    o->oFloatF8 = gMarioState->pos[0] + ((random_float() - 0.5f) * 50.0f);
                    o->oFloatFC = gMarioState->pos[2] + ((random_float() - 0.5f) * 50.0f);
                } else {
                    o->oFloatF8 = o->oPosX - (gMarioState->pos[0] - o->oPosX);
                    o->oFloatFC = o->oPosZ - (gMarioState->pos[2] - o->oPosZ);
                }

                //dist2 += ((random_float() - 0.5f) * 50.0f);
                //dist += ((random_float() - 0.5f) * 50.0f);
                //o->oFloatF8 = sins(o->os16100) * dist;
                /*if (o->oFloatF8 + o->oPosX > 2500.0f) {
                    o->oFloatF8 = 2500.0f - o->oPosX;
                } else if (o->oFloatF8 + o->oPosX < -2500.0f) {
                    o->oFloatF8 = -2500.0f - o->oPosX;
                }*/
                //o->oFloatFC = coss(o->os16100) * dist2;
                /*if (o->oFloatFC + o->oPosZ > 2500.0f) {
                    o->oFloatFC = 2500.0f - o->oPosZ;
                }  else if (o->oFloatFC + o->oPosZ < -2500.0f) {
                    o->oFloatFC = -2500.0f - o->oPosZ;
                }*/

                o->oMoveAngleYaw = o->oFaceAngleYaw = atan2s(o->oFloatFC, o->oFloatF8);
                if (o->oObjF4 == NULL) {
                    o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_STRIKE, bhvLightningStrike);
                }
                //o->oForwardVel = 60.0f;
                //cur_obj_compute_vel_xz();
            }
            break;
        case 1:
            //dist = 60.0f * (o->oFloatF8 / o->oFloatFC);
            //dist2 = 60.0f * (o->oFloatFC / o->oFloatF8);
            o->oPosX = approach_f32(o->oPosX, o->oFloatF8, 60.0f, 60.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oFloatFC, 60.0f, 60.0f);

            if (o->oPosX == o->oFloatF8 && o->oPosZ == o->oFloatFC) {
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->oTimer == 0) {
                o->oAnimState = 1;
                if (o->oObjF4 != NULL) {
                    o->oObjF4->oF4 = 1;
                }
            } else {
                if (o->oObjF4->oF4 == 0) {
                    o->oAction = 0;
                    o->oAnimState = 0;
                    o->os16108++;
                    if (o->os16108 > 5) {
                        o->os16104 = 2;
                        o->os16108 = 0;
                        o->oObjF4->activeFlags = 0;
                        o->oObjF4 = NULL;
                    }
                }
            }
            break;
    }
}

void lightning_cloud_blast_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosX = approach_f32(o->oPosX, 0, 100.0f, 100.0f);
            o->oPosZ = approach_f32(o->oPosZ, -3500.0f, 100.0f, 100.0f);
            o->oPosY = approach_f32(o->oPosY, 320.0f, 30.0f, 30.0f);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0, 0x400);
            if (o->oTimer > 90) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(1);
                o->oObj10C = cur_obj_nearest_object_with_behavior(bhvCenterPlatform);
                if (o->oObj10C == NULL) {
                    o->activeFlags = 0;
                    return;
                }
                o->oObj10C->oF4 = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oObj10C->oPosY + 320.0f, 30.0f, 30.0f);
            if (o->header.gfx.animInfo.animFrame == 16) {
                o->oAnimState = 1;
                o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_BLAST, bhvLightningBlast);
                o->oObjF4->oFaceAngleYaw += 0x8000;
                o->oObjF4->oPosY -= 210.0f;
                cur_obj_play_sound_1(SOUND_OBJ2_BOWSER_ROAR);
            } else if (o->header.gfx.animInfo.animFrame > 18) {
                o->os16102 += 0x100;
                o->oPosX = sins(o->os16102) * 3000.0f;
                if (o->oObj10C->oF4 == 0) {
                    o->oAction = 0;
                    o->os16104 = 3;
                    o->oAnimState = 0;
                    o->oObjF4->activeFlags = 0;
                    o->oObjF4 = NULL;
                    o->os16102 = 0;
                    cur_obj_init_animation_with_sound(2);
                }
            }
            break;
    }
}

void bhv_lightning_cloud_loop(void) {
    struct Object *obj;
    f32 dist;
    switch (o->os16104) {
        case 0:
            if (o->oDistanceToMario < 1500.0f) {
                o->os16108 = 0;
                o->os16104 = 1;
                o->oTimer = 0;
            }
            break;
        case 1:
            lightning_cloud_strike_loop();
            break;
        case 2:
            lightning_cloud_blast_loop();
            break;
        case 3:
            lightning_cloud_bolt_loop();
            break;
        case 4:
            obj = cur_obj_nearest_object_with_behavior(bhvCenterPlatform);
            if (obj != NULL) {
                o->oPosY = approach_f32(o->oPosY, obj->oHomeY + 400.0f, 75.0f, 75.0f);
                o->oPosX = approach_f32(o->oPosX, 0, 20.0f, 20.0f);
                o->oPosZ = approach_f32(o->oPosZ, -1000.0f, 20.0f, 20.0f);
            }
            if (o->oTimer > 120 && obj->oAction == 4) {
                o->os16104 = 1;
            }
            break;
        case 5:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0, 0x400);
            o->oPosX = approach_f32(o->oPosX, 0, 60.0f, 60.0f);
            o->oPosY = approach_f32(o->oPosY, 9450.0f, 60.0f, 60.0f);
            o->oPosZ = approach_f32(o->oPosZ, -1000.0f, 60.0f, 60.0f);

            dist = approach_f32(o->header.gfx.scale[0], 0.33f, 0.005f, 0.005f);
            cur_obj_scale(dist);
            if (o->oPosX == 0 && o->oPosY == 9450.0f && o->oPosZ == -1000.0f && dist == 0.33f) {
                o->oMoveAngleYaw = o->oFaceAngleYaw = 0;
                obj = spawn_object(o, MODEL_RAINBOW_CLOUD, bhvRainbowCloud);
                o->activeFlags = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}


void bonus_lightning_cloud_bolt_loop(void) {
    struct Object *obj;
    f32 dist;
    switch (o->oAction) {
        case 0:
            if (o->oBehParams2ndByte) {
                dist = 1500.0f;
            } else {
                dist = -1500.0f;
            }
            o->oPosX = approach_f32(o->oPosX, dist, 100.0f, 100.0f);
            o->oPosY = approach_f32(o->oPosY, 9250.0f, 100.0f, 100.0f);
            o->oPosZ = approach_f32(o->oPosZ, gMarioState->pos[2] - 4500.0f, 100.0f, 100.0f);
            if (o->oPosX == dist && o->oPosZ == gMarioState->pos[2] - 4500.0f && o->oPosY == 9250.0f) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(1);
            }
            break;
        case 1:
            if (o->header.gfx.animInfo.animFrame == 16) {
                o->oAnimState = 1;
                o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_BOLT, bhvLightningBolt);
                o->oObjF4->oPosY -= 70.0f;
            } else if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 2;
                o->oAnimState = 0;
                cur_obj_init_animation_with_sound(2);
            }
            break;
        case 2:
            if (o->oDistanceToMario < 15000.0f && o->oTimer > 10) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(1);
            }
            break;
    }
    if (o->oAction) {
        o->os16102 += 0xC0;
        o->oPosZ = (gMarioState->pos[2] - 4500.0f) + sins(o->os16102) * 1500.0f;
        //o->oPosZ = gMarioState->pos[2] - 4500.0f;
        o->oMoveAngleYaw = o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0x400);
    }
    obj = cur_obj_nearest_object_with_behavior(bhvLightningButton);
    if (obj != NULL && obj->oAction == 3) {
        cur_obj_init_animation_with_sound(2);
        o->oAction = 0;
        o->os16102 = 0;
        o->o110 = 4;
    }
}


void bonus_lightning_cloud_strike_loop(void) {
    f32 dist, dist2;
    struct Object *obj;
    obj = cur_obj_nearest_object_with_behavior(bhvCenterPlatform);
    o->oPosY = obj->oPosY + 1067.0f;
    switch (o->oAction) {
        case 0:
            o->oAction = 1;
            //cur_obj_init_animation_with_sound(0);

            /* RANDOM LOCATION
            o->os16100 = cur_obj_angle_to_home() + (s32)((random_float() - 0.5f) * 0x1000);
            o->oFloatF8 = sins(o->os16100) * 1000.0f;
            if (o->oFloatF8 + o->oPosX > 1000.0f) {
                o->oFloatF8 = 1000.0f - o->oPosX;
            }
            o->oFloatFC = coss(o->os16100) * 1000.0f;
            if (o->oFloatFC + o->oPosZ > 1000.0f) {
                o->oFloatFC = 1000.0f - o->oPosZ;
            }
            o->oMoveAngleYaw = o->oFaceAngleYaw = atan2s(o->oFloatFC, o->oFloatF8);*/

            //o->os16100 = o->oAngleToMario + (s32)((random_float() - 0.5f) * 0x200);
            //dist = o->oDistanceToMario;
            if (lateral_dist_between_objects(o, gMarioObject) > 500.0f) {
                o->oFloatF8 = gMarioState->pos[0] + ((random_float() - 0.5f) * 50.0f);
                o->oFloatFC = gMarioState->pos[2] + ((random_float() - 0.5f) * 50.0f);
            } else {
                o->oFloatF8 = -gMarioState->pos[0];
                o->oFloatFC = -gMarioState->pos[2];
            }


            //dist2 = dist + ((random_float() - 0.5f) * 50.0f);
            //dist += ((random_float() - 0.5f) * 50.0f);
            //o->oFloatF8 = sins(o->os16100) * dist;
            /*if (o->oFloatF8 + o->oPosX > 2500.0f) {
                o->oFloatF8 = 2500.0f - o->oPosX;
            } else if (o->oFloatF8 + o->oPosX < -2500.0f) {
                o->oFloatF8 = -2500.0f - o->oPosX;
            }*/
            //o->oFloatFC = coss(o->os16100) * dist2;
            /*if (o->oFloatFC + o->oPosZ > 2500.0f) {
                o->oFloatFC = 2500.0f - o->oPosZ;
            }  else if (o->oFloatFC + o->oPosZ < -2500.0f) {
                o->oFloatFC = -2500.0f - o->oPosZ;
            }*/

            o->oMoveAngleYaw = o->oFaceAngleYaw = atan2s(o->oFloatFC, o->oFloatF8);
            if (o->oObjF4 == NULL) {
                o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_STRIKE, bhvLightningStrike);
            }
            break;
        case 1:
            o->oPosX = approach_f32(o->oPosX, o->oFloatF8, 60.0f, 60.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oFloatFC, 60.0f, 60.0f);

            if (o->oPosX == o->oFloatF8 && o->oPosZ == o->oFloatFC) {
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->oTimer == 0) {
                o->oAnimState = 1;
                if (o->oObjF4 != NULL) {
                    o->oObjF4->oF4 = 1;
                }
            } else {
                if (o->oObjF4->oF4 == 0) {
                    o->oAction = 0;
                    o->oAnimState = 0;
                }
            }
            break;
    }
}

void bonus_lightning_cloud_blast_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosX = approach_f32(o->oPosX, 3500.0f, 100.0f, 100.0f);
            o->oPosZ = approach_f32(o->oPosZ, 0.0f, 100.0f, 100.0f);
            o->oPosY = approach_f32(o->oPosY, 320.0f, 30.0f, 30.0f);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0xC000, 0x800);
            if (o->oTimer > 90) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(1);
                o->oObj10C = cur_obj_nearest_object_with_behavior(bhvCenterPlatform);
                if (o->oObj10C == NULL) {
                    o->activeFlags = 0;
                    return;
                }
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oObj10C->oPosY + 320.0f, 30.0f, 30.0f);
            if (o->header.gfx.animInfo.animFrame == 16) {
                o->oAnimState = 1;
                o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_BLAST, bhvLightningBlast);
                o->oObjF4->oBehParams2ndByte = 1;
                o->oObjF4->oFaceAngleYaw = 0x4000;
                o->oObjF4->oPosY -= 210.0f;
            } else if (o->header.gfx.animInfo.animFrame > 18) {
                o->os16102 += 0xC0;
                o->oPosZ = sins(o->os16102) * 3000.0f;
                if (o->oObj10C->oF4 == 0) {
                    o->oAction = 0;
                    o->os16104 = 3;
                    o->oAnimState = 0;
                    o->oObjF4->activeFlags = 0;
                    o->oObjF4 = NULL;
                    o->os16102 = 0;
                    cur_obj_init_animation_with_sound(2);
                }
            }
            break;
    }
}


void bhv_bonus_lightning_cloud_init(void) {
    f32 xpos;
    obj_set_hitbox(o, &sRainbowCloudHitbox);
    if (o->oBehParams2ndByte) {
        xpos = 1500.0f;
    } else {
        xpos = -1500.0f;
    }
    vec3f_set(&o->oPosX, xpos, 800.0f, -1500.0f);
    o->oFaceAngleYaw = o->oMoveAngleYaw = 0;
}

void bonus_lightning_cloud_get_action(s32 type) {
    switch (type) {
        case 0:
            if (o->parentObj->os16104 == 1 || o->parentObj->os16104 == 2) {
                if (o->o110 != 1)
                    o->oAction = 0;
                o->o110 = 1;
            } else if (o->parentObj->os16104 == 3) {
                if (o->o110 != 3)
                    o->oAction = 0;
                o->o110 = 3;
            }
            break;
        case 1:
            if (o->parentObj->os16104 == 1) {
                if (o->o110 != 1)
                    o->oAction = 0;
                o->o110 = 1;
            } else if (o->parentObj->os16104 == 2) {
                if (o->o110 != 2)
                    o->oAction = 0;
                o->o110 = 2;
            } else if (o->parentObj->os16104 == 3) {
                if (o->o110 != 3)
                    o->oAction = 0;
                o->o110 = 3;
            }
            break;
    }
    if (o->parentObj->activeFlags == 0 || o->parentObj->os16104 == 5) {
        o->o110 = 5;
    }

}

void bhv_bonus_lightning_cloud_loop(void) {
    struct Object *obj;
    f32 xPos, dist;
    bonus_lightning_cloud_get_action(o->oBehParams2ndByte);
    switch (o->o110) {
        case 0:
            break;
        case 1:
            bonus_lightning_cloud_strike_loop();
            break;
        case 2:
            bonus_lightning_cloud_blast_loop();
            break;
        case 3:
            bonus_lightning_cloud_bolt_loop();
            break;
        case 4:
            obj = cur_obj_nearest_object_with_behavior(bhvCenterPlatform);
            if (obj != NULL) {
                o->oPosY = approach_f32(o->oPosY, obj->oHomeY + 400.0f, 75.0f, 75.0f);
                o->oPosX = approach_f32(o->oPosX, 500, 20.0f, 20.0f);
                o->oPosZ = approach_f32(o->oPosZ, 0.0f, 20.0f, 20.0f);
            }
            break;
        case 5:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0, 0x400);
            if (o->oBehParams2ndByte) {
                xPos = -400.0f;
            } else {
                xPos = 400.0f;
            }
            o->oPosX = approach_f32(o->oPosX, xPos, 60.0f, 60.0f);
            o->oPosY = approach_f32(o->oPosY, 9250.0f, 60.0f, 60.0f);
            o->oPosZ = approach_f32(o->oPosZ, -1000.0f, 60.0f, 60.0f);

            dist = approach_f32(o->header.gfx.scale[0], 0.33f, 0.005f, 0.005f);
            cur_obj_scale(dist);
            if (o->oPosX == xPos && o->oPosY == 9250.0f && o->oPosZ == -1000.0f && dist == 0.33f) {
                o->oMoveAngleYaw = o->oFaceAngleYaw = 0;
                obj = spawn_object(o, MODEL_RAINBOW_CLOUD, bhvRainbowCloud);
                o->activeFlags = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}


//BOSS CODE END













void bhv_mist_trigger_loop(void) {
    struct Object *hiddenStar;
    o->oF4 += 0x400;
    o->oGraphYOffset = 30.0f * sins(o->oF4);
    o->oFaceAngleYaw += 0xC0;
    if (obj_check_if_collided_with_object(o, gMarioObject) == 1) {
        hiddenStar = cur_obj_nearest_object_with_behavior(bhvHiddenStar);
        if (hiddenStar != NULL) {
            hiddenStar->oHiddenStarTriggerCounter++;
            if (hiddenStar->oHiddenStarTriggerCounter != 5) {
                spawn_orange_number(hiddenStar->oHiddenStarTriggerCounter, 0, 0, 0);
            }

            play_sound(SOUND_MENU_COLLECT_SECRET
                           + (((u8) hiddenStar->oHiddenStarTriggerCounter - 1) << 16),
                       gGlobalSoundSource);
        }

        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}












//FWOOSH START
static s8 sMGCloudPartHeights[] = { 11, 8, 12, 8, 9, 9 };

s32 sMGModelSpawnTable[] = {
    MODEL_LOWPOLY_GOOMBA, MODEL_LOWPOLY_KOOPA, MODEL_LOWPOLY_GOOMBA,
};

const BehaviorScript *sMGBhvSpawnTable[] = {
    bhvFwooshMGGoomba, bhvFwooshMGKoopa, bhvFwooshMGGoomba,
};

f32 sMGRowTable[] = {
    -14372.0f, -13922.0f, -13472.0f,
};


void bhv_fwooshmg_koopa_update(void) {
    struct Object *obj;
    o->oFaceAngleYaw = 0x4000;
    cur_obj_init_animation_with_sound(9);
    cur_obj_update_floor_and_walls();

    if (!(o->oMoveFlags & OBJ_MOVE_HIT_WALL)) {
        o->oPosX += 10.0f;
    }
    cur_obj_move_standard(-78);

    if (o->oFloorType == SURFACE_DEATH_PLANE && o->oPosY - o->oFloorHeight < 500.0f) {
        o->activeFlags = 0;
        obj = cur_obj_nearest_object_with_behavior(bhvFwooshMGHandler);
        if (obj == NULL)
            return;
        obj->os16F6 += 2;
        play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
    }
    if (o->oPosX > 15966.0f) {
        o->activeFlags = 0;
    }
}



void bhv_fwooshmg_goomba_update(void) {
    f32 animSpeed;
    struct Object *obj;
    o->oFaceAngleYaw = 0x4000;
    cur_obj_scale(o->oGoombaScale);
    obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
    cur_obj_update_floor_and_walls();

    o->oForwardVel = 0;
    animSpeed = 1.0f;
    cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

    if (!(o->oMoveFlags & OBJ_MOVE_HIT_WALL)) {
        o->oPosX += 5.0f;
        if (o->oBehParams2ndByte == 1) {
            o->oPosX += 5.0f;
        }
    }
    cur_obj_move_standard(-78);

    if (o->oFloorType == SURFACE_DEATH_PLANE && o->oPosY - o->oFloorHeight < 500.0f) {
        o->activeFlags = 0;
        obj = cur_obj_nearest_object_with_behavior(bhvFwooshMGHandler);
        if (obj == NULL)
            return;
        obj->os16F6++;
        if (o->oBehParams2ndByte == 1) {
            obj->os16F6 += 4;
        }
        play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
    }
    if (o->oPosX > 15966.0f) {
        o->activeFlags = 0;
    }
}


void bhv_fwooshmg_star_loop(void) {
    if (o->oF4 == 1) {
        spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
        o->activeFlags = 0;
    }
}


void fwooshmg_spawn_enemies(void) {
    struct Object *obj;
    while (sMGSpawnersRow1[o->os16F8].timeCode != -1 && sMGSpawnersRow1[o->os16F8].timeCode <= (MINIGAME_SECONDS*30 + 1) - o->os16F4) {
        obj = spawn_object(o, sMGModelSpawnTable[sMGSpawnersRow1[o->os16F8].type], sMGBhvSpawnTable[sMGSpawnersRow1[o->os16F8].type]);
        if (sMGSpawnersRow1[o->os16F8].type == 2) {
            obj->oBehParams2ndByte = 1;
        }
        vec3f_set(&obj->oPosX, 11366.0f, 8125.00f, sMGRowTable[0]);
        o->os16F8++;
    }


    while (sMGSpawnersRow2[o->os16FA].timeCode != -1 && sMGSpawnersRow2[o->os16FA].timeCode <= (MINIGAME_SECONDS*30 + 1) - o->os16F4) {
        obj = spawn_object(o, sMGModelSpawnTable[sMGSpawnersRow2[o->os16FA].type], sMGBhvSpawnTable[sMGSpawnersRow2[o->os16FA].type]);
        if (sMGSpawnersRow2[o->os16FA].type == 2) {
            obj->oBehParams2ndByte = 1;
        }
        vec3f_set(&obj->oPosX, 11366.0f, 8125.00f, sMGRowTable[1]);
        o->os16FA++;
    }

    
    while (sMGSpawnersRow3[o->os16FC].timeCode != -1 && sMGSpawnersRow3[o->os16FC].timeCode <= (MINIGAME_SECONDS*30 + 1) - o->os16F4) {
        obj = spawn_object(o, sMGModelSpawnTable[sMGSpawnersRow3[o->os16FC].type], sMGBhvSpawnTable[sMGSpawnersRow3[o->os16FC].type]);
        if (sMGSpawnersRow3[o->os16FC].type == 2) {
            obj->oBehParams2ndByte = 1;
        }
        vec3f_set(&obj->oPosX, 11366.0f, 8125.00f, sMGRowTable[2]);
        o->os16FC++;
    }
}


void bhv_fwooshmg_handler_init(void) {
    o->os16F4 = (MINIGAME_SECONDS*30 + 1);
}


void bhv_fwooshmg_handler_update(void) {
    struct Object *obj;
    Vec3f pos;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[2] < -11500.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (gMarioState->pos[2] > -11500.0f) {
                gMarioState->pos[2] = -11500.0f;
            }
            fwooshmg_spawn_enemies();
            
            gComitCam = 1;
            vec3f_copy(gComitCamPos[0], &o->oPosX);
            vec3f_set(gComitCamPos[1], o->oPosX, 8000.0f, o->oPosZ - 1800.0f);

            o->os16F4--;
            if (o->os16F4 > 10*30) {
                if (o->os16F4 % 30 == 0) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                }
                o->os16104 = 10;
                o->os16106 = 20;
            } else {
                if (o->os16F4 % 30 == 0 || o->os16F4 % 30 == 15) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                }
                o->o100 += 0x1000;
                o->os16104 = 10 + (sins(o->o100) * 2);
                o->os16106 = 20 + (coss(o->o100) * 2);
            }

            print_text_fmt_int(o->os16106, o->os16104, "TIME  %d", o->os16F4 / 30);
            print_text_fmt_int(20, 200, "POINTS %d", o->os16F6);
            print_text_fmt_int(20, 215, "GOAL %d", MINIGAME_GOAL);
            if (o->os16F4 <= 0) {
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->os16F6 >= MINIGAME_GOAL) {
                obj = cur_obj_nearest_object_with_behavior(bhvFwooshMGStar);
                if (obj != NULL) {
                    obj->oF4 = 1;
                }
            } else {
                gMarioState->health = 0xFF;
            }
            o->activeFlags = 0;
            break;
    }
}


void bhv_metal_crate_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvMinigameFwoosh);
    if (o->oObjF4 == NULL)
        o->activeFlags = 0;
}

void bhv_metal_crate_loop(void) {
    f32 posZ;
    o->oAction = o->oObjF4->o104;
    switch (o->oAction) {
        case 0:
            o->oFloatF8 = approach_f32(o->oFloatF8, 50.0f, 6.0f, 6.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oHomeZ, o->oFloatF8, o->oFloatF8);
            break;
        case 1:
            load_object_collision_model();
            o->oFloatF8 = approach_f32(o->oFloatF8, 100.0f, 10.0f, 10.0f);
            posZ = o->oPosZ;
            o->oPosZ = approach_f32_asymptotic(o->oPosZ, o->oHomeZ - 2000.0f, 0.05f);
            if (posZ - o->oPosZ < 60.0f) {
                o->oPosZ = posZ - 60.0f;
            }
            if (o->oPosZ < o->oHomeZ - 2000.0f) {
                o->oPosZ = o->oHomeZ - 2000.0f;
            }
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