// water top

#ifndef o
#include "types.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "game/object_list_processor.h"
#include "engine/math_util.h"
#endif

#include "levels/ddd/header.h"

f32 water_top_cumulative_y(Waters *frames, s32 group, s32 frame) {
    f32 cum = 0.0f;
    for (s32 i = 5; i >= group; i--) {
        cum += frames[frame][i];
    }
    return cum;
}

#define UP_THRESHOLD -4500.0f
#define DOWN_THRESHOLD -1500.0f
#define CONSIDER_MAX_WATER_TOP -400.0f

#define WATER_GRAVITY 10.0f

#define WATER_FORCE_EXTENT 350.0f

// called from mario_actions_submerged
void set_water_top_force(struct MarioState *m) {
    f32 distFromWaterTop = m->pos[1] - (m->waterLevel - 80.0f);
    f32 waterVel = (f32)(m->waterLevel - m->prevWaterLevel);
    f32 maxdist = waterVel > 0.0f ? UP_THRESHOLD : DOWN_THRESHOLD;
    
    // check if mario is too far from the surface to be affected
    if (distFromWaterTop < maxdist )
    {
        m->waterForce = 0.0f;
        return;
    }
    // check if water level hasn't changed at all
    else if (m->prevWaterLevel == m->waterLevel)
    {
        m->waterForce = approach_f32_asymptotic(m->waterForce, 0.0f, 0.1f);
        return;
    }
    f32 force = distFromWaterTop > CONSIDER_MAX_WATER_TOP
        ? waterVel
        : get_relative_position_between_ranges(
            distFromWaterTop,
            maxdist, CONSIDER_MAX_WATER_TOP,
            0.0f, waterVel
        );
    
    if (force > m->waterForce) m->waterForce = approach_f32_asymptotic(m->waterForce, force, 0.8f);
    else if (force > 0) m->waterForce = approach_f32_asymptotic(m->waterForce, force, 0.1f);
    else m->waterForce = approach_f32_symmetric(m->waterForce, force, WATER_GRAVITY);
    m->waterForce = MIN_MAX(m->waterForce, -WATER_FORCE_EXTENT, WATER_FORCE_EXTENT);
}

void water_top_loop(void) {
    Waters *frames = segmented_to_virtual(water_top_frames);
    o->oAction = o->oAction >= WATER_TOP_NUM_FRAMES ? 0 : o->oAction + 1;
    s32 frame = o->oAction;

    s16 *collisionData = o->collisionData;
    s16 *vertices;

    collisionData++;
    s32 numVertices = *collisionData;
    collisionData++;

    vertices = collisionData;

    s32 group = 0;
    s32 left = 1;
    s32 i = 0;
    while (numVertices-- && group < 6) {
        vertices[i+1] = water_top_cumulative_y(frames, group, frame);
        i += 3;

        if (--left == 0) {
            left = 10;
            group++;
        }
    }
}

#define WATER_SPOUT_RADIUS 210
#define WATER_SPOUT_ACCEL 32.0f
#define WATER_SPOUT_STEP 3.0f
void water_spout_loop(void) {
    Bool32 marioIsInSpout =
        gMarioState->action & ACT_FLAG_SWIMMING
        && gMarioState->water
        && gMarioState->water->object == o;

    if (!marioIsInSpout) return;

    gMarioState->waterForce = approach_f32_symmetric(gMarioState->waterForce, WATER_SPOUT_ACCEL, WATER_SPOUT_STEP);


    // Keep mario towards center
    gMarioState->pos[0] = approach_f32_asymptotic(gMarioState->pos[0], o->oPosX, 0.2f);
    gMarioState->pos[2] = approach_f32_asymptotic(gMarioState->pos[2], o->oPosZ, 0.2f);
}
