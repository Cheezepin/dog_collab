#include "game/behaviors/thecozies_helpers.h"

#define EXTRUDE_FB_AMT (-25.0f/2.0f)
#define FLIPPY_DEG_MAX (DEGREES(-88))

#define FLIPPY_VEL (DEGREES(-0.552231377f)) // atan(4/415)
#define FLIPPY_TERMINAL_VEL (DEGREES(-10.2440874f)) // atan(70/415)

#define FLIPPY_RESPAWN_TIME (2*30) // 2s

#define FLIPPY_NO_COLLIDE_THRESHOLD DEGREES(-55)

enum FlippyBitchActions {
    FLIPPY_BITCH_WAIT,
    FLIPPY_BITCH_FLIPPIN,
    FLIPPY_BITCH_FLIPPED,
};


void flippy_bitch_init(void) {
    // needs to be moved away from the wall for the flip origin to work
    f32 x = sins(gCurrentObject->header.gfx.angle[1]);
    f32 z = coss(gCurrentObject->header.gfx.angle[1]);
    o->oPosX += EXTRUDE_FB_AMT * x;
    o->oPosZ += EXTRUDE_FB_AMT * z;
}



void flippy_bitch_wait(struct Object *obj) {
    if (obj->oSubAction == 0 && check_mario_on_object(gMarioState)) {
        obj->oSubAction = 1;
        obj->oTimer = 0;
        if (gMarioState->action == ACT_GROUND_POUND_LAND) {
            obj->oAngleVelPitch = FLIPPY_TERMINAL_VEL * 2.0f;
            cur_obj_change_action(FLIPPY_BITCH_FLIPPIN);
            obj->oSubAction = 1;
            return;
        }
    }


    switch (obj->oSubAction) {
        case 0:
        default:
            obj->oAngleVelPitch = 0;
            return;
        case 1:
            obj->oAngleVelPitch += (FLIPPY_VEL/2);
            obj->oFaceAnglePitch += obj->oAngleVelPitch;

            if (obj->oFaceAnglePitch < DEGREES(-5)) {
                obj->oAngleVelPitch = -obj->oAngleVelPitch;
                obj->oFaceAnglePitch += obj->oAngleVelPitch;
                obj->oSubAction = 2;
                cur_obj_play_sound_2(SOUND_GENERAL_COZIES_FLIPPER_CLICK);
            }
            break;
        case 2:
            obj->oAngleVelPitch += (FLIPPY_VEL/3);
            obj->oFaceAnglePitch += obj->oAngleVelPitch;
            if (obj->oFaceAnglePitch > 0) {
                obj->oSubAction = 3;
            }
            break;
        case 3:
            obj->oAngleVelPitch += (FLIPPY_VEL/4);
            obj->oFaceAnglePitch += obj->oAngleVelPitch;
            if (obj->oFaceAnglePitch < 0) {
                cur_obj_change_action(FLIPPY_BITCH_FLIPPIN);
            }
            if (obj->oTimer > 20) {
            }
            break;
    }
}

extern Vec3f sMarioAmountDisplaced;

void flippy_bitch_flippin(struct Object *obj) {
    obj->oAngleVelPitch += FLIPPY_VEL;
    if (obj->oAngleVelPitch < FLIPPY_TERMINAL_VEL) obj->oAngleVelPitch = approach_angle(obj->oAngleVelPitch, FLIPPY_TERMINAL_VEL, ABS(FLIPPY_VEL));


    obj->oFaceAnglePitch += obj->oAngleVelPitch;

    if (obj->oFaceAnglePitch < FLIPPY_NO_COLLIDE_THRESHOLD && check_mario_on_object(gMarioState)) {
        // ACT_BEGIN_SLIDING
        set_mario_action(gMarioState, ACT_FREEFALL, 0);
        f32 displaceAmt = obj->oSubAction == 1 ? -20.0f : -100.0f;
        gMarioState->vel[0] = displaceAmt * sins(obj->oFaceAngleYaw);
        // gMarioState->vel[1] = -4;
        gMarioState->vel[2] = displaceAmt * coss(obj->oFaceAngleYaw);

        gMarioState->pos[0] += gMarioState->vel[0];
        // gMarioState->pos[1] += 5.0f;
        gMarioState->pos[2] += gMarioState->vel[2];
        vec3_zero(sMarioAmountDisplaced);
    } else if (
        obj->oSubAction == 1
        && obj->oFaceAnglePitch > DEGREES(-5)
        && obj->oAngleVelPitch > 0
        && check_mario_on_object(gMarioState)
    ) {
        set_mario_action(gMarioState, ACT_TRIPLE_JUMP, 1);
        gMarioState->vel[1] = 42.0f;
    }

    if (obj->oFaceAnglePitch < FLIPPY_DEG_MAX) {
        // TODO: Play clink sound
        cur_obj_play_sound_2(SOUND_ACTION_METAL_BONK);
        if (abs_angle_diff(obj->oAngleVelPitch, FLIPPY_VEL) < (100*4)) {
            obj->oFaceAnglePitch = FLIPPY_DEG_MAX;
            cur_obj_change_action(FLIPPY_BITCH_FLIPPED);
            return;
        }
        s16 bonus = abs_angle_diff(FLIPPY_DEG_MAX, obj->oFaceAnglePitch);
        obj->oFaceAnglePitch = FLIPPY_DEG_MAX + bonus;
        obj->oAngleVelPitch *= -0.66f;
        // if (abs(obj->oAngleVelPitch) > abs(FLIPPY_VEL)) {
        //     obj->oAngleVelPitch *= -0.8f;
        // } else {
        //     obj->oAngleVelPitch = 0;
        //     cur_obj_change_action(FLIPPY_BITCH_FLIPPED);
        // }
    }
    // if (obj->oTimer > 60 && abs_angle_diff(obj->oFaceAnglePitch, FLIPPY_DEG_MAX) < DEGREES(1)) {
    //     obj->oFaceAnglePitch = FLIPPY_DEG_MAX;
    //     cur_obj_change_action(FLIPPY_BITCH_FLIPPED);
    // }
}
void flippy_bitch_flipped(struct Object *obj) {
    if (obj->oTimer < FLIPPY_RESPAWN_TIME) return;

    obj->oAngleVelPitch += -FLIPPY_VEL;
    if (obj->oAngleVelPitch > -FLIPPY_TERMINAL_VEL) obj->oAngleVelPitch = -FLIPPY_TERMINAL_VEL;

    obj->oFaceAnglePitch += obj->oAngleVelPitch;
    if (obj->oFaceAnglePitch > 0) {
        obj->oFaceAnglePitch = 0;
        obj->oAngleVelPitch = 0;
        cur_obj_play_sound_2(SOUND_GENERAL_COZIES_FLIPPER_CLICK);
        cur_obj_change_action(FLIPPY_BITCH_WAIT);
    }
}

