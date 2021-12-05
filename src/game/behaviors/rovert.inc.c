//hey sussy baka >:3
#include "src/game/game_init.h"

struct ObjectHitbox sMissileHitbox = {
    /* interactType: */ INTERACT_DAMAGE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 2,
    /* health: */ 1,
    /* numLootCoins: */ 7,
    /* radius: */ 40,
    /* height: */ 40,
    /* hurtboxRadius: */ 40,
    /* hurtboxHeight: */ 40,
};

void bhv_Magma_Thwomp() {
    if (o->oTimer > 120) {
        o->oTimer = 0;
        }

    if (o->oTimer == o->oBehParams2ndByte*20) {
        o->oVelY = 60;
        o->oSubAction = 1;
        cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        }

    o->oVelY -= 2;
    o->oPosY += o->oVelY;

    if (o->oPosY < o->oHomeY) {
        if (o->oSubAction) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
            o->oSubAction = 0;
            }
        o->oPosY = o->oHomeY;
        o->oVelY = 0;
        }
    }

void bhv_swing_Board (void) {
        if (o->oAction == 0) {
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                o->oTimer = 0;
                play_sound(SOUND_GENERAL_OPEN_CHEST, o->header.gfx.cameraToObject);
                }
            }
        if (o->oAction == 1) {
            o->oFaceAngleRoll += o->oMoveAngleRoll;
            if (o->oFaceAngleRoll > 0x4000) {
                o->oMoveAngleRoll -= 0x50;
                }
                else
                {
                o->oMoveAngleRoll += 0x50;
                }

            if (o->oTimer < 120) {
                o->oMoveAngleRoll *= .98;
                }

            }
        if (o->oDistanceToMario > 5000.0f) {
            o->oAction = 0;
            o->oMoveAngleRoll = 0;;
            o->oFaceAngleRoll = 0;
            }
    }

void bhv_Propane_Shooter(void) {
    struct Object *obj;

    if (o->oBehParams2ndByte == 1) {
        o->oFaceAngleYaw += 0x400;
        }
        else
        {
        o->oFaceAngleYaw -= 0x400;
        }
    if (o->oDistanceToMario < 1500.0f) {
        cur_obj_play_sound_1(SOUND_AIR_BLOW_FIRE);
        if (o->oTimer%3) {
            obj = spawn_object(o,MODEL_BLUE_FLAME,bhvPropane);
            obj->oMoveAngleYaw = o->oFaceAngleYaw;
            obj->oPosY += 90.0f;
            obj = spawn_object(o,MODEL_BLUE_FLAME,bhvPropane);
            obj->oMoveAngleYaw = o->oFaceAngleYaw+0x7FFF;
            obj->oPosY += 90.0f;
            }
        }
    }

void bhv_Propane_Flame(void) {
    obj_scale(o,3.0f-(o->oTimer * .15));
    o->oPosX += sins(o->oMoveAngleYaw) * 50.0f;
    o->oPosZ += coss(o->oMoveAngleYaw) * 50.0f;
    if (o->oTimer > 15) {
        obj_mark_for_deletion(o);
        }
    }

void bhv_lava_grate_loop(void) {
    if (o->oBehParams2ndByte == 0) {
        o->oPosY += o->oVelY;

        if (gMarioObject->platform == o) {
            if (o->oVelY > -50.0f) {
                o->oVelY -= .25;
                }
            }
            else
            {
            if (o->oVelY < 50.0f) {
                o->oVelY += .5;
                }
            }

        if (o->oVelY > (o->oHomeY - o->oPosY)*.1) {
            o->oVelY = (o->oHomeY - o->oPosY)*.1;
            }
        if (o->oPosY > o->oHomeY) {
            o->oPosY = o->oHomeY;
            o->oVelY = 0;
            }
        }
    }

void bhv_castle_raft(void) {
    o->oPosY = -100.0f + (sins(o->oTimer*0x200)*50.0f);

    o->oPosX = sins(o->oFaceAngleYaw+0x7FFF) * -13574;
    o->oPosZ = coss(o->oFaceAngleYaw+0x7FFF) * -13574;

    switch(o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                }
        break;
        case 1:
            o->oFaceAngleYaw += 0x10;
            if (o->oFaceAngleYaw > 0x7FFF) {
                o->oAction = 2;
                }
        break;
        case 2:
        
        break;
        }
    }

