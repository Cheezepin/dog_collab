#include "thecozies_helpers.h"


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

#define WATER_SPOUT_PARAM_HOLD_TOP BPARAM1 // just used for tube top
#define WATER_SPOUT_PARAM_SWITCH_REQ BPARAM2 // needs matching switch id

// #define WATER_SPOUT_SNAP_STRENGTH_UP   0.045f
// #define WATER_SPOUT_SNAP_STRENGTH_DOWN 0.035f
#define WATER_SPOUT_MAX_VEL         80.0f
#define WATER_SPOUT_VEL_INC         2.0f
#define WATER_SPOUT_MAX_VEL_DECEL   -70.0f
#define WATER_SPOUT_VEL_DEC         3.0f
#define WATER_SPOUT_SNAP_STRENGTH_DOWN 0.035f



#define FLOATY_ROCK_GRAV 3.0f
#define FLOATY_ROCK_TERMINAL -70.0f
#define FLOATY_ROCK_WATER_DEPTH_STRETCH_BACK 400.0f
#define FLOATY_ROCK_WATER_DEPTH_LIMIT 600.0f
#define FLOATY_ROCK_WATER_ELASTIC_UP 0.015f
#define FLOATY_ROCK_PRESERVED_MOMENTUM_TIMEOUT 18



ALWAYS_INLINE f32 floater_is_tube_top(struct Object *obj) {
    return obj_has_model(obj, MODEL_TUBE_TOP);
}
f32 get_floater_height(struct Object *obj) {
    return floater_is_tube_top(obj) ? 150.0f : FLOATY_ROCK_WATER_DEPTH_LIMIT;
}



void determine_water_spout_height_from_platform(void) {
    s32 marioOnPlatform = gMarioObject->platform == o->oWaterSpoutFloatyRock;

    switch (o->oSubAction) {
        case WATER_SPOUT_AT_BOTTOM: {
            f32 newPos = o->oWaterSpoutBottom + (WATER_SPOUT_BOB_HEIGHT * sins(o->oWaterSpoutBobTimer));
            o->oVelY = approach_f32_asymptotic(o->oVelY, newPos - o->oPosY, 0.2f);
            if (marioOnPlatform) {
                cur_obj_enable_rendering();
                o->oSubAction = WATER_SPOUT_GOING_TO_TOP;
            } else if (floater_is_tube_top(o->oWaterSpoutFloatyRock)) {
                cur_obj_disable_rendering();
            }
            break;
        }
        case WATER_SPOUT_GOING_TO_TOP: {
            f32 floaterHeight = get_floater_height(o->oWaterSpoutFloatyRock);
            f32 maxVel = WATER_SPOUT_PARAM_HOLD_TOP ? WATER_SPOUT_MAX_VEL * 0.5f : WATER_SPOUT_MAX_VEL;
            f32 newVel = approach_f32_symmetric(o->oVelY, maxVel, WATER_SPOUT_VEL_INC);

            f32 overVel = (o->oPosY + newVel) - (o->oWaterSpoutFloatyRock->oPosY + floaterHeight);
            if (overVel > 0) {
                newVel -= overVel;
            }

            o->oVelY = newVel;

            if (!marioOnPlatform) {
                o->oVelY = MIN(10, o->oVelY);
                o->oSubAction = WATER_SPOUT_GOING_TO_BOTTOM;
            }
            if (o->oVelY + o->oPosY > o->oHomeY) o->oSubAction = WATER_SPOUT_AT_TOP;
            break;
        }
        case WATER_SPOUT_AT_TOP: {
            if (WATER_SPOUT_PARAM_HOLD_TOP) {
                elastic_approach(&o->oPosY, &o->oVelY, o->oHomeY, 0.1f, 0.1f);
                if (!marioOnPlatform) {
                    o->oVelY = MIN(10, o->oVelY);
                    o->oSubAction = WATER_SPOUT_GOING_TO_BOTTOM;
                }
            } else {
                o->oVelY = approach_f32_symmetric(o->oVelY, WATER_SPOUT_MAX_VEL_DECEL, WATER_SPOUT_VEL_DEC);
                if (o->oVelY + o->oPosY < o->oHomeY) {
                    o->oSubAction = WATER_SPOUT_GOING_TO_BOTTOM;
                }
            }
            break;
        }
        case WATER_SPOUT_GOING_TO_BOTTOM: {
            f32 maxVelDecel = WATER_SPOUT_PARAM_HOLD_TOP ? WATER_SPOUT_MAX_VEL_DECEL * 0.75f : WATER_SPOUT_MAX_VEL_DECEL;
            o->oVelY = approach_f32_symmetric(o->oVelY, maxVelDecel, WATER_SPOUT_VEL_DEC);
            if (o->oVelY + o->oPosY < o->oWaterSpoutBottom) o->oSubAction = WATER_SPOUT_AT_BOTTOM;
            break;
        }

    }

    o->oPosY += o->oVelY;
}

