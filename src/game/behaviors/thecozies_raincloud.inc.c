#include "thecozies_helpers.h"

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
    ddd_area_3_spline_CloudPath4_STAR,
    ddd_area_2_spline_CloudInTheHolePath,
};

#define RAIN_CLOUD_WAYPOINT_FOLLOW_SPEED 0.016f
#define RAIN_CLOUD_WAYPOINT_BAND_SPEED_DOWN 0.015f
#define RAIN_CLOUD_WAYPOINT_BAND_SPEED_UP   0.015f

#define RAIN_CLOUD_WAYPOINT_BAND_SPEED 0.025f
#define RAIN_CLOUD_WAYPOINT_BAND_SPEED_DAMP 0.95f

void set_rain_cloud_waypoints(struct Waypoint *startWaypoint, struct Waypoint **prevWaypoint, struct Waypoint **nextWaypoint) {
    *prevWaypoint = (startWaypoint + o->oRainCloudWaypointIndex);
    *nextWaypoint = (startWaypoint + o->oRainCloudNextWaypointIndex);   
}

void rain_cloud_follow_trajectory(int mario_on_cloud) {
    int continuous = ((o->oBehParams >> 8) & 0xFF) == 1;
    struct Waypoint *startWaypoint = o->oRainCloudWaypoint;

    struct Waypoint *prevWaypoint;
    struct Waypoint *nextWaypoint;
    o->oRainCloudActiveMix = approach_f32_asymptotic(
        o->oRainCloudActiveMix,
        mario_on_cloud != FALSE,
        0.25f
    );

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

    spring_towards(
        &o->oPosX,
        &o->oVelX,
        o->oHomeX,
        RAIN_CLOUD_WAYPOINT_BAND_SPEED,
        RAIN_CLOUD_WAYPOINT_BAND_SPEED_DAMP
    );
    spring_towards(
        &o->oPosZ,
        &o->oVelZ,
        o->oHomeZ,
        RAIN_CLOUD_WAYPOINT_BAND_SPEED,
        RAIN_CLOUD_WAYPOINT_BAND_SPEED_DAMP
    );
    // elastic_approach(&o->oPosX, &o->oVelX, o->oHomeX, RAIN_CLOUD_WAYPOINT_BAND_SPEED_DOWN, RAIN_CLOUD_WAYPOINT_BAND_SPEED_UP);
    // elastic_approach(&o->oPosZ, &o->oVelZ, o->oHomeZ, RAIN_CLOUD_WAYPOINT_BAND_SPEED_DOWN, RAIN_CLOUD_WAYPOINT_BAND_SPEED_UP);
}

void add_rain_cloud_jump_bonus(f32 cloudAffect) {
    f32 bonus = cloudAffect * RAIN_CLOUD_SNAP_STRENGTH_UP;
    f32 total_extra = bonus + MAX(o->oRainCloudPreservedMomentum, 0.0f);
    if (gMarioState->action == ACT_LONG_JUMP) total_extra *= 0.5f;
    gMarioState->vel[1] += total_extra;
    o->oRainCloudMarioIsStandingOnCloud = FALSE;
}

void check_room_and_scale(void) {
    s32 enableRender = FALSE;
    if (o->oRainCloudRoom != -1 && gMarioCurrentRoom != 0) {
        enableRender = (
            gMarioCurrentRoom == o->oRainCloudRoom
            || gDoorAdjacentRooms[gMarioCurrentRoom][0] == o->oRainCloudRoom
            || gDoorAdjacentRooms[gMarioCurrentRoom][1] == o->oRainCloudRoom
        );
    } else {
        o->oDrawingDistance = 32000.0f;
        enableRender = o->oDistanceToMario < 8000.0f;
    }

    if (enableRender) {
        f32 goalScale = 1.0f + ((f32)(BPARAM2) * 0.01f);
        o->header.gfx.scale[2] = o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], goalScale, 0.1f);
        cur_obj_enable_rendering();
        cur_obj_unhide();
        o->activeFlags &= ~ACTIVE_FLAG_IN_DIFFERENT_ROOM;
        gNumRoomedObjectsInMarioRoom++;
        o->oRainCloudMarioInRoom = TRUE;
        return;
    } else if (o->oRainCloudMarioInRoom) {
        o->header.gfx.scale[2] = o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 0, 0.1f);
        if (o->header.gfx.scale[0] < 0.02f) {
            o->oRainCloudMarioInRoom = FALSE;
            spawn_mist_particles_variable(1, 0, 5.0f);
            cur_obj_hide();
            cur_obj_disable_rendering();
            o->activeFlags |= ACTIVE_FLAG_IN_DIFFERENT_ROOM;
            gNumRoomedObjectsNotInMarioRoom++;
        }
    } else {
        o->header.gfx.scale[2] = o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 0.01f, 0.1f);
        cur_obj_disable_rendering();
        o->activeFlags |= ACTIVE_FLAG_IN_DIFFERENT_ROOM;
        gNumRoomedObjectsNotInMarioRoom++;
        cur_obj_hide();
    }
}