void bhv_ash_pile(void) {
    struct Object *sussy;

    switch(o->oAction) {
        case 0:
            load_object_collision_model();
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_ASHPILE2];
            o->oOpacity = 255.0f;

            sussy = cur_obj_nearest_object_with_behavior(bhvDogRovert);
            if ((gPlayer1Controller->buttonPressed & Z_TRIG) && (o->oDistanceToMario < 400) && (!sussy)) {
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                sussy = spawn_object(o,MODEL_DOG,bhvDogRovert);
                sussy->oPosY += 1000.0f;
                o->parentObj = sussy;
                o->oAction = 3;
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_ASHPILE];
                }
        break;
        case 1:
            if (o->oTimer%8==0) {
                cur_obj_play_sound_2(SOUND_ACTION_QUICKSAND_STEP);
                }
            if (o->oOpacity  > 20.0f) {
                o->oOpacity -= 2.0f;
                obj_scale(o,o->oOpacity/255.0f);
                o->parentObj->oPosY = o->oHomeY+((o->oOpacity/255.0f)*100.0f);
                }
                else
                {
                o->oAction = 2;
                }
        break;
        case 2:
            obj_mark_for_deletion(o->parentObj);
            spawn_object(o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);
            switch(o->oBehParams2ndByte) {
                case 0: //coin
                    spawn_object(o,MODEL_NONE,bhvThreeCoinsSpawn);
                break;
                case 1: //motos
                    spawn_object(o,MODEL_MOTOS,bhvMotos);
                break;
                case 2: //star
                    spawn_default_star(o->oPosX,o->oPosY+200.0f,o->oPosZ);
                break;
                case 3: //a mother fucking flame thrower!!!!! holy shit!!!!
                    spawn_object(o,MODEL_PROPANE_THROWER,bhvPropaneThrower);
                break;
                }
            obj_mark_for_deletion(o);
        break;
        case 3:
            o->parentObj->oPosY -= 30.0f;
            if (o->parentObj->oPosY < o->oHomeY + 100.0f) {
                o->parentObj->oPosY = o->oHomeY + 100.0f;
                o->oAction = 1;
                }
        break;
        }
    
    }

void bhv_rovert_elevator(void) {
    switch(o->oAction) {
        case 0:
            o->oPosY = o->oHomeY-3100.0f;
            o->oAction = 1;
        break;
        case 1:
            if (gMarioObject->platform == o) {
                o->oAction = 2;
                }
        break;
        case 2:
            if (o->oPosY < o->oHomeY) {
                o->oPosY += 30.0f;
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
                }
                else
                {
                o->oPosY = o->oHomeY;
                o->oAction = 3;
                }
        break;
        case 3:
            if (gMarioState->pos[1] < o->oPosY+500.0f) {
                o->oAction = 0;
                }
        break;
        }
    }

void bhv_rovert_fling(void) {
    switch(o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                cur_obj_play_sound_2(SOUND_OBJ_HEAVEHO_TOSSED);
                drop_and_set_mario_action(gMarioState, ACT_THROWN_BACKWARD, 1);
                gMarioState->vel[1] = 120.0f;
                gMarioState->forwardVel = 90.0f;
                gMarioState->faceAngle[1] = 0x7FFF;
                }
        break;
        case 1:
            o->oFaceAnglePitch -= 0x400;
            if (o->oFaceAnglePitch < -0x2800) {
                o->oAction = 2;
                }
        break;
        case 2:
            o->oFaceAnglePitch += 0x100;
            if (o->oFaceAnglePitch == 0x0) {
                o->oAction = 0;
                }
        break;
        }
    }

u8 toad_opened_cage_count;