void water_spout_bobbin(void) {
    o->oWaterSpoutBobTimer += WATER_SPOUT_BOB_INC;
    if (WATER_SPOUT_PARAM_SWITCH_REQ && !(o->oWaterSpoutIsHome && WATER_SPOUT_PARAM_HOLD_TOP)) {
        if (o->oWaterSpoutEndHome < o->oHomeY + 200.0f)
            o->oVelY = approach_f32_symmetric(o->oVelY, 6.0f, 1.0f);
        else
            o->oVelY = approach_f32_symmetric(o->oVelY, 16.0f, 0.8f);

        if (o->oVelY + o->oHomeY > o->oWaterSpoutEndHome) {
            o->oVelY = 0;
            o->oHomeY = o->oWaterSpoutEndHome;
            o->oWaterSpoutIsHome = TRUE;
        }
        else o->oHomeY += o->oVelY;
    }
    if (o->oWaterSpoutFloatyRock) {
        determine_water_spout_height_from_platform();
        return;
    }
    o->oPosY = o->oHomeY + (WATER_SPOUT_BOB_HEIGHT * sins(o->oWaterSpoutBobTimer));
}

void water_spout_init(void) {
    o->oWaterSpoutActive = TRUE;
    o->oWaterSpoutBottom = find_floor(o->oPosX, o->oPosY, o->oPosZ, &o->oFloor) + WATER_SPOUT_MIN_HEIGHT_ABOVE_FLOOR;
    o->oWaterSpoutEndHome = o->oHomeY;
    if (WATER_SPOUT_PARAM_SWITCH_REQ) {
        if (check_my_water_level_is_active()) return;
        o->oWaterSpoutActive = FALSE;
        o->oWaterSpoutBottom -= (WATER_SPOUT_MIN_HEIGHT_ABOVE_FLOOR + 100);
        o->oPosY = o->oWaterSpoutBottom;
        o->oHomeY = o->oWaterSpoutBottom;
        cur_obj_disable_rendering();
    }
}

void water_spout_loop(void) {
    cur_obj_play_sound_1(SOUND_ENV_WATERFALL1);
    if (!o->oWaterSpoutActive) {
        o->oWaterSpoutActive = check_my_water_level_is_active();
        if (!o->oWaterSpoutActive) {
            return;
        }
        cur_obj_enable_rendering();
    }

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


/**
 * Floaty rock and whatnot
 */

s32 check_mario_groundpound_float(void) {
    if (gMarioState->action == ACT_GROUND_POUND && gMarioState->actionState == 0) {
        o->oVelY = -70;
        return TRUE;
    }
    return FALSE;
}

void floaty_rock_init(void) {
    f32 delta = floater_is_tube_top(o) ? 0.0f : 50.0f;
    o->oFloatyRockFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &o->oFloor) + delta;

    f32 colHeight = get_floater_height(o);
    o->oPosY = o->oFloatyRockFloorHeight + colHeight;
}

