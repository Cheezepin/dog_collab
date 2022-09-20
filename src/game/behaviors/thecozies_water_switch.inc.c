#include "game/behaviors/thecozies_helpers.h"


enum BST_WATER_LEVELS {
    BST_LEVEL0,
    BST_LEVEL1,
    BST_LEVEL2,
    BST_LEVEL3,
    BST_LEVEL4,
    BST_LEVEL5,
    BST_LEVEL6,
    BST_LEVEL_LAST,
};

f32 bstWaterLevels[] = {
    [BST_LEVEL0] = 0,
    [BST_LEVEL1] = 0,
    [BST_LEVEL2] = 0,
    [BST_LEVEL3] = 0,
    [BST_LEVEL4] = 0,
    [BST_LEVEL5] = 0,
    [BST_LEVEL6] = 0,
    [BST_LEVEL_LAST] = 0,
};

void water_switch_init(void) {
    if (gCurrActNum > BPARAM1) { // x star in DDD complete
        o->oWaterSwitchActivated = TRUE;
    }
} 

s16 original_water_col_positions[] = {
    36,
    36,
    36,
    36,
    25,
    25,
    -20,
    -20,
    25,
    -20,
    25,
    -20,
};

void translate_water_switch_col(struct Object *obj) {
    if (obj->oDistanceToMario > obj->oCollisionDistance) return;
    s16 *collisionData = obj->collisionData;
    s16 *vertices;

    collisionData++;
    s32 numVertices = *collisionData;
    collisionData++;

    vertices = collisionData;
    s32 i = 0;
    for (s32 i = 0; i < numVertices; i++) {
        s16 *vert = &vertices[i*3];
        vert[1] = (s16)roundf(o->oWaterSwitchOffset + (f32)original_water_col_positions[i]);
    }
}

#define WATER_SWITCH_OFFSET -26
#define WATER_SWITCH_OFFSET_MARIO (WATER_SWITCH_OFFSET - 8)

void water_switch_loop(void) {
    f32 goalOffset = 0;
    if (check_mario_on_object(gMarioState)) {
        goalOffset = WATER_SWITCH_OFFSET_MARIO;
    }
    else if (o->oWaterSwitchActivated) {
        goalOffset = WATER_SWITCH_OFFSET;
    }

    elastic_approach(&o->oWaterSwitchOffset, &o->oWaterSwitchOffsetVel, goalOffset, 0.2f, 0.2f);

    if (o->oWaterSwitchOffset <= WATER_SWITCH_OFFSET + 1) {
        o->oWaterSwitchActivated = TRUE;
    }

    if (o->oWaterSwitchOffset < WATER_SWITCH_OFFSET_MARIO - 2) {
        o->oWaterSwitchOffset = WATER_SWITCH_OFFSET_MARIO - 2;
        o->oWaterSwitchOffsetVel = 0;
    }

    if (o->oWaterSwitchActivated && o->oWaterSwitchOffset > WATER_SWITCH_OFFSET + 2) {
        o->oWaterSwitchOffset = WATER_SWITCH_OFFSET + 2;
        o->oWaterSwitchOffsetVel = 0;
    }

    if (
        o->oWaterSwitchActivated
        && gPlayer1Controller->buttonPressed & Z_TRIG
        && gPlayer1Controller->buttonDown & L_TRIG
    ) {
        o->oWaterSwitchActivated = FALSE;
        o->oWaterSwitchActiveState = 0;
    }

    translate_water_switch_col(o);
}

Gfx *geo_water_switch_activation(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    Gfx *dlStart, *dlHead;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (currentGraphNode->parameter != 0) SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, currentGraphNode->parameter);

        dlStart = alloc_display_list(sizeof(Gfx) * 2);
        dlHead = dlStart;

        ((struct GraphNodeTranslation *) node->next)->translation[1] = roundf(obj->oWaterSwitchOffset);

        if (obj->oWaterSwitchActivated) {
            gDPSetEnvColor(dlHead++, 255, 123*1.25f, 10*1.25f, 255);
        } else {
            gDPSetEnvColor(dlHead++, 255*(2.0f/3.0f), 123*(2.0f/3.0f), 10*(2.0f/3.0f), 255);
        }
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