void bhv_toad_cage(void) {
    
    switch(o->oAction) {
        case 0:
            toad_opened_cage_count = 0;
            o->prevObj = spawn_object(o,MODEL_TOAD,bhvRovertToad);
            o->prevObj->oAction = 5;
            o->prevObj->oPosY -= 110.0f;
            o->oAction = 1;
        break;
        case 1:
            load_object_collision_model();
            if (cur_obj_is_mario_ground_pounding_platform()) {
                cur_obj_play_sound_2(SOUND_ACTION_METAL_HEAVY_LANDING);
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TOAD_CAGE_3];
                o->oAction = 2;
                }
        break;
        case 2:
            load_object_collision_model();
            if (cur_obj_is_mario_ground_pounding_platform() && o->oTimer>10) {
                cur_obj_play_sound_2(SOUND_ACTION_METAL_HEAVY_LANDING);
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TOAD_CAGE_4];
                o->oAction = 3;
                }
        break;
        case 3:
            load_object_collision_model();
            if (cur_obj_is_mario_ground_pounding_platform() && o->oTimer>10) {
                cur_obj_play_sound_2(SOUND_ACTION_METAL_HEAVY_LANDING);
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TOAD_CAGE_2];
                o->oAction = 4;

                stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_TOAD_MESSAGE));
                play_music(SEQ_PLAYER_ENV, SEQUENCE_ARGS(4, SEQ_EVENT_TOAD_MESSAGE), 0);

                toad_opened_cage_count ++;
                }
        break;
        case 4:
        //dlete toad
        if (o->prevObj != NULL) {
            o->prevObj->oOpacity --;
            if (o->prevObj->oOpacity == 5) {
                obj_mark_for_deletion(o->prevObj);
                o->prevObj = NULL;
                }
            }
        break;
        }
    }

void bhv_rovert_toad(void) {
    o->oFaceAngleYaw = o->oAngleToMario;
    switch(o->oAction) {
        case 0:
            if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_002)) {
                o->oAction = 1;
                }
        break;
        case 1:
            
            if ((o->oDistanceToMario < 200.0f)&&(toad_opened_cage_count == 5)) {
                if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_003)) {
                    spawn_default_star(o->oPosX+100.0f,o->oPosY+200.0f,o->oPosZ);
                    o->oAction = 2;
                    }
                }
        break;
        case 2:

        break;
        }
    }

u16 tank_target_angle;
u8 tank_phase;

void bhv_tank_base(void) {
    struct Object *spawnobj;
    u16 a_diff;
    switch(o->oAction) {
        case 0://init
        o->oAction = 1;
            o->oHealth = 3;
            tank_phase = 1;
            o->prevObj = spawn_object(o,MODEL_TANK_HEAD,bhvTankHead);
        break;
        case 1://wait for mario
            if (o->oDistanceToMario < 1500.0f) {
                if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_000)) {
                    o->oAction = 2;
                    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_BOSS_PEACH_RUINS), 0);
                    }
                }
        break;
        case 2://chase mario
            if (tank_phase) {
                if (o->oTimer%10==0) {
                    spawnobj = spawn_object_relative(0, 0, 300, 700, o->prevObj, MODEL_BLUE_FLAME, bhvTankPropane);
                    spawnobj->oMoveAngleYaw = o->oFaceAngleYaw;
                    cur_obj_play_sound_2(SOUND_OBJ_FLAME_BLOWN);
                    spawnobj->oHomeY = o->oPosY;
                    }
                }
                else
                {
                if (o->oTimer%(40+(o->oHealth*5))==0) {
                    spawnobj = spawn_object_relative(0, 0, 300, 700, o->prevObj, MODEL_MISSILE, bhvMissile);
                    spawnobj->parentObj = o;
                    spawnobj->oMoveAngleYaw = o->prevObj->oFaceAngleYaw;
                    cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
                    spawnobj->oHomeY = o->oPosY;
                    }
                }
            if (o->oTimer%60==0) {
                tank_target_angle = cur_obj_angle_to_home();
                }
            if (o->oForwardVel < 40.0f-(10.0*o->oHealth)) {
                o->oForwardVel += .2;
                }
            if (o->oTimer > 250) {
                o->oAction = 4;
                }
        break;
        case 3://death
            tank_target_angle = o->oMoveAngleYaw;
            o->oForwardVel = 0.0f;
            if (o->oTimer > 70) {
                if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_001)) {
                    spawn_default_star(o->oPosX,o->oPosY+700.0f,o->oPosZ);
                    o->oAction = 6;
                    }
                }
        break;//
        case 4://charge
            tank_target_angle = o->oAngleToMario;
            if (o->oForwardVel > -(o->oHealth*4.0)) {
                o->oForwardVel -= 0.5f;
                }
                else
                {
                o->oAction = 5;
                }
        break;
        case 5:
            tank_target_angle = o->oAngleToMario;
            if (o->oForwardVel < 50.0f) {
                o->oForwardVel += 3.0;
                }
            if (o->oTimer > 90) {
                o->oAction = 2;
                tank_phase = !tank_phase;
                }
        break;
        }

    a_diff = tank_target_angle - o->oMoveAngleYaw;
    a_diff = (a_diff + 0x7FFF) % 0xFFFF - 0x7FFF;

    if ((a_diff > 0x200)&&(a_diff < 0x7FFF)) {
        o->oMoveAngleYaw += 0x200;
        }
    if ((a_diff < 0xFFDF)&&(a_diff > 0x7FFF)) {
        o->oMoveAngleYaw -= 0x200;
        }

    
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-30);
    o->oFaceAngleYaw = o->oMoveAngleYaw;

    //if mario falls reset boss
    if ((gMarioState->pos[1] < o->oHomeY-100.0f)&&(o->oAction>1)&&(o->oAction!=3)&&(o->oAction!=6)) {
        stop_background_music(SEQUENCE_ARGS(4, SEQ_BOSS_PEACH_RUINS));
        play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_PEACH_RUINS), 0);
        o->oAction = 1;
        o->oHealth = 3;
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        o->oMoveAngleYaw = 0;
        o->oForwardVel = 0.0f;
        }

    o->prevObj->oAction = o->oAction;
    o->prevObj->oPosX = o->oPosX;
    o->prevObj->oPosZ = o->oPosZ;
    o->prevObj->oPosY = o->oPosY;
    tank_treads = o->oForwardVel;
    }