void flippy_bitch_loop(void) {
    // if (o->oAction != FLIPPY_BITCH_WAIT) print_text_fmt_int(20, 20, "%d", o->header.gfx.angle[1]);
    switch (o->oAction) {
        case FLIPPY_BITCH_WAIT:
        default:
            flippy_bitch_wait(o);
            break;
        case FLIPPY_BITCH_FLIPPIN:
            flippy_bitch_flippin(o);
            break;
        case FLIPPY_BITCH_FLIPPED:
            flippy_bitch_flipped(o);
            break;
    }

    if (o->oFaceAnglePitch > FLIPPY_NO_COLLIDE_THRESHOLD && o->oDistanceToMario < o->oCollisionDistance) {
        load_object_collision_model();
    }
}

Vec3f fbLightDir  = {  0.0f, 127.0f, 0.0f };
#define FB_LIGHT_DIR_EXTENT 0.2f
Gfx *geo_flippy_bitch_static_rot(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    Gfx *dlStart, *dlHead;
    dlStart = NULL;
    static u32 didIt = 0; 

    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (currentGraphNode->parameter != 0) SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, currentGraphNode->parameter);



        // dlStart = alloc_display_list(sizeof(Gfx) * 2);
        // dlHead = dlStart;

        ((struct GraphNodeTranslationRotation *) node->next)->rotation[0] = -(obj->oFaceAnglePitch);
        // f32 x = sins(obj->oFaceAngleYaw);
        // f32 z = coss(obj->oFaceAngleYaw);
        // fbLightDir[0] = 0;
        // fbLightDir[1] = 1.0f;
        // fbLightDir[2] = 0;
        // vec3f_normalize(fbLightDir);
        // vec3_mul_val(fbLightDir, 127.0f);

        if (didIt != gGlobalTimer) {
            Lights1 *lights;
            Lights1 *lights2;
            if (gCurrLevelNum == LEVEL_DDD) {
                lights = segmented_to_virtual(&flippy_bitch_metalgrateside_layer1_lights);
                lights2 = segmented_to_virtual(&flippy_bitch_gratolite_layer4_lights);
            } else {
                lights = segmented_to_virtual(&flippy_bitch_pss_metalgrateside_layer1_lights);
                lights2 = segmented_to_virtual(&flippy_bitch_pss_gratolite_layer4_lights);
            }
            lights->l->l.dir[0] = ((s8)(fbLightDir[1] * (*viewMat)[1][0]));
            lights->l->l.dir[1] = ((s8)(fbLightDir[1] * (*viewMat)[1][1]));
            lights->l->l.dir[2] = ((s8)(fbLightDir[1] * (*viewMat)[1][2]));

            lights2->l->l.dir[0] = lights->l->l.dir[0];
            lights2->l->l.dir[1] = lights->l->l.dir[1];
            lights2->l->l.dir[2] = lights->l->l.dir[2];
            didIt = gGlobalTimer;
        }

        // if (obj->oWaterSwitchActivated) {
        //     gDPSetEnvColor(dlHead++, 255, 123*1.25f, 10*1.25f, 255);
        // } else {
        //     gDPSetEnvColor(dlHead++, 255*(2.0f/3.0f), 123*(2.0f/3.0f), 10*(2.0f/3.0f), 255);
        // }
        // gSPEndDisplayList(dlHead);
    }

    return dlStart;
}
