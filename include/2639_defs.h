#pragma once

extern u32 _2639_BoB_A1_ToadTalkLatch;
extern u32 _2639_BoB_A1_CaneCollected;
extern u32 _2639_BoB_A1_SunglassesCollected;
void StarXYZ(u32 bparam, f32 targetX, f32 targetY, f32 targetZ);
// Spline defines
#define NC_SPLINE_NORMAL 0x00 //Will face the direction that it's moving.
#define NC_SPLINE_NOTURN 0x01 //Won't change direction at all.
#define NC_SPLINE_FOLLOW 0x02 //Will face the direction of a second spline.
#define NC_SPLINE_FOLLOWMARIO 0x03 // looks at mario
#define _2639COINCOUNT 123
enum ActNames2639 {
    ACT_0 = 0,
    ACT_LOBBYSCAVENGER,
    ACT_COUCHES,
    ACT_PARTY,
    ACT_FLOOD,
    ACT_BASEMENT,
    ACT_SCAVENGER,
};

enum newcam_flagvalues
{
    NC_FLAG_XTURN = 0x0001,//If this flag is set, the camera's yaw can be moved by the player.
    NC_FLAG_YTURN = 0x0002, //If this flag is set, the camera's pitch can be moved by the player.
    NC_FLAG_ZOOM = 0x0004, //If this flag is set, the camera's distance can be set by the player.
    NC_FLAG_8D = 0x0008, //If this flag is set, the camera will snap to an 8 directional axis
    NC_FLAG_4D = 0x0010, //If this flag is set, the camera will snap to a 4 directional axis
    NC_FLAG_2D = 0x0020, //If this flag is set, the camera will stick to 2D.
    NC_FLAG_FOCUSX = 0x0040, //If this flag is set, the camera will point towards its focus on the X axis.
    NC_FLAG_FOCUSY = 0x0080, //If this flag is set, the camera will point towards its focus on the Y axis.
    NC_FLAG_FOCUSZ = 0x0100, //If this flag is set, the camera will point towards its focus on the Z axis.
    NC_FLAG_POSX = 0x0200, //If this flag is set, the camera will move along the X axis.
    NC_FLAG_POSY = 0x0400, //If this flag is set, the camera will move along the Y axis.
    NC_FLAG_POSZ = 0x0800, //If this flag is set, the camera will move along the Z axis.
    NC_FLAG_COLLISION = 0x1000, //If this flag is set, the camera will collide and correct itself with terrain.
    NC_FLAG_SLIDECORRECT = 0x2000, //If this flag is set, the camera will attempt to centre itself behind Mario whenever he's sliding.

    NC_MODE_NORMAL = NC_FLAG_XTURN | NC_FLAG_YTURN | NC_FLAG_ZOOM | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ | NC_FLAG_POSX | NC_FLAG_POSY | NC_FLAG_POSZ | NC_FLAG_COLLISION,
    NC_MODE_SLIDE = NC_FLAG_XTURN | NC_FLAG_YTURN | NC_FLAG_ZOOM | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ | NC_FLAG_POSX | NC_FLAG_POSY | NC_FLAG_POSZ | NC_FLAG_COLLISION | NC_FLAG_SLIDECORRECT,
    NC_MODE_FIXED = NC_FLAG_XTURN | NC_FLAG_YTURN | NC_FLAG_ZOOM | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ,
    NC_MODE_2D = NC_FLAG_XTURN | NC_FLAG_YTURN | NC_FLAG_ZOOM | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ | NC_FLAG_POSX | NC_FLAG_POSY | NC_FLAG_POSZ | NC_FLAG_COLLISION,
    NC_MODE_8D = NC_FLAG_XTURN | NC_FLAG_YTURN | NC_FLAG_ZOOM | NC_FLAG_8D | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ | NC_FLAG_POSX | NC_FLAG_POSY | NC_FLAG_POSZ | NC_FLAG_COLLISION,
    NC_MODE_FIXED_NOMOVE = 0x0000,
    NC_MODE_NOTURN = NC_FLAG_ZOOM | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ | NC_FLAG_POSX | NC_FLAG_POSY | NC_FLAG_POSZ | NC_FLAG_COLLISION,
    NC_MODE_NOROTATE = NC_FLAG_YTURN | NC_FLAG_ZOOM | NC_FLAG_FOCUSX | NC_FLAG_FOCUSY | NC_FLAG_FOCUSZ | NC_FLAG_POSX | NC_FLAG_POSY | NC_FLAG_POSZ | NC_FLAG_COLLISION

};

typedef struct newcam_hardpos {
    u8 levelID;
    u8 areaID;
    u8 permaswap;
    u16 modeset;
    s32 *func;
    s16 X1;
    s16 Y1;
    s16 Z1;
    s16 X2;
    s16 Y2;
    s16 Z2;
    s16 camX;
    s16 camY;
    s16 camZ;
    s16 lookX;
    s16 lookY;
    s16 lookZ;
} PuppyCamVolume;

extern struct newcam_hardpos newcam_fixedcam[];

#define cNearestObj_Bhv cur_obj_find_nearest_object_with_behavior
#define Obj_GetAnyObj find_any_object_with_behavior

#define BASEVOL 65
enum SoundChannels {
    KIDSHOW_STAGE3 = 0,
    KIDSHOW_STAGE2,
    KIDSHOW_MAIN,
    PIANO,
    PAD,
    SUPERSAW,
    STRINGS,
    BASS,
    CITYSOUND,

    // drums
    CYMBALRIDE,
    CYMBALRIDE2,
    _808SNARE,
    KICK,
    CLAPFILL,
    MAINSNARE,

    // unused but maybe i'll make this the background claps
    CHF,
};

enum DF6_STATE {
    DF6_NORMAL = 0,
    DF6_APPROACH,
    DF6_JUMP,
    DF6_IN_AIR,
    DF6_SWIM,
};
#define DOG_ANIM_POUNCE 4
extern s32 gDialogResponse;
