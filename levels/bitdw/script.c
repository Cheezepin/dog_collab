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
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_ELECTRIC_SPINNER, electric_spinner_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SIMPLE_SPINNER, simple_spinner_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SPHERE, sphere_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitdw_area_1),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(3, 0x02, 8000, 15000, 20000),
		INSTANT_WARP(0, 0x02, 0, 0, 0),
		OBJECT(0x1AB, -3132, 1006, 4606, 0, 49, 0, 0x0FFFFFFF, bhvElectricSpinner),
		OBJECT(0x1AB, -6000, 19, 1806, 0, 21, 0, 0x10F000FF, bhvElectricSpinner),
		OBJECT(0x1AB, -6619, -1089, -1377, 0, -9, 0, 0x00000FFF, bhvElectricSpinner),
		OBJECT(0x1AB, -6538, -1192, -1872, 0, -9, 0, 0x10000FFF, bhvElectricSpinner),
		OBJECT(0x1AB, 161, 1157, 5363, 0, 90, 0, 0x000000FF, bhvElectricSpinner),
		OBJECT(MODEL_NONE, 11951, -3584, 8790, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 10003, -4901, 8716, 0, 0, 0, 0x00000000, bhvPaletteSwap),
		OBJECT(MODEL_RED_COIN, 8794, -7708, 7870, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2773, -5713, 7939, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4869, -3894, 6288, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3521, -3977, 6327, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11686, -4624, 9919, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2952, -7559, 9150, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9420, -5534, 9033, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7117, -708, 6268, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(0x00, 8474, -773, 6268, 0, 0, 0, 0x00000000, bhvBowserCourseRedCoinStar),
		OBJECT(0x1AD, 11661, -3790, 5993, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 13049, -3784, 8795, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 10336, -4216, 6733, 0, 0, 0, 0x10000100, bhvSphere),
		OBJECT(0x1AD, 9413, -4216, 7982, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 10547, -3929, 8079, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 9628, -8428, 6650, 0, 0, 0, 0x10000100, bhvSphere),
		OBJECT(0x1AD, 10809, -7776, 7257, 0, 0, 0, 0x00000100, bhvSphere),
		OBJECT(0x1AD, 10556, -8142, 6159, 0, 0, 0, 0x10000100, bhvSphere),
		TERRAIN(bitdw_area_1_collision),
		ROOMS(bitdw_area_1_collision_rooms),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bitdw_area_2),
		INSTANT_WARP(3, 0x01, 0, 0, 0),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x25, WARP_NO_CHECKPOINT),
		OBJECT(0x1AA, 961, -7329, -2930, 0, -180, 0, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -788, -7329, -2930, 180, 0, -90, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -2538, -7329, -2930, 0, -180, 0, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -4287, -7329, -2930, 180, 0, -90, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -6036, -7329, -2930, 0, -180, 0, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1AA, -7786, -7329, -2930, 180, 0, -90, 0x00000000, bhvRotatingTorus),
		OBJECT(0x1F8, 13822, 3712, -1515, 0, 0, 0, 0x00000000, bhvMotos),
		OBJECT(0x1F8, 14699, 3752, -4227, 0, 0, 0, 0x00000000, bhvMotos),
		OBJECT(0x1F8, 12950, 3752, -6861, 0, 0, 0, 0x00000000, bhvMotos),
		OBJECT(0x1AD, 11274, -3966, -3927, 0, 0, 0, 0x10000300, bhvSphere),
		OBJECT(0x1AD, 8286, 3698, -5630, 0, 0, 0, 0x00000300, bhvSphere),
		OBJECT(0x1AC, 11274, 3060, -3927, 0, 0, 0, 0x00000100, bhvSimpleSpinner),
		OBJECT(0x1AC, 11274, 948, -3927, 0, 0, 0, 0x00000100, bhvSimpleSpinner),
		OBJECT(0x1AC, 11274, 2056, -3927, 0, 0, 0, 0x10000300, bhvSimpleSpinnerShock),
		OBJECT(0x1AC, 11274, -55, -3927, 0, 0, 0, 0x10000300, bhvSimpleSpinnerShock),
		OBJECT(0x1AC, 11274, -1071, -3927, 0, 0, 0, 0x00000100, bhvSimpleSpinner),
		OBJECT(0x1AC, 11274, -2074, -3927, 0, 0, 0, 0x10000300, bhvSimpleSpinnerShock),
		TERRAIN(bitdw_area_2_collision),
		MACRO_OBJECTS(bitdw_area_2_macro_objs),
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
