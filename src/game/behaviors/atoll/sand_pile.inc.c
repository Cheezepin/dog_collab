void bhv_sand_pile(void) {
    struct Object *sussy; 
    f32 dist;
 switch(o->oAction) {
        case 0:
            load_object_collision_model();

            sussy = cur_obj_nearest_object_with_behavior(bhvDogRovert);
            if ((gPlayer1Controller->buttonPressed & Z_TRIG) && (o->oDistanceToMario < 400) && (!sussy)) {
                if (o->oBehParams2ndByte == 4) {
                    return;
                }
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                sussy = spawn_object(o,MODEL_DOG,bhvDogRovert);
                sussy->oPosY += 1000.0f;
                o->parentObj = sussy;
                //cur_obj_scale_over_time(SCALE_AXIS_Y, 5, 1.0f, 0.2f);
                o->oAction = 3;
                }
        break;
        case 1:
            if (o->oTimer%8==0) {
                cur_obj_play_sound_2(SOUND_ACTION_QUICKSAND_STEP);
                }
            if (o->header.gfx.scale[1] > 0.2f) {
                o->parentObj->oPosY = o->oHomeY+((o->header.gfx.scale[1]/255.0f)*100.0f);
                o->header.gfx.scale[1] -= 0.06f;
            } else {
                o->oAction = 2;
            }
        break;
        case 2:
            obj_mark_for_deletion(o->parentObj);
            spawn_object(o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);
            switch(o->oBehParams2ndByte) {
                case 0: //sand pillar
                    sussy = spawn_object(o,MODEL_SAND_PILLAR,bhvSandPillar);
                    sussy->oBehParams = o->oBehParams;
                break;
                case 1: //motos
                    sussy = spawn_object(o,MODEL_SAND_SLOPE,bhvSandSlope);
                    sussy->oBehParams = o->oBehParams;
                break;
                case 2: //star
                    sussy = spawn_object(o,MODEL_SAND_PILLAR,bhvSandPillar);
                    sussy->oBehParams = o->oBehParams;
                break;
                case 3: //a mother fucking flame thrower!!!!! holy shit!!!!
                    spawn_object(o,MODEL_PROPANE_THROWER,bhvPropaneThrower);
                break;
                case 4: //a mother fucking cheerrry tree holy shit!!!!
                    spawn_object(o,MODEL_CHERRY_TREE,bhvCherryTree);
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

void bhv_sand_pillar_init(void) {
    o->header.gfx.scale[0] = 0;
    o->header.gfx.scale[1] = 0;
    o->header.gfx.scale[2] = 0;
}

void bhv_sand_pillar_loop(void) {
    if(o->oSubAction == 0) {
        f32 targetY = ((f32)((o->oBehParams >> 8) & 0xFF)) / 10.0f;
        f32 targetLat = ((f32)(o->oBehParams & 0xFF)) / 10.0f;
        o->header.gfx.scale[1] = approach_f32_asymptotic(o->header.gfx.scale[1], targetY, 0.25f);
        o->header.gfx.scale[0] = o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[0], targetLat, 0.25f);
        if(targetY - o->header.gfx.scale[1] < 0.01f) {
            o->header.gfx.scale[1] = targetY;
            o->header.gfx.scale[0] = o->header.gfx.scale[2] = targetLat;
            o->oFlags &= ~OBJ_FLAG_DONT_CALC_COLL_DIST;
            o->oSubAction = 1;
            if((o->oBehParams >> 24) == 1) {
                struct Object *star = spawn_star(o, o->oPosX,o->oPosY+2000.0f,o->oPosZ);
                star->oBehParams = 0x00000000;
            }
        }
    }
}

f32 ktq_ring_calc_mario_dist(void) {
    f32 marioDistX = o->oPosX - gMarioObject->header.gfx.pos[0];
    f32 marioDistY = o->oPosY - (gMarioObject->header.gfx.pos[1] + 80.0f);
    f32 marioDistZ = o->oPosZ - gMarioObject->header.gfx.pos[2];
    f32 marioDistInFront = marioDistX * o->oWaterRingNormalX + marioDistY * o->oWaterRingNormalY
                           + marioDistZ * o->oWaterRingNormalZ;

    return marioDistInFront;
}

void bhv_ktq_ring_init(void) {
}

void ktq_ring_check_collection() {
    if (o->oInteractStatus != 0) {
        struct Object *ktq = o->parentObj;

        if (ktq) {
                ktq->oWaterRingSpawnerRingsCollected++;
                spawn_orange_number(ktq->oWaterRingSpawnerRingsCollected, 0, -40, 0);
                play_sound(SOUND_MENU_COLLECT_SECRET
                            + (((u8) ktq->oWaterRingSpawnerRingsCollected - 1) << 16),
                            gGlobalSoundSource);

        }

        obj_mark_for_deletion(o);
    }
}

void bhv_ktq_ring_loop(void) {
    ktq_ring_check_collection();
}