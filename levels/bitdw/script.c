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
#include "levels/bitdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, geo_bitdw_0003C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, geo_bitdw_0003D8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, geo_bitdw_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, geo_bitdw_000408), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, geo_bitdw_000420), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, geo_bitdw_000438), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, geo_bitdw_000450), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, geo_bitdw_000468), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, geo_bitdw_000480), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, geo_bitdw_000498), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, geo_bitdw_0004B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, geo_bitdw_0004C8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, geo_bitdw_0004E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, geo_bitdw_0004F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, geo_bitdw_000510), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SQUARE_PLATFORM, geo_bitdw_000558), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SEESAW_PLATFORM, geo_bitdw_000540), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SLIDING_PLATFORM, geo_bitdw_000528), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_FERRIS_WHEEL_AXLE, geo_bitdw_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_BLUE_PLATFORM, geo_bitdw_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME4, geo_bitdw_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME3, geo_bitdw_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME2, geo_bitdw_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME1, geo_bitdw_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE, geo_bitdw_000600), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_RAINBOW_CHAIN, rainbow_chain_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SPHERE, sphere_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitdw_area_1),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOWSER_1, 0x01, 0x0A, WARP_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOWSER_1, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 10003, -4901, 8716, 0, 0, 0, 0x00000000, bhvPaletteSwap),
		OBJECT(MODEL_1UP, 2983, -2397, 9441, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_NONE, -8232, 2625, -12071, 0, 0, 0, 0x000C0000, bhvDeathWarp),
		OBJECT(0x1AA, 4695, 1864, -10724, 0, 0, 0, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, 2946, 1864, -10724, -90, 0, 180, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, 1196, 1864, -10724, 0, 0, 0, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -553, 1864, -10724, -90, 0, 180, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -2302, 1864, -10724, 0, 0, 0, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -4052, 1864, -10724, -90, 0, 180, 0x00000000, bhvRotatingTorus),
		OBJECT(MODEL_NONE, 12066, -3634, 9035, 0, -177, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 13445, -2750, 7083, 0, 1, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8184, -6670, 9553, 0, 143, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7530, -712, 6227, 0, 98, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5172, -2267, 7701, 0, 143, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4646, -3067, 8451, 0, 158, 0, 0x00040000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9566, -8006, 8940, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(0x1F8, 7293, 2183, -2412, 0, 0, 0, 0x00000000, bhvMotos),
		OBJECT(0x1F8, 5617, 2183, -507, 0, 0, 0, 0x00000000, bhvMotos),
		OBJECT(0x1F8, 7175, 2185, -4502, 0, 0, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_RED_COIN, 8794, -7708, 7870, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2773, -5151, 7939, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5740, -4239, 6650, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10814, -3699, 6327, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11807, -4675, 9919, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2952, -7559, 9150, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9420, -5534, 9033, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10513, -708, 8585, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(0x00, 8474, -773, 6268, 0, 0, 0, 0x00000000, bhvBowserCourseRedCoinStar),
		OBJECT(MODEL_YELLOW_COIN_NO_SHADOW, 6056, -1357, 6427, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3710, 370, 5772, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4191, 88, 6031, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4496, -200, 6101, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4908, -522, 6228, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5395, -845, 6326, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5693, -1149, 6360, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 12506, -3350, 8734, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(0x1AD, 11661, -3790, 5993, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 13049, -3784, 8795, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 10336, -4216, 6733, 0, 0, 0, 0x10000100, bhvSphere),
		OBJECT(0x1AD, 9413, -4216, 7982, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 10547, -3929, 8079, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 9628, -8621, 6650, 0, 0, 0, 0x10000100, bhvSphere),
		OBJECT(0x1AD, 10809, -7776, 7257, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 10556, -8174, 6159, 0, 0, 0, 0x10000100, bhvSphere),
		OBJECT(MODEL_NONE, -8248, 1268, -10689, 0, 0, 0, 0x600B0000, bhvWarp),
		TERRAIN(bitdw_area_1_collision),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
