#include "thecozies_helpers.h"


#define WARP_PAD_OPA_MIN_INACTIVE 30
#define WARP_PAD_OPA_MIN_ACTIVE 100
#define WARP_PAD_OPA_MIN_ACTIVE_CLOSE 200
#define WARP_PAD_WARP_OPA_MIN 20
#define WARP_PAD_WARP_OPA_MIN_CLOSE 200

void bhv_cozy_warp_pad_init(void) {
    o->oWarpPadActive = check_min_star_collected((u8)BPARAM2);
    if (o->oWarpPadActive) {
        o->oOpacity = WARP_PAD_OPA_MIN_ACTIVE;
        o->oWarpPadWarpOpa = WARP_PAD_WARP_OPA_MIN;
    } else {
        o->oOpacity = WARP_PAD_OPA_MIN_INACTIVE;
        o->oWarpPadWarpOpa = 0;
    }
}

struct Object *find_next_available_warp_pad(void) {
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvCozyWarpPad);

    struct Object *next = (struct Object *) o->header.prev;

    while (next != o) {
        if (
            next->behavior == behaviorAddr
            && next->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && next->oWarpPadActive
            && next->oWarpPadNext != o
        ) {
            return next;
        }
    
        next = (struct Object *) next->header.prev;
    }

    return NULL;
}

enum WarpPadActions {
    ACT_WARP_PAD_WAITING,
    ACT_WARP_PAD_MARIO_WARPING_OUT,
    ACT_WARP_PAD_MARIO_WARPING_IN,
    ACT_WARP_PAD_WAIT_FOR_MARIO_TO_LEAVE,
};

extern s16 s8DirModeYawOffset;

void bhv_cozy_warp_pad_loop(void) {
    if (!o->oWarpPadNext) {
        o->oWarpPadNext = find_next_available_warp_pad();
        if (o->oWarpPadNext == NULL) {
            return;
        }
    }

    if (!o->oWarpPadActive) {
        return;
    }
    
    struct MarioState *m = gMarioState;
    f32 goalPadOpa = WARP_PAD_OPA_MIN_ACTIVE;
    f32 goalFieldOpa = WARP_PAD_WARP_OPA_MIN;

    switch (o->oAction) {
        default:
        case ACT_WARP_PAD_WAITING: {
            if (o->oDistanceToMario < 1000) {
                f32 fac = smooth_fac(get_lerp(o->oDistanceToMario, 1000, 200));
                goalPadOpa = lerp(WARP_PAD_OPA_MIN_ACTIVE, WARP_PAD_OPA_MIN_ACTIVE_CLOSE, fac);
                goalFieldOpa = lerp(WARP_PAD_WARP_OPA_MIN, WARP_PAD_WARP_OPA_MIN_CLOSE, fac);
            }
            if (
                check_mario_on_object(m)
                || (
                    (m->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED
                    && m->floor->object == o
                    && m->pos[1] < o->oPosY + 180.0f
                )
            ) {
                cur_obj_change_action(ACT_WARP_PAD_MARIO_WARPING_OUT);
                Vec3f nextPos;
                vec3f_copy(nextPos, &o->oWarpPadNext->oPosX);
                nextPos[1] += 120.0f;
                manual_set_checkpoint(m, nextPos, o->oWarpPadNext->oFaceAngleYaw);
                set_mario_action(m, ACT_FLOOR_CHECKPOINT_WARP_OUT, 0);
                set_mario_animation(m, MARIO_ANIM_GENERAL_FALL);
                cur_obj_play_sound_2(SOUND_ACTION_TELEPORT);
            }
            break;
        }
        case ACT_WARP_PAD_MARIO_WARPING_OUT: {
            goalPadOpa = goalFieldOpa = 255;

            if (m->action != ACT_FLOOR_CHECKPOINT_WARP_OUT) {
                cur_obj_change_action(ACT_WARP_PAD_WAITING);
                o->oWarpPadNext->oTimer = 0;
                o->oWarpPadNext->oSubAction = 0;
                o->oWarpPadNext->oAction = ACT_WARP_PAD_MARIO_WARPING_IN;
                o->oWarpPadNext->oPrevAction = ACT_WARP_PAD_MARIO_WARPING_IN;
                m->area->camera->yaw = s8DirModeYawOffset = o->oWarpPadNext->oFaceAngleYaw;
                play_sound(SOUND_ACTION_TELEPORT, o->oWarpPadNext->header.gfx.cameraToObject);
            } else {
                Vec3f nextPos;
                vec3f_copy(nextPos, &o->oPosX);
                nextPos[1] += 120.0f;
                spring_towards_vec3f(m->pos, m->vel, nextPos, 0.1f, 0.97f);
            }
            break;
        }
        case ACT_WARP_PAD_MARIO_WARPING_IN: {
            goalPadOpa = goalFieldOpa = 255;

            if (m->action != ACT_FLOOR_CHECKPOINT_WARP_IN) {
                set_fov_function(CAM_FOV_DEFAULT);
                cur_obj_change_action(ACT_WARP_PAD_WAIT_FOR_MARIO_TO_LEAVE);
            } else {
                Vec3f nextPos;
                vec3f_copy(nextPos, &o->oPosX);
                nextPos[1] += 120.0f;
                spring_towards_vec3f(m->pos, m->vel, nextPos, 0.1f, 0.97f);
            }
            break;
        }
        case ACT_WARP_PAD_WAIT_FOR_MARIO_TO_LEAVE: {
            goalPadOpa = WARP_PAD_OPA_MIN_ACTIVE;
            goalFieldOpa = WARP_PAD_WARP_OPA_MIN;
            if (o->oDistanceToMario > 200) {
                cur_obj_change_action(ACT_WARP_PAD_WAITING);
            }
            break;
        }
    }

    o->oOpacity = lroundf(approach_f32_asymptotic(o->oOpacity, goalPadOpa, 0.1f));
    o->oWarpPadWarpOpa = lroundf(approach_f32_asymptotic(o->oWarpPadWarpOpa, goalFieldOpa, 0.1f));

    // osSyncPrintf("oOpacity %8d | oWarpPadWarpOpa %8d\n", o->oOpacity, o->oWarpPadWarpOpa);
}

Gfx *geo_warp_pad_env_alpha(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    Gfx *dlStart, *dlHead;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (currentGraphNode->parameter != 0) SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, currentGraphNode->parameter);

        s32 opa = currentGraphNode->parameter >= LAYER_TRANSPARENT_DECAL ? obj->oWarpPadWarpOpa : obj->oOpacity;
        opa = CLAMP(opa, 0, 255);

        // osSyncPrintf("layer %8d | opa %8d\n", currentGraphNode->parameter, opa);

        if (currentGraphNode->parameter == LAYER_TRANSPARENT_INTER) {
            s32 visible = opa > 0;
            struct GraphNodeDisplayList *nextNode = (struct GraphNodeDisplayList *) node->next;
            COND_BIT(
                visible,
                nextNode->node.flags,
                GRAPH_RENDER_ACTIVE
            );

            if (!visible) return dlStart;
        }


        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;

        gDPSetEnvColor(dlHead++, 255, 255, 255, opa);
        gDPPipeSync(dlHead++);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

