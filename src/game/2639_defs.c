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

u32 _2639_BoB_A1_ToadTalkLatch = 0;
u32 _2639_BoB_A1_CaneCollected = 0;
u32 _2639_BoB_A1_SunglassesCollected = 1;

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

void CDebug(struct Camera *c) {
    char pstr[50];
    char fstr[50];
    char FFF[50];

    sprintf(pstr, "POS %0.2f %0.2f %0.2f", c->pos[0], c->pos[1], c->pos[2]);
    sprintf(fstr, "FOC %0.2f %0.2f %0.2f", c->focus[0], c->focus[1], c->focus[2]);

    sprintf(FFF, "MODE %d", sModeInfo.newMode);

    print_text(10, 50, pstr);
    print_text(10, 64, fstr);
    print_text(10, 78, FFF);
}

void Cam2639_LogoCam(struct Camera *c) {
    set_camera_mode_fixed(c, -534, 2252, 3328);
}
void Cam2639_Elevator(struct Camera *c) {
    set_camera_mode_fixed(c, -125, 958, -380);
}

void Cam2639_Main(struct Camera *c) {
    extern s16 sStatusFlags;
    sStatusFlags |= CAM_FLAG_BLOCK_AREA_PROCESSING;
    transition_to_camera_mode(c, CAMERA_MODE_8_DIRECTIONS, 10);
    CDebug(c);
}
