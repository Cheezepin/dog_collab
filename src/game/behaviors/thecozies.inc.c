// water top
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

#define WATER_GRAVITY 10.0f
void set_water_force(struct MarioState *m) {
    f32 distFromWaterTop = m->pos[1] - (m->waterLevel - 80.0f);
    f32 waterVel = (f32)(m->waterLevel - m->prevWaterLevel);
    f32 maxdist = waterVel > 0.0f ? UP_THRESHOLD : DOWN_THRESHOLD;
    if (m->prevWaterLevel == m->waterLevel || distFromWaterTop > 0.0f || distFromWaterTop < maxdist ) {
        m->waterForce = 0.0f;
        return;
    }
    f32 force = get_relative_position_between_ranges(
        distFromWaterTop,
        maxdist, 0.0f,
        0.0f, waterVel
    );
    if (force > m->waterForce) m->waterForce = approach_f32_asymptotic(m->waterForce, force, 0.8f);
    else if (force > 0) m->waterForce = approach_f32_asymptotic(m->waterForce, force, 0.1f);
    else m->waterForce = approach_f32_symmetric(m->waterForce, force, WATER_GRAVITY);
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
        // s16 lastX = vertices[i];
        // s16 lastY = vertices[i+1];
        // s16 lastZ = vertices[i+2];
        vertices[i+1] = water_top_cumulative_y(frames, group, frame);
        // vertices[i+1] = frames[frame][group];
        i += 3;

        if (--left == 0) {
            left = 10;
            group++;
        }
    }

    set_water_force(gMarioState);

    // f32 latDist = lateral_dist_between_objects(o, gMarioObject);
    // s32 marioGroup = (latDist / 5944.0f) * 6;
    // s32 lastFrame = frame == 0 ? WATER_TOP_NUM_FRAMES : frame - 1;

    // f32 curFrameY = water_top_cumulative_y(frames, marioGroup, frame);

    // f32 yDiff = gMarioState->pos[1] - (curFrameY + o->oPosY);
    // if (yDiff < -80.0f && ABS(yDiff) < 2000.0f) {
    //     f32 lastFrameY = water_top_cumulative_y(frames, marioGroup, lastFrame);
    //     f32 aguaVel = curFrameY - lastFrameY;
    //     f32 amt = get_relative_position_between_ranges(ABS(yDiff), 0.0f, 2000.0f, 0.0, 1.0f);
    //     aguaVel = (aguaVel * (1.0f - (amt*amt)));
    //     // aguaVel = MAX(MIN(100.0f, aguaVel), -100.0f);
    //     // aguaVel *= (1.0 - (ABS(yDiff) / 2000.0));
    //     // gMarioState->pos[1] += aguaVel;
    //     // gMarioState->waterForce = approach_f32_asymptotic(gMarioState->waterForce, aguaVel, 0.75f);
    //     gMarioState->waterForce = aguaVel;
    // } else {
    //     gMarioState->waterForce = approach_f32_asymptotic(gMarioState->waterForce, 0.0f, 0.75f);
    // }
}
