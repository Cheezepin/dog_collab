
void bhv_2639A4DrainScrew_init(void) {
	
}
void bhv_2639A4DrainScrew_loop(void) {
	struct Surface *w = gMarioState->wall;

    if (w != NULL) {
        struct Object *oo = w->object;
        s16 angle1 = o->oAngleToMario;
        s16 angle2 = atan2s(w->normal.z, w->normal.x);


        if (oo == o) {
            if ((s16)(angle2 - angle1) < 0) {
                o->oMoveAngleYaw += 0x180;
                o->oVelY = 10;
            } else {
                o->oMoveAngleYaw -= 0x180;
                o->oVelY = -10;
            }
        }
    }

    if (o->oVelY < 0) {
    	o->oVelY++;
    }
    if (o->oVelY > 0) {
    	o->oVelY++;
    }

    char dbg[50];
    sprintf(dbg, "VEL %d", w, o->oVelY);
    print_text(50, 50, dbg);
}
