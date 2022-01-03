#include "thecozies_helpers.h"
#include "actors/group13.h"
#include "buffers/framebuffers.h"
#include "game/game_init.h"
// #include "gbi.h"

// Width and height of output texture
#define BUBBLE_FB_IMAGE__W         32
#define BUBBLE_FB_IMAGE__H         32
// Number of pixels to sample for each individual pixel (samples more of the framebuffer)
#define BUBBLE_FB_SAMPLE_SIZE__W   4
#define BUBBLE_FB_SAMPLE_SIZE__H   4
// Multiple of columns to skip during sampling (1 for every pixel, 2 for every other pixel, etc)
#define BUBBLE_FB_SAMPLE_SKIP      2
// Num pixels to sample per pixel
#define BUBBLE_FB_SAMPLE_SIZE__TOTAL (BUBBLE_FB_SAMPLE_SIZE__W * BUBBLE_FB_SAMPLE_SIZE__H)
// Multiplier (for dividing the strength of each sampled pixel)
#define BUBBLE_FB_SAMPLE_SIZE__MUL ((1.0f / BUBBLE_FB_SAMPLE_SIZE__TOTAL) * BUBBLE_FB_SAMPLE_SKIP)
// Distance from center to edge of sample area
#define BUBBLE_FB_SAMPLE_OFFSET__W (BUBBLE_FB_SAMPLE_SIZE__W * BUBBLE_FB_IMAGE__W / 2)
#define BUBBLE_FB_SAMPLE_OFFSET__H (BUBBLE_FB_SAMPLE_SIZE__H * BUBBLE_FB_IMAGE__H / 2)

void bubble_shell_sample_frame_buffer(void) {
    s32 pixel;
    f32 r, g, b;
    s32 iy, ix, sy, sx;
    static u32 curFrame = 0;
    static s32 xOffset = (SCREEN_WIDTH / 2) - BUBBLE_FB_SAMPLE_OFFSET__W;
    static s32 yOffset = (SCREEN_HEIGHT / 2) - BUBBLE_FB_SAMPLE_OFFSET__H;

    // if (gNoFrameBufferEmulation) {
    //     return;
    // }

    if (curFrame == gGlobalTimer) return;
    curFrame = gGlobalTimer;

    u16 *fb = gFrameBuffers[sRenderingFrameBuffer];
    u16 *image = segmented_to_virtual(shell_bubble_framebuffer_img);

    for (iy = 0; iy < BUBBLE_FB_IMAGE__H; iy++) {
        for (ix = 0; ix < BUBBLE_FB_IMAGE__W; ix++) {
            r = 0;
            g = 0;
            b = 0;

            for (sy = 0; sy < BUBBLE_FB_SAMPLE_SIZE__H; sy += BUBBLE_FB_SAMPLE_SKIP) {
                for (sx = 0; sx < BUBBLE_FB_SAMPLE_SIZE__W; sx += BUBBLE_FB_SAMPLE_SKIP) {
                    pixel = SCREEN_WIDTH * (BUBBLE_FB_SAMPLE_SIZE__H * iy + sy + yOffset) + (BUBBLE_FB_SAMPLE_SIZE__W * ix + xOffset) + sx;

                    r += ((fb[pixel] >> 0xB) & 0x1F);
                    g += ((fb[pixel] >> 0x6) & 0x1F);
                    b += ((fb[pixel] >> 0x1) & 0x1F);
                }
            }

            image[BUBBLE_FB_IMAGE__H * iy + ix] =
                ((((u16) ((r * BUBBLE_FB_SAMPLE_SIZE__MUL) + 0.5) << 0xB) & 0xF800)) |
                ((((u16) ((g * BUBBLE_FB_SAMPLE_SIZE__MUL) + 0.5) << 0x6) &  0x7C0)) |
                ((((u16) ((b * BUBBLE_FB_SAMPLE_SIZE__MUL) + 0.5) << 0x1) &   0x3E)) | 1;
        }
    }

    return;
}

enum BUBBLE_SHELL_ACTIONS {
    BUBBLE_SHELL_WAIT_FOR_COLLECTION,
    BUBBLE_SHELL_WAIT_FOR_RESPAWN,
    BUBBLE_SHELL_RESPAWNING
};

// #define BUBBLE_SHELL_RESPAWN_WAIT (30 * 30) // 30 seconds
#define BUBBLE_SHELL_RESPAWN_WAIT (10 * 30) // 30 seconds
#define BUBBLE_SHELL_RESPAWNING_LENGTH (10 * 30) // 10 seconds

void bubble_shell_spawn_shell(void) {
    struct Object *object = spawn_object(o, MODEL_KOOPA_SHELL, bhvKoopaShellUnderwater);
    o->oBubbleShellObj = object;
}

void bubble_shell_wait_for_collection(void) {
    if (!o->oBubbleShellObj) bubble_shell_spawn_shell();

    // make sure mario doesn't have a shell or sphere interaction idk
    if (
        o->oDistanceToMario < 200
        && (gMarioState->action & ACT_FLAG_SWIMMING)
        && !(gMarioState->action & ACT_FLAG_METAL_WATER)
        && ((gMarioState->action & ACT_ID_MASK) < (ACT_HOLD_BREASTSTROKE & ACT_ID_MASK))
        && !gMarioState->usedObj
        && !gMarioState->heldObj
    ) {
        cur_obj_change_action(BUBBLE_SHELL_WAIT_FOR_RESPAWN);
        cur_obj_hide();
        gMarioState->usedObj = o->oBubbleShellObj;
        mario_grab_used_object(gMarioState);
        o->oBubbleShellObj->parentObj = gMarioObject;
        gMarioState->marioBodyState->grabPos = GRAB_POS_LIGHT_OBJ;
        set_mario_action(gMarioState, ACT_WATER_SHELL_SWIMMING, 0);
        o->oBubbleShellObj = NULL;
    }
}

void bubble_shell_wait_for_respawn(void) {
    if (o->oTimer++ > BUBBLE_SHELL_RESPAWN_WAIT) {
        cur_obj_change_action(BUBBLE_SHELL_RESPAWNING);
        cur_obj_scale(0.001f);
        cur_obj_unhide();
        o->oBubbleShellScaleVel = 0.0f;
    }
}

void bubble_shell_respawning(void) {
    elastic_approach(&o->header.gfx.scale[0], &o->oBubbleShellScaleVel, 1.0f, 0.1f, 0.1f);
    cur_obj_scale(o->header.gfx.scale[0]);

    bubble_shell_wait_for_collection();
    if (o->oTimer++ > BUBBLE_SHELL_RESPAWNING_LENGTH) {
        cur_obj_change_action(BUBBLE_SHELL_WAIT_FOR_COLLECTION);
        cur_obj_scale(1.0f);
    }
}

void bubble_shell_loop(void) {
    bubble_shell_sample_frame_buffer();
    switch (o->oAction) {
        case BUBBLE_SHELL_WAIT_FOR_COLLECTION:
            bubble_shell_wait_for_collection();
            break;
        case BUBBLE_SHELL_WAIT_FOR_RESPAWN:
            bubble_shell_wait_for_respawn();
            break;
        case BUBBLE_SHELL_RESPAWNING:
            bubble_shell_respawning();
            break;
    }
}
