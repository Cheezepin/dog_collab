u8 counter;
void bhv_bowser_lightning_loop(void){
    struct Object *mine;
    struct Object *bowser;
    bowser = cur_obj_nearest_object_with_behavior(bhvBowser);
    mine = cur_obj_nearest_object_with_behavior(bhvEmuBomb);
    if(bowser->oHealth == 3) {
    if (mine != NULL && mine->oHeldState == HELD_HELD){
        if (counter > 100){
            if (o->oTimer == 0){
                cur_obj_set_model(MODEL_RED_CIRCLE);
                o->oPosX = gMarioState->pos[0];
                o->oPosZ = gMarioState->pos[2];
            }
            if (o->oTimer > 7){
                cur_obj_set_model(MODEL_LIGHTNING);
                cur_obj_play_sound_1(SOUND_MOVING_SHOCKED);
                f32 xDel = gMarioState->pos[0] - o->oPosX;
                f32 zDel = gMarioState->pos[2] - o->oPosZ;
                f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
                if (marioXZDist <= 175){
                    interact_shock(gMarioState, INTERACT_SHOCK, o);
                }
            }
            if (o->oTimer > 15){
                obj_mark_for_deletion(o);
            }
        }
        else {counter++;}
    } else {
        counter = 0;
        if (o->oTimer == 0){
            cur_obj_set_model(MODEL_RED_CIRCLE);
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
        }
        if (o->oTimer > 30){
            cur_obj_set_model(MODEL_LIGHTNING);
            cur_obj_play_sound_1(SOUND_MOVING_SHOCKED);
            f32 xDel = gMarioState->pos[0] - o->oPosX;
            f32 zDel = gMarioState->pos[2] - o->oPosZ;
            f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
            if (marioXZDist <= 30){
                interact_shock(gMarioState, INTERACT_SHOCK, o);
            }
        }
        if (o->oTimer > 40){
            obj_mark_for_deletion(o);
        }
    }
} else {
    if (mine != NULL && mine->oHeldState == HELD_HELD){
        if (counter > 100){
            if (o->oTimer == 0){
                cur_obj_set_model(MODEL_RED_CIRCLE);
                o->oPosX = gMarioState->pos[0];
                o->oPosZ = gMarioState->pos[2];
            }
            if (o->oTimer > 12){
                cur_obj_set_model(MODEL_LIGHTNING);
                cur_obj_play_sound_1(SOUND_MOVING_SHOCKED);
                f32 xDel = gMarioState->pos[0] - o->oPosX;
                f32 zDel = gMarioState->pos[2] - o->oPosZ;
                f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
                if (marioXZDist <= 175){
                    interact_shock(gMarioState, INTERACT_SHOCK, o);
                }
            }
            if (o->oTimer > 17){
                obj_mark_for_deletion(o);
            }
        }
        else {counter++;}
    } else {
        counter = 0;
        if (o->oTimer == 0){
            cur_obj_set_model(MODEL_RED_CIRCLE);
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
        }
        if (o->oTimer > 50){
            cur_obj_set_model(MODEL_LIGHTNING);
            cur_obj_play_sound_1(SOUND_MOVING_SHOCKED);
            f32 xDel = gMarioState->pos[0] - o->oPosX;
            f32 zDel = gMarioState->pos[2] - o->oPosZ;
            f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
            if (marioXZDist <= 30){
                interact_shock(gMarioState, INTERACT_SHOCK, o);
            }
        }
        if (o->oTimer > 60){
            obj_mark_for_deletion(o);
        }
    }
}
}

void bhv_stationary_lightning_loop(void){
    struct Object *mine;
    mine = cur_obj_nearest_object_with_behavior(bhvEmuBomb);
    if (mine == NULL){
        obj_mark_for_deletion(o);
    }
    f32 xDel = gMarioState->pos[0] - o->oPosX;
    f32 zDel = gMarioState->pos[2] - o->oPosZ;
    f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
    if (marioXZDist <= 30){
        interact_shock(gMarioState, INTERACT_SHOCK, o);
    }
}