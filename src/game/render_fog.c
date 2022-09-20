#include <PR/ultratypes.h>
#include "sm64.h"

#include "area.h"
#include "rendering_graph_node.h"
#include "engine/math_util.h"
#include "object_list_processor.h"
#include "level_update.h"
#include "camera.h"
#include "render_fog.h"

struct GlobalFog sDDDWaterFog = {
    .r    = WATER_BASE_RA,
    .g    = WATER_BASE_GA,
    .b    = WATER_BASE_BA,
    .a    = 0xFF,
    .low  = 920,
    .high = 1000
};

struct GlobalFog sDDDFogArea3 = {
    .r    = 0xB3,
    .g    = 0xBC,
    .b    = 0xCD,
    .a    = 0xFF,
    .low  = 980,
    .high = 1050
};

struct GlobalFog sDDDFogArea2 = {
    .r    = 70,
    .g    = 67,
    .b    = 77,
    .a    = 0xFF,
    .low  = 980,
    .high = 1030
};

struct GlobalFog sDDDFogRoom4_5_6_7 = {
    .r    = 93,
    .g    = 80,
    .b    = 124,
    .a    = 0xFF,
    .low  = 960,
    .high = 1002
};

struct GlobalFog sDDDFogRoom8 = {
    .r    = 100,
    .g    = 62,
    .b    = 144,
    .a    = 0xFF,
    .low  = 970,
    .high = 1080
};

struct GlobalFog sDDDFogRoom8Tube = {
    .r    = 0,
    .g    = 0,
    .b    = 0,
    .a    = 0xFF,
    .low  = 960,
    .high = 990
};

struct GlobalFog sDDDFogRoom9 = {
    // [255, 237, 255]
    .r    = 255,
    .g    = 237,
    .b    = 255,
    .a    = 0xFF,
    .low  = 960,
    .high = 1040
};
struct GlobalFog sDDDFogRoom10 = {
    .r    = 111,
    .g    = 158,
    .b    = 170,
    .a    = 0xFF,
    .low  = 980,
    .high = 1000
};

struct GlobalFog sDDDWaterFogRoom10 = {
    // [80, 115, 124]
    .r    = 80,
    .g    = 115,
    .b    = 124,
    .a    = 0xFF,
    .low  = 960,
    .high = 995
};

struct GlobalFog sDDDFogArea1 = {
    .r    = 0xB3,
    .g    = 0xBC,
    .b    = 0xDD,
    .a    = 0xFF,
    .low  = 950,
    .high = 1000
};

#define AREA1_FOG_LOW 955
#define AREA1_FOG_HIGH_ADD 5

struct GlobalFog sDDDFogArea1_0xC000 = {
    // [60, 58, 74]
    .r    = 60,
    .g    = 58,
    .b    = 74,
    .a    = 0xFF,
    .low  = AREA1_FOG_LOW,
    .high = 1005 + AREA1_FOG_HIGH_ADD
};

struct GlobalFog sDDDFogArea1_0x8000 = {
    // [90, 85, 96]
    .r    = 90,
    .g    = 85,
    .b    = 96,
    .a    = 0xFF,
    .low  = AREA1_FOG_LOW,
    .high = 1002 + AREA1_FOG_HIGH_ADD
};

struct GlobalFog sDDDFogArea1_0x4000 = {
    // [114, 106, 111]
    .r    = 114,
    .g    = 106,
    .b    = 111,
    .a    = 0xFF,
    .low  = AREA1_FOG_LOW,
    .high = 1000 + AREA1_FOG_HIGH_ADD
};

struct GlobalFog sDDDFogArea1_0x0000 = {
    // [84, 86, 102]
    .r    = 84,
    .g    = 86,
    .b    = 102,
    .a    = 0xFF,
    .low  = AREA1_FOG_LOW,
    .high = 1001 + AREA1_FOG_HIGH_ADD
};

struct GlobalFog *area1_fogs[] = {
    &sDDDFogArea1_0x0000,
    &sDDDFogArea1_0x4000,
    &sDDDFogArea1_0x8000,
    &sDDDFogArea1_0xC000,
};

void lerp_camera_direction_area1(void) {
    u16 yaw = (u16)gCamera->yaw;
    u16 remainder = yaw % DEGREES(90);
    u32 index = (yaw - remainder) / DEGREES(90);
    struct GlobalFog *f1 = area1_fogs[index];
    struct GlobalFog *f2 = area1_fogs[(index + 1) % 4];
    f32 fac = get_lerp((f32)remainder, 0, (f32)DEGREES(90));
    sDDDFogArea1.r = (u8)roundf(lerp(f1->r, f2->r, fac));
    sDDDFogArea1.g = (u8)roundf(lerp(f1->g, f2->g, fac));
    sDDDFogArea1.b = (u8)roundf(lerp(f1->b, f2->b, fac));
    sDDDFogArea1.low = roundf(lerp(f1->low, f2->low, fac));
    sDDDFogArea1.high = roundf(lerp(f1->high, f2->high, fac));
    // osSyncPrintf("\n%d || %d || %d\n", yaw, remainder, index);
    // osSyncPrintf("%x %x %x | [%d, %d]\n", sDDDFogArea1.r, sDDDFogArea1.g, sDDDFogArea1.b, sDDDFogArea1.low, sDDDFogArea1.high);
}

extern struct GlobalFog gGlobalFog;

#define GLOBAL_FOG_UPDATE_RATE_DIVISOR 10
void update_global_fog_ddd(void) {
    if (gCurrLevelNum != LEVEL_COZIES) return;
    struct GlobalFog *goalFog;

    if (gCameraIsUnderwater) {
        if (gCurrAreaIndex == 2 && gMarioCurrentRoom == 10) {
            goalFog = &sDDDWaterFogRoom10;
        } else {
            goalFog = &sDDDWaterFog;
        }
    }
    else {
        switch (gCurrAreaIndex)
        {
        case 3:
            goalFog = &sDDDFogArea3;
            break;
        case 2: {
            switch (gMarioCurrentRoom) {
                case 4:
                case 5:
                case 6:
                case 7:
                    goalFog = &sDDDFogRoom4_5_6_7;
                    break;
                case 8: {
                    if (gCamera->cozyVolId == COZY_VOLUME_DOWN_THA_TUBE || gMarioState->pos[1] < -7633.0f) { // wayyy down the tube
                        goalFog = &sDDDFogRoom8Tube;
                    } else {
                        goalFog = &sDDDFogRoom8;
                    }
                    break;
                }
                case 9:
                    goalFog = &sDDDFogRoom9;
                    break;
                case 10:
                    goalFog = &sDDDFogRoom10;
                    break;
                default:
                    goalFog = &sDDDFogArea2;
            }
            break;
        }
        case 1:
        default:
            lerp_camera_direction_area1();
            goalFog = &sDDDFogArea1;
            break;
        }
    }
    gGlobalFog.r    = approach_s16_asymptotic(gGlobalFog.r,    goalFog->r,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.g    = approach_s16_asymptotic(gGlobalFog.g,    goalFog->g,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.b    = approach_s16_asymptotic(gGlobalFog.b,    goalFog->b,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.a    = approach_s16_asymptotic(gGlobalFog.a,    goalFog->a,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.low  = approach_s16_asymptotic(gGlobalFog.low,  goalFog->low,  GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.high = approach_s16_asymptotic(gGlobalFog.high, goalFog->high, GLOBAL_FOG_UPDATE_RATE_DIVISOR);
}
