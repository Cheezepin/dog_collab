#include "types.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "game/object_list_processor.h"
#include "game/rendering_graph_node.h"
#include "engine/math_util.h"
#include "levels/ddd/header.h"

#ifndef THECOZIES_HELPERS_INC_C
#define THECOZIES_HELPERS_INC_C

void elastic_approach(f32 *cur, f32 *curVel, f32 goal, f32 speedDown, f32 speedUp) {
    f32 diff = goal - *cur;
    *curVel = approach_f32_asymptotic(*curVel, diff, *cur < goal ? speedUp : speedDown);
    *cur = *cur + *curVel;
}

s16 approach_dir(s16 curYaw, s16 target, f32 speed) {
    return (s16) (target - approach_f32_asymptotic(
        (s16) (target - curYaw),
        0,
        speed
    ));
}

void elastic_approach_angle(s16 *cur, s16 *curVel, s16 goal, f32 speedDown, f32 speedUp) {
    s16 diff = goal - *cur;
    *curVel = approach_dir(*curVel, diff, *cur < goal ? speedUp : speedDown);
    *cur = *cur + *curVel;
}

void elastic_approach_vec3f(Vec3f cur, Vec3f curVel, Vec3f goal, f32 speedDown, f32 speedUp) {
    elastic_approach(&cur[0], &curVel[0], goal[0], speedDown, speedUp);
    elastic_approach(&cur[1], &curVel[1], goal[1], speedDown, speedUp);
    elastic_approach(&cur[2], &curVel[2], goal[2], speedDown, speedUp);
}

void elastic_approach_vec3s(Vec3s cur, Vec3s curVel, Vec3s goal, f32 speedDown, f32 speedUp) {
    elastic_approach_angle(&cur[0], &curVel[0], goal[0], speedDown, speedUp);
    elastic_approach_angle(&cur[1], &curVel[1], goal[1], speedDown, speedUp);
    elastic_approach_angle(&cur[2], &curVel[2], goal[2], speedDown, speedUp);
}

void audio_meter_approach(f32 *cur, f32 next, f32 reduction, s32 timeout, s32 *momentumTimer) {
    if (next > *cur) {
        *cur = next;
        *momentumTimer = timeout;
    }
    else if (*momentumTimer > 0) *momentumTimer = *momentumTimer - 1;
    else *cur = approach_f32_symmetric(*cur, next, reduction);
}

#endif
