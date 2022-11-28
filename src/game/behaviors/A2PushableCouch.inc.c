
struct ObjectHitbox s2639CouchHitbox = {
    /* interactType: */ 0,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 1000,
    /* height: */ 300,
    /* hurtboxRadius: */ 1000,
    /* hurtboxHeight: */ 300,
};

#define o2639PushDist OBJECT_FIELD_S32(0x1B)
#define o2639SecretActivated OBJECT_FIELD_S32(0x1C)
#define o2639DogBitten OBJECT_FIELD_S32(0x1C)

void bhv_A2PushableCouch_init(void) {
	o->o2639PushDist = 0;
	o->o2639SecretActivated = 0;
}

void makeSecret(void) {
    struct Object *hiddenStar = cur_obj_nearest_object_with_behavior(bhv2639a2hiddenstar);
    if (hiddenStar != NULL) {
        hiddenStar->oHiddenStarTriggerCounter++;
        if (hiddenStar->oHiddenStarTriggerCounter != 5) {
            spawn_orange_number(hiddenStar->oHiddenStarTriggerCounter, 0, 0, 0);
        }
        play_sound(SOUND_MENU_COLLECT_SECRET
                       + (((u8) hiddenStar->oHiddenStarTriggerCounter - 1) << 16),
                   gGlobalSoundSource);
    }
}

f32 CouchXZDistSq(Vec3f x, Vec3f y) {
    return ((x[0] - y[0]) * (x[0] - y[0])) + ((x[2] - y[2]) * (x[2] - y[2]));
}

void bhv_A2PushableCouch_loop(void) {
    o->oForwardVel = 0;

	if (o->o2639SecretActivated) {
		return;
	}

    if (gCurrActNum != 6) {
        struct Object *goddardObj = cur_obj_nearest_object_with_behavior(bhvDogfloor1);
        if (goddardObj) {
            if (CouchXZDistSq(&o->oPosX, &goddardObj->oPosX) < 2500 && goddardObj->oAction == 2) {
                goddardObj->o2639DogBitten = 1;
                obj_explode_and_spawn_coins(46.0f, 0);
                create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
                o->o2639SecretActivated = 1;
            }
        }
    }


	s16 angleToMario;
    obj_set_hitbox(o, &s2639CouchHitbox);
    o->oForwardVel = 0.0f;
    if (obj_check_if_collided_with_object(o, gMarioObject) 
        && gMarioStates[0].flags & MARIO_PUSHING
    ) {
        angleToMario = obj_angle_to_object(o, gMarioObject);
        if (abs_angle_diff(angleToMario, gMarioObject->oMoveAngleYaw) > 0x4000) {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if (check_if_moving_over_floor(8.0f, 150.0f)) {
                o->oForwardVel = 4.0f;
                o->o2639PushDist += 4;
				if (o->o2639PushDist >= 200 && gCurrActNum != 6) {
					o->o2639SecretActivated = 1;
					// spawn secret at mairo
                    makeSecret();
				}
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
            }
        }
    }
    cur_obj_move_using_fvel_and_gravity();
}


#undef o2639PushDist
#undef o2639SecretActivated

