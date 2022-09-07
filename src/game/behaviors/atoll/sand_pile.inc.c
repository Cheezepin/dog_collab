void bhv_sand_pile(void) {
    struct Object *sussy; 
    f32 dist;
 switch(o->oAction) {
        case 0:
            load_object_collision_model();

            sussy = cur_obj_nearest_object_with_behavior(bhvDogRovert);
            if ((gPlayer1Controller->buttonPressed & Z_TRIG) && (o->oDistanceToMario < 400) && (!sussy)) {
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
                o->header.gfx.scale[1] -= 0.04f;
            } else {
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