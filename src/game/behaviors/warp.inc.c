// warp.inc.c

#define oWarped OBJECT_FIELD_S32(0x1B)
void bhv_warp_loop(void) {
    if (o->oTimer == 0) {
        u16 radius = GET_BPARAM1(o->oBehParams);

        if (radius == 0) {
            o->hitboxRadius = 50.0f;
        } else if (radius == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = radius * 10.0f;
        }
        o->hitboxHeight = 50.0f;
    }
    if (in2639Level() && (gCurrAreaIndex == 1)) {
        o->hitboxRadius = 0;
        if (gMarioState->pos[2] < -2500.0f && (o->oWarped == 0)) {
            o->oWarped = 1;
            warp_mario2(gMarioState, 20, GET_BPARAM2(o->oBehParams));
        }
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

// identical to the above function except for o->hitboxRadius
void bhv_fading_warp_loop() {
    if (o->oTimer == 0) {
        u16 radius = GET_BPARAM1(o->oBehParams);

        if (radius == 0) {
            o->hitboxRadius = 85.0f;
        } else if (radius == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = radius * 10.0f;
        }
        o->hitboxHeight = 50.0f;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}
