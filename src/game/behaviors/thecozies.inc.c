// water top

#include "game/behaviors/thecozies_helpers.inc.c"

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
    f32 distFromWaterTop = m->pos[1] - (m->waterLevel - 80.0f);
    f32 waterVel = (f32)(m->waterLevel - m->prevWaterLevel);
    f32 maxdist = waterVel > 0.0f ? UP_THRESHOLD : DOWN_THRESHOLD;
    
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
#define WATER_SPOUT_MAX_SPEED 75.0f
#define WATER_SPOUT_STEP 3.0f
#define WATER_SPOUT_FORCE_WAIT 20
#define WATER_SPOUT_FORCE_LERP 800.0f
#define WATER_SPOUT_BOB_HEIGHT 80.0f
#define WATER_SPOUT_BOB_INC 0x400
#define WATER_SPOUT_MIN_HEIGHT_ABOVE_FLOOR 250.0f

enum WATER_SPOUT_STATES {
    WATER_SPOUT_WAITING,
    WATER_SPOUT_HAS_MARIO,
};
enum WATER_SPOUT_PLATFORM_STATES {
    WATER_SPOUT_AT_BOTTOM,
    WATER_SPOUT_GOING_TO_TOP,
    WATER_SPOUT_AT_TOP,
    WATER_SPOUT_GOING_TO_BOTTOM,
};

// #define WATER_SPOUT_SNAP_STRENGTH_UP   0.045f
// #define WATER_SPOUT_SNAP_STRENGTH_DOWN 0.035f
#define WATER_SPOUT_MAX_VEL         100.0f
#define WATER_SPOUT_VEL_INC         2.0f
#define WATER_SPOUT_MAX_VEL_DECEL   -70.0f
#define WATER_SPOUT_VEL_DEC         3.0f
#define WATER_SPOUT_SNAP_STRENGTH_DOWN 0.035f
inline void determine_water_spout_height_from_platform(void) {
    s32 marioOnPlatform = gMarioObject->platform == o->oWaterSpoutFloatyRock;
    switch (o->oSubAction) {
        case WATER_SPOUT_AT_BOTTOM: {
            f32 newPos = o->oWaterSpoutBottom + (WATER_SPOUT_BOB_HEIGHT * sins(o->oWaterSpoutBobTimer));
            o->oVelY = approach_f32_asymptotic(o->oVelY, newPos - o->oPosY, 0.2f);
            if (marioOnPlatform) o->oSubAction = WATER_SPOUT_GOING_TO_TOP;
            break;
        }
        case WATER_SPOUT_GOING_TO_TOP: {
            o->oVelY = approach_f32_symmetric(o->oVelY, WATER_SPOUT_MAX_VEL, WATER_SPOUT_VEL_INC);
            if (o->oVelY + o->oPosY > o->oHomeY) o->oSubAction = WATER_SPOUT_AT_TOP;
            else if (!marioOnPlatform) o->oSubAction = WATER_SPOUT_GOING_TO_BOTTOM;
            break;
        }
        case WATER_SPOUT_AT_TOP: {
            o->oVelY = approach_f32_symmetric(o->oVelY, WATER_SPOUT_MAX_VEL_DECEL, WATER_SPOUT_VEL_DEC);
            if (o->oVelY + o->oPosY < o->oHomeY) o->oSubAction = WATER_SPOUT_GOING_TO_BOTTOM;
            break;
        }
        case WATER_SPOUT_GOING_TO_BOTTOM: {
            o->oVelY = approach_f32_symmetric(o->oVelY, WATER_SPOUT_MAX_VEL_DECEL, WATER_SPOUT_VEL_DEC);
            if (o->oVelY + o->oPosY < o->oWaterSpoutBottom) o->oSubAction = WATER_SPOUT_AT_BOTTOM;
            break;
        }

    }
    
    o->oPosY += o->oVelY;
}

void water_spout_bobbin(void) {
    o->oWaterSpoutBobTimer += WATER_SPOUT_BOB_INC;
    if (o->oWaterSpoutFloatyRock) {
        determine_water_spout_height_from_platform();
        return;
    }
    o->oPosY = o->oHomeY + (WATER_SPOUT_BOB_HEIGHT * sins(o->oWaterSpoutBobTimer));
}

void water_spout_init(void) {
    o->oWaterSpoutBottom = find_floor(o->oPosX, o->oPosY, o->oPosZ, &o->oFloor) + WATER_SPOUT_MIN_HEIGHT_ABOVE_FLOOR;
}

