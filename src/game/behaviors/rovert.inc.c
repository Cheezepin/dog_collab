//hey sussy baka >:3

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
            o->oAction = 1;
        break;
        case 1:
            
            if ((o->oDistanceToMario < 200.0f)&&(toad_opened_cage_count == 5)) {
                spawn_default_star(o->oPosX+100.0f,o->oPosY+200.0f,o->oPosZ);
                o->oAction = 2;
                }
        break;
        case 2:

        break;
        }
    }