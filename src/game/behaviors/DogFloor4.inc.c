
void bhv_DogFloor4_init(void) {
	o->oAction = 0;
}
#include "game/debug.h"
#define DOG_SNAP_SPEED 100.0f
enum DF4_State {
	DF4_IDLE,
	DF4_WOOF,
	DF4_APPROACH,
	DF4_HIT,
	DF4_FILLER1,
};
	// char dbg[50];
	// sprintf(dbg, "D %f", ballDist);
	// print_text(50, 50, dbg);
void bhv_DogFloor4_loop(void) {
	float ballDist;
	struct Object *yummyball = cur_obj_find_nearest_object_with_behavior(
		bhv2639SoccerBall, &ballDist
	);


	switch (o->oAction) {
		case DF4_IDLE:
			cur_obj_init_animation(DOG_ANIM_IDLE);
			if (yummyball) {
				if (ballDist <= 2000.0f) {
					o->oAction = DF4_WOOF;
				}
			}
			break;
		case DF4_WOOF:
			play_sound(SOUND_CUSTOM_2639BARK, gGlobalSoundSource);
			o->oAction = DF4_APPROACH;
			break;
		case DF4_APPROACH:
			if (yummyball) {
				obj_turn_toward_object(o, yummyball, 16, 0xC00);
				cur_obj_init_animation(DOG_ANIM_RUN);
				o->oForwardVel = 50.0f;
				if (ballDist <= 100) {
					yummyball->oAction = 3;
					o->oAction = DF4_HIT;
				}
			} else {
				o->oAction = DF4_HIT;
			}
			break;
		case DF4_HIT:
			o->oPosX = approach_f32(o->oPosX, o->oHomeX, DOG_SNAP_SPEED, DOG_SNAP_SPEED);
	        o->oPosY = approach_f32(o->oPosY, o->oHomeY, DOG_SNAP_SPEED, DOG_SNAP_SPEED);
	        o->oPosZ = approach_f32(o->oPosZ, o->oHomeZ, DOG_SNAP_SPEED, DOG_SNAP_SPEED);

	        #define DOGGY_DELTA 30.0f
	        if ((o->oPosX - o->oHomeX < DOGGY_DELTA)
	         && (o->oPosY - o->oHomeY < DOGGY_DELTA)
	         && (o->oPosZ - o->oHomeZ < DOGGY_DELTA)
	        ) {
	        	vec3f_copy(&o->oPosX, &o->oHomeX);
	        	o->oAction = DF4_IDLE;
	        	o->oForwardVel = 0;
	        }
	}
}