u16 FaceAngleLock = 0;
f32 angle_speed = 0;
f32 roll_amount = 0;
f32 crack_sound = 0;

void bhv_tank_head(void) {
    u16 a_diff;
    u8 anyone_picked = FALSE;
    struct Object *spawnobj;

    if ((o->oAction != 3)&&(o->oAction != 6)) {//live
        a_diff = o->parentObj->oAngleToMario - o->oFaceAngleYaw;
        a_diff = (a_diff + 0x7FFF) % 0xFFFF - 0x7FFF;

        crack_sound += angle_speed;
        if (crack_sound > 200.0f) {
            crack_sound -= 200.0f;
            cur_obj_play_sound_2(SOUND_MOVING_AIM_CANNON);
            }
        if (crack_sound < -200.0f) {
            crack_sound += 200.0f;
            cur_obj_play_sound_2(SOUND_MOVING_AIM_CANNON);
            }


        if ((a_diff > 0x300)&&(a_diff < 0x7FFF)) {
        angle_speed += 0x15;
        anyone_picked = TRUE;
            }
        if ((a_diff < 0xFFCF)&&(a_diff > 0x7FFF)) {
            angle_speed -= 0x15;
            anyone_picked = TRUE;
            }
        if (!anyone_picked) {
            angle_speed /= 1.2;
            }

        //cap
        //dont feel like writing a clamp function xd
        if (angle_speed > 768.0f) {
            angle_speed = 768.0f;
            }
        if (angle_speed < -768.0f) {
            angle_speed = -768.0f;
            }

        o->oFaceAngleYaw += (s16)angle_speed;
        o->oFaceAngleRoll = sins(o->oTimer*0x700)*roll_amount;
        roll_amount *= 0.99;

        if ((cur_obj_is_mario_ground_pounding_platform())&&(o->oTimer > 20)) {
            o->oTimer = 0;
            o->parentObj->oHealth --;
            cur_obj_play_sound_2(SOUND_ACTION_METAL_HEAVY_LANDING);
            if (o->parentObj->oHealth < 1) {
                FaceAngleLock = o->oFaceAngleYaw;
                o->parentObj->oAction = 3;
                o->oAction = 3;
                o->parentObj->oAction = 3;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_BOSS_PEACH_RUINS));
                play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_PEACH_RUINS), 0);

                //bruh this code is sus as shit xd
                spawnobj = spawn_object(o,MODEL_RED_FLAME,bhvFlame);
                spawnobj->oPosY += 300.0f;
                spawnobj->oPosX += sinf(o->oFaceAngleYaw+1000)*200.0f;
                spawnobj->oPosZ += cosf(o->oFaceAngleYaw+1000)*200.0f;
                spawnobj = spawn_object(o,MODEL_RED_FLAME,bhvFlame);
                spawnobj->oPosY += 300.0f;
                spawnobj->oPosX -= sinf(o->oFaceAngleYaw+0x5FFF)*270.0f;
                spawnobj->oPosZ -= cosf(o->oFaceAngleYaw+0x5FFF)*270.0f;
                }
                else
                {
                cur_obj_play_sound_2(SOUND_OBJ_HEAVEHO_TOSSED);
                drop_and_set_mario_action(gMarioState, ACT_THROWN_BACKWARD, 1);
                gMarioState->vel[1] = 40.0f;
                gMarioState->forwardVel = 40.0f;
                gMarioState->faceAngle[1] = o->oFaceAngleYaw+0x7FFF;
                roll_amount = 0x1000;
                }
            }
        }
        else
        {//die
        o->oFaceAngleYaw = FaceAngleLock;
        if (o->oTimer < 50) {
            o->oFaceAnglePitch += 0x30;
            }
        }
    }

