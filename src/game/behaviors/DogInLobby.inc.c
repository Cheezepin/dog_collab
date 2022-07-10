
void bhv_DogInLobby_init(void) {
	o->oAction = 0;	
}
void bhv_DogInLobby_loop(void) {
	struct Object *CaneObj = cur_obj_nearest_object_with_behavior(bhv2639cane);
	struct Object *GlassesObj = cur_obj_nearest_object_with_behavior(bhv2639glasses);


	switch (o->oAction) {
		case 0:
			dog_FollowMario();
			if (CaneObj != NULL) {
				if (dist_between_objects(o, CaneObj) < 500) {
					o->oAction = 1;
				}
			}
			break;
		case 1:
    		cur_obj_init_animation(DOG_ANIM_RUN);
			o->oForwardVel = 0.0f;
        	obj_turn_toward_object(o, CaneObj, 16, 0x800);
        	if (o->oTimer > 60) {
        		o->oAction = 2;
        	}
			break;
		case 2:
			o->oForwardVel = 25.0f;
            if (CaneObj != NULL) {
                obj_turn_toward_object(o, CaneObj, 16, 0x800);
            } else {
                o->oAction = 0;
            }
	}




    // play_sound(SOUND_ACTION_METAL_STEP, gGlobalSoundSource);
    // deliciousCouch = find_unpushed_couch(bhvA2pushablecouch, &dist);
    // if (deliciousCouch != NULL) {
    //     if (o->oTimer > 60) {
    //         o->oAction++;
    //     }
    // }
    // break;
}