void water_spout_loop(void) {
    cur_obj_play_sound_1(SOUND_ENV_WATERFALL2);
    Bool32 marioIsInSpout =
        gMarioState->action & ACT_FLAG_SWIMMING
        && gMarioState->water
        && gMarioState->water->object == o;

    water_spout_bobbin();

    if (!marioIsInSpout) {
        if (o->oAction == WATER_SPOUT_HAS_MARIO) {
            set_mario_action(gMarioState, ACT_TRIPLE_JUMP, 0);
            gMarioState->vel[1] += (WATER_SPOUT_MAX_SPEED * 0.33f);
            gMarioState->faceAngle[1] = gMarioState->intendedYaw;
        }
        o->oTimer = 0;
        o->oAction = WATER_SPOUT_WAITING;
        return;
    }
    o->oAction = WATER_SPOUT_HAS_MARIO;

    if (o->oTimer++ > WATER_SPOUT_FORCE_WAIT) {
        if (gMarioState->pos[1] > o->oPosY - WATER_SPOUT_FORCE_LERP) {
            f32 minSpeed = get_relative_position_between_ranges(
                o->oPosY - gMarioState->pos[1],
                WATER_SPOUT_FORCE_LERP,
                80.0f,
                0.0f,
                WATER_SPOUT_MAX_SPEED
            );
            gMarioState->waterForce = MAX(gMarioState->waterForce, minSpeed);
        }
        else gMarioState->waterForce = approach_f32_symmetric(gMarioState->waterForce, WATER_SPOUT_MAX_SPEED, WATER_SPOUT_STEP);
    }


    // Keep mario towards center
    gMarioState->pos[0] = approach_f32_asymptotic(gMarioState->pos[0], o->oPosX, 0.2f);
    gMarioState->pos[2] = approach_f32_asymptotic(gMarioState->pos[2], o->oPosZ, 0.2f);
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
#define RAIN_CLOUD_GET_MARIO_AFFECT_SPLINE() ((RAIN_CLOUD_MARIO_WEIGHT - RAIN_CLOUD_WEIGHT) * 0.5f)
#define RAIN_CLOUD_GET_MARIO_SQUISH_AFFECT() (1.0f - (RAIN_CLOUD_SQUASH_AMOUNT * (RAIN_CLOUD_GET_MARIO_AFFECT() / RAIN_CLOUD_MARIO_WEIGHT)))

#define RAIN_CLOUD_PRESERVED_MOMENTUM_TIMEOUT 18
#define RAIN_CLOUD_GROUND_POUND_EXTRA_FORCE 50.0f

const Trajectory *ddd_trajectories[] = {
    ddd_area_3_spline_CloudPath1,
    ddd_area_3_spline_CloudPath2,
    ddd_area_3_spline_CloudPath3_STAR,
    ddd_area_3_spline_CloudPath4_STAR
};

#define RAIN_CLOUD_WAYPOINT_FOLLOW_SPEED 0.01f
#define RAIN_CLOUD_WAYPOINT_BAND_SPEED_DOWN 0.015f
#define RAIN_CLOUD_WAYPOINT_BAND_SPEED_UP   0.015f
void set_rain_cloud_waypoints(struct Waypoint *startWaypoint, struct Waypoint **prevWaypoint, struct Waypoint **nextWaypoint) {
    *prevWaypoint = (startWaypoint + o->oRainCloudWaypointIndex);
    *nextWaypoint = (startWaypoint + o->oRainCloudNextWaypointIndex);   
}

void rain_cloud_follow_trajectory(int mario_on_cloud) {
    int continuous = ((o->oBehParams >> 8) & 0xFF) == 1;
    struct Waypoint *startWaypoint = o->oRainCloudWaypoint;

    struct Waypoint *prevWaypoint;
    struct Waypoint *nextWaypoint;

    f32 lastDir = o->oRainCloudWaypointDirection;
    f32 dir = mario_on_cloud ? 1.0f : -1.0f;
    if (continuous && o->oRainCloudWaypointIndex > 0) dir = 1.0f;
    o->oRainCloudWaypointDirection = approach_f32_symmetric(o->oRainCloudWaypointDirection, dir, 0.03334f);

    o->oRainCloudWaypointProgress += (RAIN_CLOUD_WAYPOINT_FOLLOW_SPEED * o->oRainCloudWaypointDirection);

    if (o->oRainCloudWaypointDirection > 0.0f && o->oRainCloudWaypointProgress > 1.0f) {
        if ((startWaypoint + (o->oRainCloudNextWaypointIndex + 1))->flags == WAYPOINT_FLAGS_END) {
            o->oRainCloudWaypointProgress = 1.0f;
            if (continuous) {
                o->oRainCloudWaypointIndex = 0;
                o->oRainCloudNextWaypointIndex = 1;
                o->oRainCloudWaypointProgress = 0.0f;
                o->oPosX = startWaypoint->pos[0]; 
                o->oPosY = startWaypoint->pos[1]; 
                o->oPosZ = startWaypoint->pos[2];
                vec3_zero(&o->oVelX);
                vec3_copy(&o->oHomeX, &o->oPosX);
                return;
            }
        } else {
            o->oRainCloudWaypointIndex++;
            o->oRainCloudNextWaypointIndex++;
            o->oRainCloudWaypointProgress = 0.0f;
        }
    }
    else if (o->oRainCloudWaypointDirection < 0.0f && o->oRainCloudWaypointProgress < 0.0f) {
        if (o->oRainCloudWaypointIndex - 1 < 0) {
            o->oRainCloudWaypointProgress = 0.0f;
        } else {
            o->oRainCloudWaypointIndex--;
            o->oRainCloudNextWaypointIndex--;
            o->oRainCloudWaypointProgress = 1.0f;
        }
    }
    set_rain_cloud_waypoints(startWaypoint, &prevWaypoint, &nextWaypoint);

    if (o->oRainCloudWaypointProgress == 1.0f) {
        o->oHomeX = nextWaypoint->pos[0];
        o->oHomeY = nextWaypoint->pos[1];
        o->oHomeZ = nextWaypoint->pos[2];
    } else if (o->oRainCloudWaypointProgress == 0.0f) {
        o->oHomeX = prevWaypoint->pos[0];
        o->oHomeY = prevWaypoint->pos[1];
        o->oHomeZ = prevWaypoint->pos[2];
    } else {
        o->oHomeX = approach_f32_asymptotic(prevWaypoint->pos[0], nextWaypoint->pos[0], o->oRainCloudWaypointProgress);
        o->oHomeY = approach_f32_asymptotic(prevWaypoint->pos[1], nextWaypoint->pos[1], o->oRainCloudWaypointProgress);
        o->oHomeZ = approach_f32_asymptotic(prevWaypoint->pos[2], nextWaypoint->pos[2], o->oRainCloudWaypointProgress);
    }
    // int printOffset = (((o->oBehParams >> 24) & 0xFF) - 1) * 50;
    // print_text_fmt_int(20 + printOffset, 120, "%d", o->oRainCloudWaypointIndex);
    // print_text_fmt_int(20 + printOffset, 100, "%d", o->oRainCloudNextWaypointIndex);
    // print_text_fmt_int(20 + printOffset, 40, "%d", (s32)(o->oRainCloudWaypointProgress * 100));
    // print_text_fmt_int(20, 60, "%d", prevWaypoint->pos[1]);
    // print_text_fmt_int(20, 40, "%d", prevWaypoint->pos[2]);
    // print_text_fmt_int(SCREEN_WIDTH - 75, 80, "%d", nextWaypoint->pos[0]);
    // print_text_fmt_int(SCREEN_WIDTH - 75, 60, "%d", nextWaypoint->pos[1]);
    // print_text_fmt_int(SCREEN_WIDTH - 75, 40, "%d", nextWaypoint->pos[2]);

    // o->oPosX = o->oHomeX;
    // o->oPosZ = o->oHomeZ;
    elastic_approach(&o->oPosX, &o->oVelX, o->oHomeX, RAIN_CLOUD_WAYPOINT_BAND_SPEED_DOWN, RAIN_CLOUD_WAYPOINT_BAND_SPEED_UP);
    elastic_approach(&o->oPosZ, &o->oVelZ, o->oHomeZ, RAIN_CLOUD_WAYPOINT_BAND_SPEED_DOWN, RAIN_CLOUD_WAYPOINT_BAND_SPEED_UP);
}

void add_rain_cloud_jump_bonus(f32 cloudAffect) {
    f32 bonus = cloudAffect * RAIN_CLOUD_SNAP_STRENGTH_UP;
    f32 total_extra = bonus + MAX(o->oRainCloudPreservedMomentum, 0.0f);
    if (gMarioState->action == ACT_LONG_JUMP) total_extra *= 0.5f;
    gMarioState->vel[1] += total_extra;
    o->oRainCloudMarioIsStandingOnCloud = FALSE;
}

void rain_cloud_loop(void) {
    int hasSpline = ((o->oBehParams >> 24) & 0xFF);
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

    f32 cloudAffect = hasSpline ? RAIN_CLOUD_GET_MARIO_AFFECT_SPLINE() : RAIN_CLOUD_GET_MARIO_AFFECT();

    // extra oomph after jump
    if (o->oRainCloudMarioIsStandingOnCloud && (gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_AIRBORNE) {
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

    if (hasSpline) rain_cloud_follow_trajectory(gMarioObject->platform == o);
}

void rain_cloud_init(void) {
    o->oRainCloudScaleVel = 0.0f;
    o->oVelY = 0.0f;
    o->oRainCloudPreservedMomentum = 0.0f;
    o->oOpacity = 0;
    f32 scale = 1.0f + ((f32)((o->oBehParams >> 16) & 0xFF) * 0.01f);
    vec3_same(o->header.gfx.scale, scale);

    int hasSpline = ((o->oBehParams >> 24) & 0xFF);
    if (hasSpline) o->oRainCloudWaypoint = segmented_to_virtual(ddd_trajectories[hasSpline - 1]);
    o->oRainCloudWaypointIndex = 0;
    o->oRainCloudNextWaypointIndex = 1;
}

void vertical_instant_warp_loop(void) {
    int warpDirection = ((o->oBehParams >> 24) & 0xFF) ? 1 : 0;
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

void floaty_rock_init(void) {
    o->oFloatyRockFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &o->oFloor) + 50.0f;
}

void add_floaty_rock_jump_bonus(f32 bonus) {
    f32 total_extra = bonus + MAX(o->oFloatyRockPreservedMomentum, 0.0f);
    if (total_extra > gMarioState->vel[1]) {
        total_extra = total_extra - gMarioState->vel[1];
        if (gMarioState->action == ACT_LONG_JUMP) total_extra *= 0.5f;
        gMarioState->vel[1] = MAX(total_extra, gMarioState->vel[1]);
    }
    gMarioState->pos[1] += (total_extra * 2.0f);
    o->oFloatyRockMarioIsOnTop = FALSE;
}

#define FLOATY_ROCK_GRAV 3.0f
#define FLOATY_ROCK_TERMINAL -70.0f
#define FLOATY_ROCK_WATER_DEPTH_STRETCH_BACK 400.0f
#define FLOATY_ROCK_WATER_DEPTH_LIMIT 600.0f
#define FLOATY_ROCK_WATER_ELASTIC_UP 0.015f
#define FLOATY_ROCK_PRESERVED_MOMENTUM_TIMEOUT 18
void floaty_rock_loop(void) {
    struct Surface *water_floor = NULL;
    f32 waterlevel = find_water_floor(o->oPosX, o->oPosY, o->oPosZ, &water_floor);
    s32 marioOnRock = gMarioObject->platform == o;

    if (!o->oFloatyRockWaterSpout && water_floor && water_floor->object) {
        o->oFloatyRockWaterSpout = water_floor->object;
        water_floor->object->oWaterSpoutFloatyRock = o;
        o->oFloatyRockPrevWaterLevel = waterlevel;
        o->oVelY = 0.0f;
    }

    f32 targetY = waterlevel;
    f32 waterVel = waterlevel - o->oFloatyRockPrevWaterLevel;
    if (o->oFloatyRockWaterSpout) {
        targetY = o->oFloatyRockWaterSpout->oPosY;
        waterVel = o->oFloatyRockWaterSpout->oVelY;
    }

    if (targetY > o->oPosY) {
        o->oVelY = approach_f32_asymptotic(o->oVelY, waterVel, 0.1f);
        elastic_approach(
            &o->oPosY, &o->oVelY,
            targetY,
            FLOATY_ROCK_WATER_ELASTIC_UP, FLOATY_ROCK_WATER_ELASTIC_UP);

        // o->oVelY = approach_f32_asymptotic(o->oVelY, waterVel, 0.1f);
        // o->oPosY = MAX(o->oPosY, waterlevel - FLOATY_ROCK_WATER_DEPTH_LIMIT);
        // return;

        // if (gMarioObject->platform == o && o->oVelY + o->oPosY > targetY) o->oVelY += waterVel;
    } else {
        o->oVelY -= FLOATY_ROCK_GRAV;
    }
    if (o->oVelY < FLOATY_ROCK_TERMINAL) o->oVelY = FLOATY_ROCK_TERMINAL;

    o->oPosY += o->oVelY;
    if (targetY - o->oPosY > FLOATY_ROCK_WATER_DEPTH_STRETCH_BACK) {
        o->oVelY += 10.0f;
    }

    if (targetY - o->oPosY > FLOATY_ROCK_WATER_DEPTH_LIMIT) {
        o->oPosY = targetY - FLOATY_ROCK_WATER_DEPTH_LIMIT;
    }
    else if (o->oFloatyRockFloorHeight > o->oPosY) {
        if (o->oVelY < -10.0f) cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
        o->oPosY = o->oFloatyRockFloorHeight;
        o->oVelY = MAX(0.0f, (o->oVelY * -0.9f));
        // TODO: play BOOM sound
    }

    audio_meter_approach(
        &o->oFloatyRockPreservedMomentum,
        o->oVelY,
        1.0f,
        FLOATY_ROCK_PRESERVED_MOMENTUM_TIMEOUT,
        &o->oFloatyRockPreservedMomentumTimeout
    );

    if (o->oFloatyRockMarioIsOnTop && !marioOnRock) {
        add_floaty_rock_jump_bonus(0.0f);
    }

    o->oFloatyRockMarioIsOnTop = marioOnRock;
}

#include "game/behaviors/thecozies_shyguy_scuba.inc.c"
#include "game/behaviors/thecozies_bubble_shell.inc.c"