void add_floaty_rock_jump_bonus(f32 bonus) {
    f32 total_extra = bonus + MAX(o->oFloatyRockPreservedMomentum, 0.0f);
    if (total_extra > gMarioState->vel[1]) {
        total_extra = total_extra - gMarioState->vel[1];
        if (gMarioState->action == ACT_LONG_JUMP) total_extra *= 0.5f;
        gMarioState->vel[1] = MAX(total_extra, gMarioState->vel[1]);
    }
    gMarioState->pos[1] += (total_extra * 2.0f);
    f32 rockTop = get_floater_height(o) + o->oPosY + 50.0f; // 50 is just a buffer
    gMarioState->pos[1] = MAX(gMarioState->pos[1], rockTop);
    o->oFloatyRockMarioIsOnTop = FALSE;
}

// s32 testVarLmao = FALSE;


void floaty_rock_loop(void) {
    struct Surface *water_floor = NULL;

    f32 waterlevel = find_water_floor(o->oPosX, o->oPosY, o->oPosZ, &water_floor);
    s32 marioOnRock = gMarioObject->platform == o;
    f32 colHeight = get_floater_height(o);

    if (!o->oFloatyRockWaterSpout) {
        if (water_floor && water_floor->object) {
            o->oFloatyRockWaterSpout = water_floor->object;
            water_floor->object->oWaterSpoutFloatyRock = o;
            water_floor->object->oPosY = water_floor->object->oWaterSpoutBottom;
            water_floor->object->oVelY = 0;
            water_floor->object->oSubAction = WATER_SPOUT_AT_BOTTOM;
            o->oFloatyRockPrevWaterLevel = waterlevel;
            o->oVelY = 0.0f;
            return;
        } else {
            // normally this should just float on the water but yeah
            o->oPosY = o->oFloatyRockFloorHeight;
            o->oVelY = 0.0f;
            return;
        }
    }

    // TODO: this is a fun idea if you have time
    //       its busted cus you clip through the bottom anyways sadly
    // if (
    //     !marioOnRock
    //     && gMarioState->floor->object == o->oWaterSpoutFloatyRock
    //     && gMarioState->pos[1] - o->oPosY < 60.0f
    //     && check_mario_groundpound_float()
    // ) return;

    f32 targetY = MAX(waterlevel, o->oFloatyRockFloorHeight);
    if (o->oFloatyRockWaterSpout) {
        targetY = MAX(o->oFloatyRockFloorHeight, o->oFloatyRockWaterSpout->oPosY);
    }

    if (targetY > o->oPosY) {
        f32 goalDiff = targetY - o->oPosY;

        f32 fac = smooth_fac(get_lerp(goalDiff, 0, colHeight));
        f32 additionalVel = fac * colHeight;
        o->oVelY = MAX(o->oVelY, additionalVel);
        o->oVelY = MIN(100, o->oVelY);
    } else {
        o->oVelY -= FLOATY_ROCK_GRAV;
    }

    if (o->oVelY < FLOATY_ROCK_TERMINAL) o->oVelY = FLOATY_ROCK_TERMINAL;

    o->oPosY += o->oVelY;

    // if (o->oPosY < targetY - colHeight) {
        // o->oPosY = targetY - colHeight;
    // }

    if (o->oPosY < o->oFloatyRockFloorHeight) {
        if (o->oVelY < -10.0f) cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
        o->oPosY = o->oFloatyRockFloorHeight;
        o->oVelY = MAX(0.0f, (o->oVelY * -0.6f)); // was 0.9
        if (o->oVelY < 4.0f) o->oVelY = 0;
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
        o->oVelY = MIN(11.0f, o->oVelY);
    } else {
        o->oFloatyRockMarioIsOnTop = marioOnRock;
    }

}
