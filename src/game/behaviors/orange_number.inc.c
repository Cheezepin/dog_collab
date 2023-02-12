// orange_number.inc.c

void bhv_orange_number_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oVelY = 26.0f;
    o->oPosX += 5.0f;
}

void bhv_orange_number_loop(void) {
    if (gCurrLevelNum == LEVEL_BOWSER_1){
    o->oPosY = o->oHomeY+50.0f + (30.0f*coss(o->oTimer * 0x600));
    if(o->parentObj->oHeldState != 0){
        obj_mark_for_deletion(o);
    }
} else {
#ifdef DIALOG_INDICATOR
    if (o->oAnimState <= ORANGE_NUMBER_9) {
#endif
        o->oPosY += o->oVelY;
        o->oVelY -= 2.0f;

        if (o->oVelY < -21.0f) {
            o->oVelY = 14.0f;
        }

        if (o->oTimer == 35) {
            struct Object *sparkleObj = spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
            sparkleObj->oPosY -= 30.0f;
            obj_mark_for_deletion(o);
        }
#ifdef DIALOG_INDICATOR
    } else if (o->oTimer >= 1 || gMarioState->action == ACT_READING_SIGN) {
        obj_mark_for_deletion(o);
    }
#endif
}
}