void bhv_Tank_Propane_Flame() {
    switch(o->oAction) {
        case 0:
            o->oPosY -= 10.0f;
            if (o->oPosY < o->oHomeY+20.0f) {
                o->oPosY = o->oHomeY;
                o->oAction = 1;
                }
        break;
        case 1:
            if (o->oTimer > 200) {
                o->oAction = 2;
                o->oTimer = 0;
                }
        break;
        case 2:
            obj_scale(o,((10.0f-(f32)(o->oTimer))/10.0f)*5.0f);//crack head code
            if (o->oTimer > 10) {
                obj_mark_for_deletion(o);
                }
        break;
        }
    }

void bhv_Launcher_Motos() {
    struct Object *spawnobj;
    o->oHealth = 1;
    o->oFaceAngleYaw = o->oAngleToMario;
    if (o->oBehParams2ndByte == 1) {
        if ((o->oTimer%30==0)&&(o->oDistanceToMario < 3000.0f)) {
                spawnobj = spawn_object_relative(0, 0, 10, 200, o, MODEL_MISSILE, bhvMissile);
                spawnobj->oPosY += 200.0f;
                spawnobj->oMoveAngleYaw = o->oFaceAngleYaw;
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
            }
        }
    }


static s16 obj_turn_pitch_toward_mario_rovert(f32 targetOffsetY, s16 turnAmount) {
    s16 targetPitch;

    o->oPosY -= targetOffsetY;
    targetPitch = obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_PITCH_INDEX, turnAmount);
    o->oPosY += targetOffsetY;

    return targetPitch;
}

void bhv_missile_loop(void) {
    o->oMoveAnglePitch = obj_turn_pitch_toward_mario_rovert(120.0f, 80);
    o->oFaceAnglePitch = -o->oMoveAnglePitch;
    o->oGravity = 0;
    o->oFaceAngleYaw = o->oMoveAngleYaw+0x7FFF;
    obj_turn_toward_object(o, gMarioObject, 16, 0x100);

    o->oForwardVel = 40.0f *  coss(o->oMoveAnglePitch);
    o->oVelY       = 40.0f * -sins(o->oMoveAnglePitch);

    o->oPosY += o->oVelY;

    if ((o->oTimer > 100)&&(o->oMoveAnglePitch < 0xD000)) {
        o->oMoveAnglePitch += 0x100;
        }

    //INIT
    if (o->oAction == 0) {
        obj_set_hitbox(o, &sMissileHitbox);
        o->oAction = 1;
        }

    if ((o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_HIT_WALL))||(o->oTimer > 300)||(o->oMoveFlags & 0x200)||(o->parentObj->oHealth == 0)) {
        spawn_object(o,MODEL_EXPLOSION,bhvExplosion);
        obj_mark_for_deletion(o);
        }

    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(50);
    }

//yabba dabba doo