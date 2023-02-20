
void bhv_2639Vending_init(void) {
	o->oBehParams2ndByte = 0;
	o->oAction = 0;
	o->oTimer = 0;
}

enum VendAnims {
	V_IDLE = 0,
	V_VEND = 1,
};

void bhv_2639Vending_loop(void) {

	switch (o->oAction) {
		case 0:
			if (o->oBehParams2ndByte == 1) {
				if (Obj_GetAnyObj(bhv2639soda) == NULL) {
					o->oBehParams2ndByte = 0;
				}
				break;
			}
			if (o->oDistanceToMario <= 300) {
				if (gMarioState->action == ACT_PUNCHING
					|| gMarioState->action == ACT_MOVE_PUNCHING
				) {
					obj_init_animation(o, V_VEND);
					o->oAction = 1;
					o->oTimer = 0;
					o->oBehParams2ndByte = 1;
				}
			}
			break;

		case 1:
			if (o->oTimer >= 59) {
				o->oAction = 0;
				LaunchObject(o, bhv2639soda, MODEL_2639SODA);
				// obj_explode_and_spawn_coins(46.0f, 0);
            	create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
            	// mark_obj_for_deletion(o);
			}
			break;

	}

	// char dbg[50];
	// sprintf(dbg, "%d", (int)o->oDistanceToMario);
	// print_text(50, 50, dbg);

	o->oTimer++;
}
