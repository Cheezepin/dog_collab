void bhv_power_switch_init(void) {
    if (o->oBehParams2ndByte == 1) {
        o->oFaceAnglePitch = 0x2000;
        o->oMoveAnglePitch = 0x2000;
    }
    else {
        o->oFaceAnglePitch = -0x2000;
        o->oMoveAnglePitch = -0x2000;
    }
}

void bhv_power_switch_loop(void) {

extern u8 gShadeScreenAmount;

    if (o->oBehParams2ndByte == 0) {
    if (o->oDistanceToMario < 300.0f && o->oAction == 0) {
        o->oAction = 1;
        o->oTimer = 0;
        cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN);
    }
    if (o->oAction == 1 ) {
        
        if (o->oTimer < 32) {
            o->oFaceAnglePitch += 0x200;
            o->oMoveAnglePitch += 0x200;
        }
        else {
            o->oAction = 2;
            o->oTimer = 0;
            seq_player_fade_out(0, 900);
        }
    }
    if (o->oAction == 2) {
        
            
        gShadeScreenAmount = o->oTimer * 4;
        
        if (o->oTimer >= 60) {
        initiate_warp(LEVEL_JRB, 2, 0x0B, 0);
        }
    }

    


    }
    else if (o->oBehParams2ndByte == 1) {
        if (gShadeScreenAmount > 60) {
            gShadeScreenAmount -= 2;
            if (gShadeScreenAmount == 60) {
                play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_SAD_OLIVIA), 0);
            }
        }
    }
}