void get_base_switch_mat(Gfx* dlHead, u16 offset) {
	gDPPipeSync(dlHead++);
	gDPSetCombineLERP(dlHead++, 0, 0, 0, 0, TEXEL0, 0, TEXEL1, PRIMITIVE, PRIMITIVE, 0, COMBINED_ALPHA, 0, 0, 0, 0, 1);
	gSPGeometryMode(dlHead++, 0, G_TEXTURE_GEN);
	gDPSetCycleType(dlHead++, G_CYC_2CYCLE);
	gDPSetRenderMode(dlHead++, G_RM_PASS, G_RM_AA_ZB_OPA_INTER2);
	gSPTexture(dlHead++, 6048, 6048, 0, 0, 1);
	gDPTileSync(dlHead++);
	gDPSetTextureImage(dlHead++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, segmented_to_virtual(water_switch_voyanoid64_i8));
	gDPSetTile(dlHead++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 1);
	gDPLoadSync(dlHead++);
	gDPLoadBlock(dlHead++, 7, 0, 0, 2047, 256);
	gDPPipeSync(dlHead++);
	gDPSetTile(dlHead++, G_IM_FMT_I, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 1);
	gDPSetTileSize(dlHead++, 0, 64 - offset, 64 + offset, 252, 252);
	gDPTileSync(dlHead++);
	gDPSetTextureImage(dlHead++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, segmented_to_virtual(water_switch_voyanoid64_i8));
	gDPSetTile(dlHead++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 6, 0, G_TX_CLAMP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 15);
	gDPLoadSync(dlHead++);
	gDPLoadBlock(dlHead++, 6, 0, 0, 2047, 256);
	gDPPipeSync(dlHead++);
	gDPSetTile(dlHead++, G_IM_FMT_I, G_IM_SIZ_8b, 8, 0, 1, 0, G_TX_CLAMP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 15);
	gDPSetTileSize(dlHead++, 1, 48 + offset, 0, 256, 12);
	gDPSetPrimColor(dlHead++, 0, 0, 101, 255, 239, 121);
	gSPEndDisplayList(dlHead);
};

Gfx *geo_water_switch_activation_anim(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    Gfx *dlStart, *dlHead;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (currentGraphNode->parameter != 0) SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, currentGraphNode->parameter);

        dlStart = alloc_display_list(sizeof(Gfx) * 24);
        dlHead = dlStart;

        u32 rate = MAX(obj->oWaterSwitchActiveState >> 16, 1);
        u32 cur = obj->oWaterSwitchActiveState & 0xFFFF;
        if (obj->oWaterSwitchActivated) {
            if (((cur) % (16 * rate)) == 0) rate = MIN(rate + 1, 4);
            cur += rate;
            cur &= 0xFFFF;

            obj->oWaterSwitchActiveState = (rate << 16) | cur;
        }

        get_base_switch_mat(dlHead, cur);
    }

    return dlStart;
}

Vec3f *waterlevelgoals[] = {
    NULL,
    &cozies_waterlevel0,
    &cozies_waterlevel1,
    &cozies_waterlevel2,
    &cozies_waterlevel3,
};

f32 *get_goal_ptr(s32 idx) {
    f32 *p = segmented_to_virtual(waterlevelgoals[idx]);
    return p;
}

enum WaterLevelBehaviors {
    WATER_LEVEL_BHV_DEFAULT,
    WATER_LEVEL_BHV_ACT_1,
    WATER_LEVEL_BHV_WHIRLPOOL,
    WATER_LEVEL_BHV_STATIC = 0xFF,
};

void set_water_level_goal(struct Object *obj) {
    s32 behavior = BPARAM1;
    s32 id = BPARAM2;
    switch (behavior) {
        case WATER_LEVEL_BHV_STATIC: // static water, might be act specific
            break;
        case WATER_LEVEL_BHV_ACT_1:
            if (gCurrActNum > 1) obj->oHomeY = get_goal_ptr(id)[1];
            break;
        case WATER_LEVEL_BHV_WHIRLPOOL: // whirlpool
        default:
            struct Object *water_switch = get_water_switch(id);
            if (water_switch && water_switch->oWaterSwitchActivated) {
                obj->oHomeY = get_goal_ptr(id)[1];
                obj->oWaterAtGoal = TRUE;
            }
            break;
    }
}

void water_switch_water_init(void) {
    set_water_level_goal(o);
}

