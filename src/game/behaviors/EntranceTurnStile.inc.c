


void bhv_EntranceTurnStile_init(void) {

}

int EntranceTurnStile_Mult = 1;

void bhv_EntranceTurnStile_loop(void) {
    struct Surface *w = gMarioState->wall;

    if (w != NULL) {
        struct Object *oo = w->object;
        s16 angle1 = o->oAngleToMario;
        s16 angle2 = atan2s(w->normal.z, w->normal.x);


        if (oo == o) {
            if ((s16)(angle2 - angle1) < 0) {
                o->oMoveAngleYaw += 0x180;
            } else {
                o->oMoveAngleYaw -= 0x180;
            }
        }
    }

    // use the difference between the angle of the normal of the wall
    // and marios angle from the center of the door



}
