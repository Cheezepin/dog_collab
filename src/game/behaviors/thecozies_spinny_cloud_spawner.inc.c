#include "game/behaviors/thecozies_helpers.h"

#define SPINNY_CLOUD_SPAWNER_NUM_CLOUDS BPARAM1
#define SPINNY_CLOUD_SPAWNER_RADIUS     BPARAM2
#define SPINNY_CLOUD_SPAWNER_SPEED      BPARAM3
#define SPINNY_CLOUD_SPAWNER_CLOUD_SIZE BPARAM4

void spinny_cloud_spawner_init(void) {
    s32 numClouds = SPINNY_CLOUD_SPAWNER_NUM_CLOUDS;
    f32 dist = SPINNY_CLOUD_SPAWNER_RADIUS * 100.0f;
    s32 size = SPINNY_CLOUD_SPAWNER_CLOUD_SIZE;
    s32 angleInc = roundf(((f32)DEGREES(360.0f)) / numClouds);
    struct Object *cloud = NULL;
    for (s32 i = 0; i < numClouds; i++) {
        cloud = spawn_object_relative(size, dist, 0, 0, o, MODEL_RAIN_CLOUD, bhvRainCloud);
        cloud->oBehParams |= i;
        o->oFaceAngleYaw += angleInc;
    }
}

void spinny_cloud_spawner_loop(void) {

}
