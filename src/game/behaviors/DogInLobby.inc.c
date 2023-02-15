#define DOG_ANIM_IDLE 0
#define DOG_ANIM_DIG  1
#define DOG_ANIM_RUN  2
#define DOG_ANIM_WALK 3
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
                    o->oTimer = 0;
                }
            }

            if (GlassesObj != NULL) {
                if (dist_between_objects(o, GlassesObj) < 500) {
                    o->oAction = 5;
                    o->oTimer = 0;
                }
            }
            break;
        case 1:
            play_sound(SOUND_CUSTOM_2639BARK, gGlobalSoundSource);
            o->oAction++;
            break;
        case 2:
            cur_obj_init_animation(DOG_ANIM_RUN);
            o->oForwardVel = 0.0f;
            obj_turn_toward_object(o, CaneObj, 16, 0x800);
            if (o->oTimer > 60) {
                o->oAction = 3;
                o->oTimer = 0;
            }
            break;
        case 3:
            o->oForwardVel = 25.0f;
            if (CaneObj != NULL) {
                obj_turn_toward_object(o, CaneObj, 16, 0x800);
                if (dist_between_objects(o, CaneObj) < 50) {
                    o->oAction = 4;
                }
            } else {
                o->oAction = 0;
            }
            break;
        case 4:
            cur_obj_init_animation(DOG_ANIM_DIG);
            o->oForwardVel = 0.0f;
            if (CaneObj == NULL) {
                o->oAction = 0;
            }
            break;


        case 5:
            play_sound(SOUND_CUSTOM_2639BARK, gGlobalSoundSource);
            o->oAction++;
        case 6:
            cur_obj_init_animation(DOG_ANIM_RUN);
            o->oForwardVel = 0.0f;
            obj_turn_toward_object(o, GlassesObj, 16, 0x800);
            if (o->oTimer > 60) {
                o->oAction = 7;
                o->oTimer = 0;
            }
            break;
        case 7:
            o->oForwardVel = 25.0f;
            if (GlassesObj != NULL) {
                obj_turn_toward_object(o, GlassesObj, 16, 0x800);
                if (dist_between_objects(o, GlassesObj) < 50) {
                    o->oAction = 8;
                }
            } else {
                o->oAction = 0;
            }
            break;
        case 8:
            cur_obj_init_animation(DOG_ANIM_DIG);
            o->oForwardVel = 0.0f;
            if (GlassesObj == NULL) {
                o->oAction = 0;
            }
            break;
    }



    // char tt[50];
    // sprintf(tt, "D %d DST %f", o->oAction, dist_between_objects(o, CaneObj));
    // print_text(20, 100, tt);

    // play_sound(SOUND_ACTION_METAL_STEP, gGlobalSoundSource);
    // deliciousCouch = find_unpushed_couch(bhvA2pushablecouch, &dist);
    // if (deliciousCouch != NULL) {
    //     if (o->oTimer > 60) {
    //         o->oAction++;
    //     }
    // }
    // break;
}
