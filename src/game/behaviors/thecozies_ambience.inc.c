#include "thecozies_helpers.h"

s32 cozies_ambient_sounds[] = {
    SOUND_ENV_WATERFALL2,
    SOUND_ENV_DRONING2,
};


void cozies_ambient_sound_loop(void) {
    s32 sound = cozies_ambient_sounds[BPARAM2];
    vec3f_copy(&o->oHomeX, o->header.gfx.cameraToObject);
    switch (BPARAM2) {
        case 0: {
            vec3f_copy(&o->oHomeX, o->header.gfx.cameraToObject);
            if (gLakituState.pos[0] < 2228) {
                f32 fac = smooth_fac(get_lerp(gLakituState.pos[0], -30000, 2228));
                fac = (fac * 0.5f) + 0.5f;
                approach_vec3f_asymptotic(&o->oHomeX, gVec3fZero, fac, fac, fac);
            } else {
                vec3f_copy(&o->oHomeX, gVec3fZero);
            }

        }
    }

    play_sound(cozies_ambient_sounds[BPARAM2], &o->oHomeX);
}
