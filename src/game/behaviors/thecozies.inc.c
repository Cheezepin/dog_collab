// water top

#ifndef o
#include "types.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "game/object_list_processor.h"
#include "engine/math_util.h"
#endif

#include "levels/ddd/header.h"

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

void elastic_approach(f32 *cur, f32 *curVel, f32 goal, f32 speedDown, f32 speedUp) {
    f32 diff = goal - *cur;
    *curVel = approach_f32_asymptotic(*curVel, diff, *cur < goal ? speedUp : speedDown);
    *cur = *cur + *curVel;
}

void audio_meter_approach(f32 *cur, f32 next, f32 reduction, s32 timeout, s32 *momentumTimer) {
    if (next > *cur) {
        *cur = next;
        *momentumTimer = timeout;
    }
    else if (*momentumTimer > 0) *momentumTimer = *momentumTimer - 1;
    else *cur = approach_f32_symmetric(*cur, next, reduction);
}

#define RAIN_CLOUD_BASE_SCALE o->header.gfx.scale[0]

#define RAIN_CLOUD_MARIO_WEIGHT 120.0f
#define RAIN_CLOUD_SNAP_STRENGTH_UP   0.11f
#define RAIN_CLOUD_SNAP_STRENGTH_DOWN 0.085f

#define RAIN_CLOUD_SQUASH_SCALE 0.85f
#define RAIN_CLOUD_SQUASH_AMOUNT 0.2f
#define RAIN_CLOUD_SNAP_STRENGTH_SCALE_UP 0.085f
#define RAIN_CLOUD_SNAP_STRENGTH_SCALE_DOWN 0.065f

#define RAIN_CLOUD_MAX_SIZE (1.0f + (255.0f * 0.01f))
#define RAIN_CLOUD_BASE_WEIGHT (20.0f)
#define RAIN_CLOUD_WEIGHT (RAIN_CLOUD_BASE_SCALE * RAIN_CLOUD_BASE_WEIGHT)
#define RAIN_CLOUD_GET_MARIO_AFFECT() (RAIN_CLOUD_MARIO_WEIGHT - RAIN_CLOUD_WEIGHT)
#define RAIN_CLOUD_GET_MARIO_SQUISH_AFFECT() (1.0f - (RAIN_CLOUD_SQUASH_AMOUNT * (RAIN_CLOUD_GET_MARIO_AFFECT() / RAIN_CLOUD_MARIO_WEIGHT)))

#define RAIN_CLOUD_PRESERVED_MOMENTUM_TIMEOUT 18
#define RAIN_CLOUD_GROUND_POUND_EXTRA_FORCE 50.0f

void add_rain_cloud_jump_bonus(f32 cloudAffect) {
    f32 bonus = cloudAffect * RAIN_CLOUD_SNAP_STRENGTH_UP;
    f32 total_extra = bonus + MAX(o->oRainCloudPreservedMomentum, 0.0f);
    gMarioState->pos[1] += total_extra;
    gMarioState->vel[1] += total_extra;
    o->oRainCloudMarioIsStandingOnCloud = FALSE;
}

void rain_cloud_loop(void) {
    int moving_or_standing = (gMarioState->action & ACT_GROUP_MASK) <= ACT_GROUP_MOVING;
    int mario_on_cloud =
        gMarioObject->platform == o &&
        (
            moving_or_standing ||
            gMarioState->action == ACT_LEDGE_GRAB ||
            (
                gMarioState->action >= ACT_LEDGE_CLIMB_SLOW_1 &&
                gMarioState->action <= ACT_LEDGE_CLIMB_FAST
            )
        );

    f32 cloudAffect = RAIN_CLOUD_GET_MARIO_AFFECT();

    // extra oomph after jump
    if (o->oRainCloudMarioIsStandingOnCloud && (gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_AIRBORNE) {
        // BROKEN WORKAROUND FOR ROLLOUT WEIRDNESS: DELETE IF ROLLOUTS CAN BE FIXED
        // if (gMarioState->action == ACT_FORWARD_ROLLOUT || gMarioState->action == ACT_BACKWARD_ROLLOUT) {
        //     // rollouts set velocity during the first frame so we have to wait :pensive:
        //     if (gMarioState->actionState > 1 && gMarioState->vel[1] <= 30.0f)
        //         add_rain_cloud_jump_bonus(cloudAffect);
        // }
        // else
        add_rain_cloud_jump_bonus(cloudAffect);
    }
    else o->oRainCloudMarioIsStandingOnCloud = mario_on_cloud;

    f32 goal = o->oHomeY;
    if (mario_on_cloud) {
        goal -= cloudAffect;
        if (gMarioState->action == ACT_GROUND_POUND_LAND) goal -= RAIN_CLOUD_GROUND_POUND_EXTRA_FORCE;
    }
    elastic_approach(
        &o->oPosY, &o->oVelY, goal,
        RAIN_CLOUD_SNAP_STRENGTH_UP, RAIN_CLOUD_SNAP_STRENGTH_DOWN);
    
    audio_meter_approach(
        &o->oRainCloudPreservedMomentum,
        o->oVelY,
        1.0f,
        RAIN_CLOUD_PRESERVED_MOMENTUM_TIMEOUT,
        &o->oRainCloudPreservedMomentumTimeout
    );

    f32 scaleGoal = RAIN_CLOUD_BASE_SCALE;
    if (mario_on_cloud) scaleGoal *= RAIN_CLOUD_GET_MARIO_SQUISH_AFFECT();
    elastic_approach(
        &o->header.gfx.scale[1], &o->oRainCloudScaleVel, scaleGoal,
        RAIN_CLOUD_SNAP_STRENGTH_SCALE_UP, RAIN_CLOUD_SNAP_STRENGTH_SCALE_DOWN);

    COND_BIT(
        gMarioState->vel[1] > 0.0f && gMarioState->pos[1] < o->oPosY + 180.0f,
        o->activeFlags,
        ACTIVE_FLAG_IN_DIFFERENT_ROOM
    );

    f32 home_diff = o->oHomeY - o->oPosY;
    s32 goalRain = 0;
    if (home_diff <= 0) goalRain = 0;
    else if (home_diff >= cloudAffect) goalRain = 255;
    else {
        goalRain = get_relative_position_between_ranges(
            home_diff,
            0.0f, cloudAffect,
            0.0f, 255.0f
        );
    }
    o->oOpacity = approach_s32(o->oOpacity, goalRain, 14, 4);
}

void rain_cloud_init(void) {
    o->oRainCloudScaleVel = 0.0f;
    o->oVelY = 0.0f;
    o->oRainCloudPreservedMomentum = 0.0f;
    o->oOpacity = 0;
    f32 scale = 1.0f + ((f32)((o->oBehParams >> 16) & 0xFF) * 0.01f);
    vec3_same(o->header.gfx.scale, scale);
}

void vertical_instant_warp_loop(void) {
    int warpDirection = ((o->oBehParams >> 24) & 0xFF) ? 1 : 0;
    
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
