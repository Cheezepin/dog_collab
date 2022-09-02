#include <ultra64.h>
#include "sm64.h"
#include "debug.h"
#include "print.h"
#include "engine/math_util.h"
#include "puppycam2.h"
#include "level_update.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "behavior_data.h"
#include "2639_defs.h"
#include "camera.h"
#include "audio/external.h"
#include "audio/load.h"
#include "rendering_graph_node.h"
extern s16 sStatusFlags;

// MODEL FUNCS

u8 envColor[][3] = {
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255},
    {255, 255, 0},
    {0, 255, 255},
};

Gfx *geo2639_ModulatePrim(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *dl = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *generatedNode = (struct GraphNodeGenerated *) node;

        dl = alloc_display_list(sizeof(Gfx) * 4);
        Gfx *dlp = dl;
        SET_GRAPH_NODE_LAYER(generatedNode->fnNode.node.flags, LAYER_OPAQUE);

        gDPSetEnvColor(dlp++,
            envColor[gCurGraphNodeObjectNode->oBehParams2ndByte][0], 
            envColor[gCurGraphNodeObjectNode->oBehParams2ndByte][1], 
            envColor[gCurGraphNodeObjectNode->oBehParams2ndByte][2], 
            255
        );
        gSPEndDisplayList(dlp);


    }
    return dl;
}




u32 _2639_BoB_A1_ToadTalkLatch = 0;
u32 _2639_BoB_A1_CaneCollected = 0;
u32 _2639_BoB_A1_SunglassesCollected = 0;

s32 in2639Level(struct Object *co) {
    f32 throw;
    struct Object *oo = cNearestObj_Bhv(bhv2639_DRM, &throw);

    return (oo != NULL);
}


struct Object *NextObj_BParam(const BehaviorScript *behavior, s32 bp) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *obj;
    struct ObjectNode *listHead;
    int itercount = 0;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                if (obj->oBehParams == bp) {
                    return obj;
                }
            }
        }
        obj = (struct Object *) obj->header.next;

        itercount++;
        assert(itercount < 1000, "obj not found");
    }

    return NULL;
}

// GEO_CAMERA(CAMERA_MODE_RADIAL, -419, 2484, -2154, -419, 3484, -2154, geo_camera_main),

am_i_stupid() {
    *(vs8*)0=0;
}

void CDebug(struct Camera *c) {
    char pstr[50];
    char fstr[50];
    char FFF[50];

    sprintf(pstr, "POS %0.2f %0.2f %0.2f", c->pos[0], c->pos[1], c->pos[2]);
    sprintf(fstr, "FOC %0.2f %0.2f %0.2f", c->focus[0], c->focus[1], c->focus[2]);

    sprintf(FFF, "MODE %d", sModeInfo.newMode);

    // print_text(10, 50, pstr);
    // print_text(10, 64, fstr);
    // print_text(10, 78, FFF);
}

void Cam2639_LogoCam(struct Camera *c) {
    set_camera_mode_fixed(c, -534, 4075, 3328);
}
void Cam2639_Elevator(struct Camera *c) {
    set_camera_mode_fixed(c, -125, 958, -380);
}
void Cam2639_CloseFocus(struct Camera *c) {
    fadech(PAD, BASEVOL);
    set_camera_mode_fixed2(c, -534, -800, -506);
}

void Cam2639_Main(struct Camera *c) {
    sStatusFlags |= CAM_FLAG_BLOCK_AREA_PROCESSING;
    transition_to_camera_mode(c, CAMERA_MODE_8_DIRECTIONS, 10);
    CDebug(c);
}

void Cam2639_OutwardSpiral(struct Camera *c) {
    sStatusFlags |= CAM_FLAG_BLOCK_AREA_PROCESSING;
    transition_to_camera_mode(c, CAMERA_MODE_OUTWARD_RADIAL, 60);
}

void fade_channel_volume_scale(u8 player, u8 channelIndex, u8 targetScale, u16 fadeDuration);

u32 curVolumes[16] = {0};

void fadech(u32 ch, u32 vol) {
    curVolumes[ch] = vol;
    fade_channel_volume_scale(SEQ_PLAYER_LEVEL, ch, vol, 30);
}

void setch(u32 ch, u32 vol) {
    curVolumes[ch] = vol;
    fade_channel_volume_scale(SEQ_PLAYER_LEVEL, ch, vol, 0);
}

void setallch(u32 vol) {
    for (int ch = 0; ch < 16; ch++) {
        curVolumes[ch] = vol;
        fade_channel_volume_scale(SEQ_PLAYER_LEVEL, ch, vol, 1);
    }
}


void outside_music() {
    setallch(0);
    fadech(PIANO, BASEVOL);
}

void introcutscene_music() {
    for (int i = 0; i < 16; i++) {
        fadech(i, BASEVOL);
    }
    fadech(KIDSHOW_STAGE2, 0);
    fadech(KIDSHOW_STAGE3, 0);
}


void Sound2639_Main(void) {
    static u32 state = 0;

    enum Sound2639States {
        STATE_INIT = 0,
        STATE_LEVELCHECK,
        STATE_CONTROLOBJ,
        STATE_INTROCUTSCENE,
    };

    switch (state) {
        case STATE_INIT:
            // TODO: if base volume is 50 then how to handle muted channels?
            for (int i = 0; i < 16; i++) {
                gSequencePlayers[SEQ_PLAYER_LEVEL].channels[i]->volumeScale = 0;
                // fade_channel_volume_scale(SEQ_PLAYER_LEVEL, i, 1, 1);
                curVolumes[i] = 0;
            }
            state = STATE_CONTROLOBJ;
            break;
        case STATE_CONTROLOBJ:            
            break;
    }
}