#define WATER_OSC_SPEED 0x100
#define WATER_OSC_HEIGHT 20.0f
void water_oscillation(struct Object *obj) {
    obj->oWaterBobTimer += WATER_OSC_SPEED;
    obj->oPosY = approach_f32_asymptotic(
        obj->oPosY,
        obj->oHomeY + (WATER_OSC_HEIGHT * sins(obj->oWaterBobTimer)),
        0.05f
    );
}

#define WHIRLPOOL_SCROLL_MIN 0.4f
#define WHIRLPOOL_SCROLL_MAX 1.5f

void scroll_metal_tube(f32 curSpeed) {
    f32 lerpo = get_relative_position_between_ranges(
        curSpeed,
        WHIRLPOOL_SCROLL_MIN, WHIRLPOOL_SCROLL_MAX,
        0.4f, 1.0f
    );
    u16 t1S = roundf(3.0f * lerpo);
    u16 t1T = roundf(5.0f * lerpo);
    u16 t2S = roundf(2.0f * lerpo);
    u16 t2T = roundf(4.0f * lerpo);

    Gfx *mat = segmented_to_virtual(mat_ddd_dl_metalTUUUUUUBE_layer0);
	shift_s(mat, 13, t1S);
	shift_t_down(mat, 13, t1T);
	shift_s(mat, 21, t2S);
	shift_t_down(mat, 21, t2T);
}

void scroll_whirlpool_verts(f32 curSpeed) {
	int i = 0;
	int count = 131;
	int width = 128 * 0x20;

    scroll_metal_tube(curSpeed);

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(water_plane4_whirlpool_water_plane4_whirlpool_mesh_layer_5_vtx_0);

	deltaX = roundf(curSpeed * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

// struct Whirlpool this_whirlpool = {
//     .pos = { 0, 0, 0 },
//     .strength = 40
// };

void whirlpool_life_cycle(struct Object *obj) {
    static f32 curSpeed = WHIRLPOOL_SCROLL_MAX;

    cur_obj_play_sound_1(SOUND_ENV_WATERFALL2);

    // if (gCurrentArea->whirlpools[0] == NULL) {
    //     gCurrentArea->whirlpools[0] = whirlpool;
    // }

    // vec3_copy(whirlpool->pos, &obj->oPosVec);

    if (obj->oWaterAtGoal) {
        // whirlpool->strength = 10;
        obj->header.gfx.scale[1] = approach_f32_asymptotic(obj->header.gfx.scale[1], 0, 0.05f);
        curSpeed = approach_f32_asymptotic(curSpeed, WHIRLPOOL_SCROLL_MIN, 0.05f);
        scroll_whirlpool_verts(curSpeed);
    } else {
        curSpeed = approach_f32_asymptotic(curSpeed, WHIRLPOOL_SCROLL_MAX, 0.05f);
        scroll_whirlpool_verts(curSpeed);
        // whirlpool->strength = 60;
        if (
            gMarioState->water
            && gMarioState->water->object == obj
            && (ACT_GROUP_SUBMERGED == (gMarioState->action & ACT_GROUP_MASK))
        ) {
            set_mario_action(gMarioState, ACT_FLOOR_CHECKPOINT_WARP_OUT, 0x100);
        }
    }

    s32 marioInRoom = (
        gMarioCurrentRoom == o->oRoom
        || gDoorAdjacentRooms[gMarioCurrentRoom][0] == o->oRoom
        || gDoorAdjacentRooms[gMarioCurrentRoom][1] == o->oRoom
    );

    COND_BIT(
        !marioInRoom || (gMarioState->pos[1] > obj->oPosY + 500),
        obj->activeFlags,
        ACTIVE_FLAG_IN_DIFFERENT_ROOM
    );
}

void water_life_cycle(struct Object *obj) {
    if (!obj->oWaterAtGoal) set_water_level_goal(obj);
    water_oscillation(obj);

    if (BPARAM1 == WATER_LEVEL_BHV_WHIRLPOOL) {
        whirlpool_life_cycle(obj);
    }
}

void water_switch_water_loop(void) {
    water_life_cycle(o);
}

Collision *watercollisions[] = {
    &water_plane2_ctrl_room_collision,
};

void static_water_obj_init(void) {
    o->collisionData = segmented_to_virtual(watercollisions[BPARAM2]);
}
