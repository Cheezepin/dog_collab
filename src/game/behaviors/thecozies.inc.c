// water top

#include "game/behaviors/thecozies_helpers.inc.c"
#include "game/behaviors/thecozies_raincloud.inc.c"
#include "game/behaviors/thecozies_water_switch.inc.c"
#include "game/behaviors/thecozies_flippy_bitch.inc.c"
#include "game/behaviors/thecozies_room_initializer.inc.c"
#include "game/behaviors/thecozies_waterspout_rock.inc.c"
#include "game/behaviors/thecozies_spinny_cloud_spawner.inc.c"
#include "game/behaviors/thecozies_dog.inc.c"
#include "game/behaviors/thecozies_warp_pad.inc.c"


/**
 * POTENTIAL POLISH
 * - Make fluorescent lighting flicker
 * - Inset fluorescent lighting and cover with semi transparent glass
 */

s16 water_top_cumulative_y(Waters *frames, s32 group, s32 frame) {
    f32 cum = 0.0f;
    for (s32 i = 5; i >= group; i--) {
        cum += frames[frame][i];
    }
    return (s16)cum;
}

#define UP_THRESHOLD -3500.0f
#define DOWN_THRESHOLD -1500.0f
#define CONSIDER_MAX_WATER_TOP -400.0f

#define WATER_GRAVITY 10.0f

#define WATER_FORCE_EXTENT 350.0f

// called from mario_actions_submerged
void set_water_top_force(struct MarioState *m) {
    struct Object *watertop = m->water->object;

    f32 distFromWaterTop = m->pos[1] - (m->waterLevel - 80.0f);
    f32 waterVel = (f32)(m->waterLevel - m->prevWaterLevel);
    f32 maxdist = waterVel > 0.0f ? UP_THRESHOLD : DOWN_THRESHOLD;

    if (TRUE) {
        Vec3f centerPos = {
            watertop->oPosX,
            watertop->oPosY + watertop->oWaterTopY - 80.0f,
            watertop->oPosZ
        };
        f32 dX = centerPos[0] - m->pos[0];
        f32 dY = centerPos[1] - m->pos[1];
        f32 dZ = centerPos[2] - m->pos[2];
        f32 distFromCenterSqr = sqr(dX) + sqr(dY) + sqr(dZ);

        if (distFromCenterSqr < sqr(2000)) {
            f32 fac = smooth_fac(get_lerp(sqrtf(distFromCenterSqr), 2000, 0));
            f32 speed = fac * 0.15f;
            f32 dampen = lerp(1.0f, 0.5f, fac);

            // using dummy because pos will be updated soon enough
            Vec3f posDummy;
            vec3f_copy(posDummy, m->pos);
            spring_towards_vec3f(posDummy, m->vel, centerPos, speed, dampen);
        }
    }

    // check if mario is too far from the surface to be affected
    if (distFromWaterTop < maxdist)
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

struct WaterColVertex
{
    s16 x;
    s16 y;
    s16 z;
};

void water_top_loop(void) {
    Waters *frames = segmented_to_virtual(water_top_frames);
    if (++o->oAction >= WATER_TOP_NUM_FRAMES) o->oAction = 0;

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

    while (numVertices && group < 6) {
        s16 cum = water_top_cumulative_y(frames, group, frame);
        if (group == 0) o->oWaterTopY = (f32)cum;
        while (left-- > 0) {
            struct WaterColVertex *vert = &vertices[i];
            vert->y = cum;
            i += 3;
            numVertices--;
        }
        left = 10;
        group++;
    }
}

void vertical_instant_warp_loop(void) {
    int warpDirection = (BPARAM1) ? 1 : 0;
    int warpLateralDist = (o->oBehParams & 0xFF) * 100;
    if (warpLateralDist) {
        int latDist = lateral_dist_between_objects(o, gMarioObject);
        if (latDist > warpLateralDist) return;
    }
    
    // Warp when mario is below
    if (warpDirection == 0) {
        if (gMarioState->pos[1] < o->oPosY) gInstantWarpObject = o;
    }
    else if (gMarioState->pos[1] > o->oPosY) gInstantWarpObject = o;
}

void aperature_door_loop(void) {
    int closed = gCurrActNum == 1;
    o->header.gfx.animInfo.animFrame = 80;

    // if (closed) load_object_collision_model();
}


#include "game/behaviors/thecozies_shyguy_scuba.inc.c"
#include "game/behaviors/thecozies_bubble_shell.inc.c"
#include "game/behaviors/thecozies_geo_misc.inc.c"
