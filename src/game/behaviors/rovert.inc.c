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