#ifndef HUD_H
#define HUD_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include <types.h>
#include "area.h"

#define HUD_POWER_METER_X            24
#define HUD_POWER_METER_EMPHASIZED_Y 214
#define HUD_POWER_METER_Y            218
#define HUD_POWER_METER_HIDDEN_Y     300

#define HUD_TOP_Y 209
#define HUD_BOTTOM_Y 19 // Same height as the Lakitu icon

// kerning for glyph + * + number + number
#define GLYPH_X_NN_WIDTH (16+10+10+10)
#define PADDING_RIGHT 22 // cam's 54 - 16 - 16

#define HUD_STARS_X (GLYPH_X_NN_WIDTH + PADDING_RIGHT) // This starts counting from the right edge
#define HUD_COINS_X (GLYPH_X_NN_WIDTH + 10 + 8 + HUD_STARS_X)
#define HUD_CAMERA_X 54 // This starts counting from the right edge

enum PowerMeterAnimation {
    POWER_METER_HIDDEN,
    POWER_METER_EMPHASIZED,
    POWER_METER_DEEMPHASIZING,
    POWER_METER_HIDING,
    POWER_METER_VISIBLE
};

#ifdef BREATH_METER
enum BreathMeterAnimation {
    BREATH_METER_HIDDEN,
    BREATH_METER_SHOWING,
    BREATH_METER_HIDING,
    BREATH_METER_VISIBLE
};
#endif

enum CameraHUDLUT {
    GLYPH_CAM_CAMERA,
    GLYPH_CAM_MARIO_HEAD,
    GLYPH_CAM_LAKITU_HEAD,
    GLYPH_CAM_FIXED,
    GLYPH_CAM_ARROW_UP,
    GLYPH_CAM_ARROW_DOWN
};

void set_hud_camera_status(s16 status);
void render_hud(void);

extern s32 gKeyboard;
extern s32 gHubStarSelectTimer;

ALWAYS_INLINE s32 speedrun_timer_is_paused(void) {
    return gEndResultsActive || gCurrLevelNum == LEVEL_CASTLE_GROUNDS;
}

#endif // HUD_H