void rain_cloud_loop(void) {
    int hasSpline = (BPARAM1);
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
    
    check_room_and_scale();

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

    if (gMarioState->vel[1] > 0.0f && gMarioState->pos[1] < o->oPosY + (138.0f*o->header.gfx.scale[1])) {
        o->activeFlags |= ACTIVE_FLAG_IN_DIFFERENT_ROOM;
    }

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
    else if (o->parentObj && o->parentObj != o) {
        o->oForwardVel = (f32)((s8)(GET_BPARAM3(o->parentObj->oBehParams)));
        s16 mvdir;
        vec3f_get_yaw(&o->parentObj->oPosX, &o->oPosX, &mvdir);
        mvdir += DEGREES(90);
        f32 dist = GET_BPARAM2(o->parentObj->oBehParams) * 100.0f;
        o->oHomeX += (o->oForwardVel * sins(mvdir));
        o->oHomeZ += (o->oForwardVel * coss(mvdir));
        s16 dirToMe;
        vec3f_get_yaw(&o->parentObj->oPosX, &o->oHomeX, &dirToMe);
        o->oPosX = o->oHomeX = o->parentObj->oPosX + (dist * sins(dirToMe));
        o->oPosZ = o->oHomeZ = o->parentObj->oPosZ + (dist * coss(dirToMe));
    }
}

void rain_cloud_init(void) {
    o->oRainCloudScaleVel = 0.0f;
    o->oVelY = 0.0f;
    o->oRainCloudPreservedMomentum = 0.0f;
    o->oOpacity = 0;
    f32 scale = 1.0f + ((f32)(BPARAM2) * 0.01f);
    vec3_same(o->header.gfx.scale, scale);

    int hasSpline = (BPARAM1);
    if (hasSpline) o->oRainCloudWaypoint = segmented_to_virtual(ddd_trajectories[hasSpline - 1]);
    o->oRainCloudWaypointIndex = 0;
    o->oRainCloudNextWaypointIndex = 1;

    // if (BPARAM4 > 0) {
    //     o->oRoom = BPARAM4;
    // } else {
    // }
    // bhv_init_room();

    struct Surface *floor = NULL;
    if (gCurrentArea->surfaceRooms != NULL) {

        find_room_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);

        if (floor != NULL) {
            o->oRainCloudRoom = floor->room;
            return;
        }
    }
    o->oRainCloudRoom = -1;
}


Gfx *geo_set_rain_cloud_wind_vis(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *cloudObj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeDisplayList *nextNode = (struct GraphNodeDisplayList *) node->next;

        s32 hasSpline = GET_BPARAM1(cloudObj->oBehParams);
        COND_BIT(
            hasSpline,
            nextNode->node.flags,
            GRAPH_RENDER_ACTIVE
        );
    }

    return NULL;
}


// #define RAIN_CLOUD_PLOD_FRAC_MIN 150
#define RAIN_CLOUD_PLOD_FRAC_MIN 150
#define RAIN_CLOUD_PLOD_FRAC_MAX 200
// #define RAIN_CLOUD_PLOD_FRAC_MAX 255
#define RAIN_CLOUD_SPLINE_PLOD_FRAC_MIN 140
#define RAIN_CLOUD_SPLINE_PLOD_FRAC_MAX 180
Gfx *geo_set_rain_cloud_prim(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    Gfx *dlStart, *dlHead;
    struct Object *cloudObj;
    struct GraphNodeGenerated *currentGraphNode;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        cloudObj = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_OPAQUE);
        s32 hasSpline = GET_BPARAM1(cloudObj->oBehParams);

        if (hasSpline) {
            // get cycle and map to [0, 1] 
            f32 cyc        = get_lerp(get_cycle(1.50f, 0.0f, gGlobalTimer), -1, 1);
            f32 cycOnCloud = get_lerp(get_cycle(0.75f, 0.0f, gGlobalTimer), -1, 1);
            cyc = (lerp(cyc, cycOnCloud, cloudObj->oRainCloudActiveMix));

            u16 primLodFrac = lroundf(lerp(RAIN_CLOUD_SPLINE_PLOD_FRAC_MIN, RAIN_CLOUD_SPLINE_PLOD_FRAC_MAX, cyc));
            cyc = lerp(1.0f, 0.5f, cyc); // flip so we're going from blown out to blue
            s32 pr = lerp(111, 100, cloudObj->oRainCloudActiveMix * cyc);
            s32 pg = lerp(115, 103, cloudObj->oRainCloudActiveMix * cyc);
            s32 pb = lerp(122, 254, cloudObj->oRainCloudActiveMix * cyc);

            primLodFrac = CLAMP(primLodFrac, RAIN_CLOUD_SPLINE_PLOD_FRAC_MIN, RAIN_CLOUD_PLOD_FRAC_MAX);
            gDPSetPrimColor(dlHead++, 0, primLodFrac, pr, pg, pb, RAIN_CLOUD_PLOD_FRAC_MAX);
        } else {
            gDPSetPrimColor(dlHead++, 0, RAIN_CLOUD_PLOD_FRAC_MIN, 111, 115, 122, 255);
        }
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}
