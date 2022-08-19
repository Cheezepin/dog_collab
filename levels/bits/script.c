#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_WARP_BOX, warpbox_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ASHPILE, ashpile_bits_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ASHPILE2, ashpile2_bits_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PROPANE_THROWER, propane_thrower_bits_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RMINE, rmine_bits_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FADE_CLOUD, fade_cloud_bits_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BITS, 0x02, 0x02, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 103, -14184, -2413, -2665),
		OBJECT(MODEL_NONE, -14184, -2413, -2665, 0, 103, 0, (0xA << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_RED_COIN, 3879, -649, 3289, 0, 0, 0, 0x000B0000, bhvRedCoin),
		OBJECT(MODEL_FADE_CLOUD, 105, -850, 2152, 0, 0, 0, 0x00000000, bhvFadeCloudBits),
		OBJECT(MODEL_FADE_CLOUD, 1331, -850, 3207, 0, 0, 0, 0x00000000, bhvFadeCloudBits),
		OBJECT(MODEL_FADE_CLOUD, 3879, -853, 3289, 0, 0, 0, 0x00000000, bhvFadeCloudBits),
		OBJECT(MODEL_FADE_CLOUD, 2971, -850, 131, 0, -26, 0, 0x00000000, bhvFadeCloudBits),
		OBJECT(MODEL_FADE_CLOUD, 4708, -850, -88, 0, -86, 0, 0x00000000, bhvFadeCloudBits),
		OBJECT(MODEL_WARP_BOX, 16661, -120, 4058, 0, 0, 0, (1 << 16), bhvWarpBox),
		TERRAIN(bits_area_1_collision),
		ROOMS(bits_area_1_collision_rooms),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bits_area_2),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BITS, 0x02, 0x02, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BITS, 0x03, 0x04, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_ASHPILE, 5107, -1291, 1541, 0, 0, 0, 0x00000000, bhvAshpileBits),
		OBJECT(MODEL_ASHPILE, -351, 3079, 1488, 0, 0, 0, 0x00000000, bhvAshpileBits),
		OBJECT(MODEL_ASHPILE, -1091, 3079, 1171, 0, 0, 0, 0x00000000, bhvAshpileBits),
		OBJECT(MODEL_ASHPILE, -3147, 3779, 1549, 0, 0, 0, 0x00000000, bhvAshpileBits),
		OBJECT(MODEL_ASHPILE, -3376, 3779, 1193, 0, 0, 0, 0x00000000, bhvAshpileBits),
		OBJECT(MODEL_ASHPILE, -4810, 8302, 2420, 0, 0, 0, 0x00000000, bhvAshpileBits),
		OBJECT(MODEL_PROPANE_THROWER, 8462, -1553, 1995, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 3373, -1231, 4447, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 4373, -1231, 4447, 0, 0, 0, 0x00010000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 2953, -22, 5934, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 1369, 2045, 5934, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 314, 2045, 5934, 0, 0, 0, (1 << 16), bhvPropaneThrower),
		OBJECT(MODEL_RMINE, 2811, -1231, 3882, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 2811, -1231, 3295, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_MOTOS, 1379, 1012, 2146, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, 3532, -22, 4860, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, -1282, 3079, 1389, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_PURPLE_SWITCH, 1897, 1012, 1302, 0, 0, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_RED_COIN, 1346, 1064, -308, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WARP_BOX, 10464, -1313, 2460, 0, 0, 0, (1 << 24) | (2 << 16), bhvWarpBox),
		OBJECT(MODEL_WARP_BOX, -8194, 8502, 2435, 0, 0, 0, (3 << 16), bhvWarpBox),
		TERRAIN(bits_area_2_collision),
		MACRO_OBJECTS(bits_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bits_area_3),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_BITS, 0x03, 0x04, WARP_NO_CHECKPOINT),
		WARP_NODE(0x05, LEVEL_BITS, 0x04, 0x06, WARP_NO_CHECKPOINT),
		OBJECT(0x1F6, -1303, 0, 0, 0, 0, 0, (0 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, -7177, 0, 0, 0, 0, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, 4, 0, -1428, 0, 90, 0, 0x00000000, bhvLaserRingSpawner),
		OBJECT(0x1F6, -4858, 0, -1086, 0, 0, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, 1379, 0, 3, 0, -180, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, -4824, 0, 555, 0, 0, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, -3, 0, 1417, 0, -90, 0, 0x00000000, bhvLaserRingSpawner),
		OBJECT(MODEL_RED_COIN, 4, 904, 3, 0, -180, 0, (1 << 16), bhvRedCoin),
		OBJECT(MODEL_WARP_BOX, -9853, 177, 10, 0, 90, 0, (1 << 24) | (4 << 16), bhvWarpBox),
		OBJECT(MODEL_WARP_BOX, 6231, 743, -727, 0, 90, 0, (0 << 24) | (5 << 16), bhvWarpBox),
		TERRAIN(bits_area_3_collision),
		MACRO_OBJECTS(bits_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bits_area_4),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x06, LEVEL_BITS, 0x04, 0x06, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, 14883, 2796, 6086, 0, -14, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHUCKYA, -7504, 7321, -6087, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -7504, 7321, -4787, 0, -180, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 5396, -750, 13013, 0, 90, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_YELLOW_COIN, -8418, 7220, -4517, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -2726, 6871, -5002, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -15437, 9300, -8945, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -15842, 9300, -9641, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 11515, 3374, 1455, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 11515, 3664, 3397, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 12451, 3032, 3397, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 12751, 3032, 3397, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 13051, 3032, 3397, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 14150, 2582, 6838, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 15657, 2582, 7242, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 15257, 2582, 8742, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 13757, 2582, 8342, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4647, 2682, 13642, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4647, 2282, 13542, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4647, 1882, 13442, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_DOG, 3932, -748, 13288, 0, -180, 0, 0x00000000, bhvDogNPC),
		OBJECT(MODEL_BOWLING_BALL, -604, 7085, -4187, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 6506, 1986, 15222, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_FLYGUY, -604, 7513, -4187, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 7796, 1576, 15995, 0, -180, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FWOOSH, -4460, 6559, -5366, 0, -14, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_FWOOSH, 11940, 3459, 2034, 0, -90, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_FWOOSH, 15765, 2759, 8078, 0, -105, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_FWOOSH, 13639, 2759, 7509, 0, 75, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_GOOMBA, 1708, 6680, -4338, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8632, 1212, 14988, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4532, -748, 12588, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -9491, 6893, -5608, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_MONTY_MOLE, 14550, 2007, 4167, 0, -180, 0, (1 << 16), bhvMontyMole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 14550, 2007, 4167, 0, -180, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 13822, 1844, 4635, 0, -180, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, 14323, 2410, 4781, 0, -180, 0, 0x00000000, bhvMontyMoleHole),
		OBJECT(MODEL_BITS_OCTAGONAL_PLATFORM, -604, 6637, -4187, 0, 0, 0, 0x00000000, bhvOctagonalPlatformRotating),
		OBJECT(MODEL_RED_COIN, 4771, 2406, 15037, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_REX, -2735, 6939, -4334, 0, 0, 0, 0x00000000, bhvRex),
		OBJECT(MODEL_WARP_BOX, -16705, 9296, -10114, 0, 90, 0, (1 << 24) | (6 << 16), bhvWarpBox),
		OBJECT(MODEL_WARP_BOX, 3439, -68, 13091, 0, 90, 0, (0 << 24) | (7 << 16), bhvWarpBox),
		OBJECT(MODEL_WHOMP, 11508, 3375, 2558, 0, -180, 0, 0x00000000, bhvSmallWhomp),
		TERRAIN(bits_area_4_collision),
		MACRO_OBJECTS(bits_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 103, -14184, -2413, -2665),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
