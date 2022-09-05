
void bhv_2639A4DrainScrew_init(void) {
	o->oAction = 0;
}
void bhv_2639A4DrainScrew_loop(void) {

	if (o->oAction == 1) {

		o->oVelY = 20;

		o->oMoveAnglePitch += 4;

		cur_obj_move_standard(-78);
		if (o->oTimer > 40) {
			obj_explode_and_spawn_coins(46.0f, 0);
            create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
            cur_obj_spawn_star_at_y_offset(o->oPosX, o->oPosY, o->oPosZ, 200.0f);
		}

		o->oTimer++;
		return;
	}

	struct Surface *w = gMarioState->wall;

    if (w != NULL) {
        struct Object *oo = w->object;
        s16 angle1 = o->oAngleToMario;
        s16 angle2 = atan2s(w->normal.z, w->normal.x);


        if (oo == o) {
            if ((s16)(angle2 - angle1) < 0) {
                o->oMoveAngleYaw += 0x180;
                o->oVelY = 5;
            } else {
                o->oMoveAngleYaw -= 0x180;
                o->oVelY = -5;
            }
        }
    }

    if (o->oVelY < 0) {
    	o->oVelY++;
    }
    if (o->oVelY > 0) {
    	o->oVelY--;
    }
    cur_obj_move_standard(-78);

    if (o->oHomeY - o->oPosY > 40) {
    	o->oPosY = o->oHomeY;
    }

    if (o->oPosY - o->oHomeY > 439) {
    	o->oAction = 1;
    	o->oTimer = 0;
    } else {
    	load_object_collision_model();
    }




    // char dbg[50];
    // sprintf(dbg, "POS %f", o->oPosY);
    // print_text(50, 50, dbg);
}
