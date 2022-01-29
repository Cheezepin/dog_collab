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
#include "levels/ddd/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ddd_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ddd_segment_7SegmentRomStart, _ddd_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ddd_segment_7SegmentRomStart, _ddd_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_WATER_TOP, water_top_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_WATER_SPOUT, water_spout_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RAIN_CLOUD, cloud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_APERATURE_DOOR, aperature_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FLOATY_ROCK, floaty_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHYGUY_SCUBA, shyguy_scuba_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ddd_area_1),
		WARP_NODE(0x0A, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x02, 0x02, 0, 10000, 0),
		OBJECT(MODEL_RAIN_CLOUD, -168, 8926, 2024, 0, 54, 0, (4 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 1317, 9228, -447, 0, 71, 0, (6 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 0, 8611, 0, 0, 16, 0, (255 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -636, 8955, -1292, 0, 59, 0, (4 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -218, 8354, 2574, 0, 144, 0, (0 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 139, 9233, -1958, 0, 61, 0, (160 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 1317, 9928, -447, 0, 33, 0, (3 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 1317, 10628, -447, 0, 57, 0, 0, bhvRainCloud),
		OBJECT(MODEL_RED_COIN, 137, 9957, -1954, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1317, 9520, -447, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1317, 10215, -447, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1317, 11478, -447, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -218, 8696, 2574, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -167, 9742, 1518, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -637, 9501, -1288, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 0, 3910, 0, 0, 0, 0, (1 << 24), bhvRedCoin),
		OBJECT(MODEL_NONE, 0, 9363, 0, 0, 0, 0, (1 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RAIN_CLOUD, -107, 8946, 1032, 0, 63, 0, (4 << 16), bhvRainCloud),
		OBJECT(MODEL_DDD_WATER_TOP, 0, 2550, 0, 0, 0, 0, 0, bhvWaterTop),
		OBJECT(MODEL_NONE, 0, 2760, 0, 0, 0, 0, (0x0A << 16), bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 2760, 0),
		OBJECT(MODEL_NONE, 0, -4000, 0, 0, 0, 0, (2 << 16), bhvVerticalInstantWarp),
		TERRAIN(ddd_area_1_collision),
		MACRO_OBJECTS(ddd_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_WATER),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ddd_area_2),
		WARP_NODE(0x0A, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x01, 0x01, 0, -10000, 0),
		INSTANT_WARP(0x02, 0x03, -20000, 0, 0),
		OBJECT(MODEL_DDD_APERATURE_DOOR, 0, 4965, 0, 0, 0, 0, 0, bhvAperatureDoor),
		OBJECT(MODEL_SHELL_BUBBLE, -52, 2318, 9, 0, 0, 0, 0x00000000, bhvBubbleShell),
		OBJECT(MODEL_SHELL_BUBBLE, 477, 1661, -2081, 0, 0, 0, 0x00000000, bhvBubbleShell),
		OBJECT(MODEL_SHELL_BUBBLE, 2103, 1929, -726, 0, 0, 0, 0x00000000, bhvBubbleShell),
		OBJECT(MODEL_SHELL_BUBBLE, 1867, 1526, -1361, 0, 0, 0, 0x00000000, bhvBubbleShell),
		OBJECT(MODEL_SHYGUY_SCUBA, 1434, 1889, -1841, 0, 0, 0, 0x00000000, bhvShyguyScuba),
		OBJECT(MODEL_NONE, 0, 6000, 0, 0, 0, 0, (1 << 24) | (1 << 16), bhvVerticalInstantWarp),
		OBJECT(MODEL_NONE, 3490, 960, -2257, 0, 0, 0, (2 << 16) | (5), bhvVerticalInstantWarp),
		TERRAIN(ddd_area_2_collision),
		MACRO_OBJECTS(ddd_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_WATER),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ddd_area_3),
		WARP_NODE(0xF0, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RAIN_CLOUD, -6196, -3162, -8787, 0, 158, 0, (0x2A << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -5138, -2961, -8444, 0, 46, 0, (0x2A << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -4236, -2811, -7568, 0, 158, 0, (1 << 24) | (0x50 << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -518, -2048, -5945, 0, 66, 0, (2 << 24) | (0xFF << 16), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 612, 4314, -7531, 0, 34, 0, (4 << 24) | (1 << 8), bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 6005, 1745, -471, 0, 167, 0, 0, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 6963, 2013, -439, 0, 79, 0, 0, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 10733, 2126, -2950, 0, 90, 0, (3 << 24) | (255 << 16), bhvRainCloud),
		OBJECT(MODEL_DDD_WATER_SPOUT, -13488, -3089, -2599, 0, 0, 0, 0, bhvWaterSpout),
		OBJECT(MODEL_FLOATY_ROCK, -11125, -3089, -3206, 0, 0, 0, 0x01000000, bhvFloatyRock),
		OBJECT(MODEL_DDD_WATER_SPOUT, -11125, -3823, -3206, 0, 0, 0, (1 << 24), bhvWaterSpout),
		OBJECT(MODEL_STAR, 12413, 7082, -2950, 0, 0, 0, (2 << 24), bhvStar),
		TERRAIN(ddd_area_3_collision),
		MACRO_OBJECTS(ddd_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_WATER),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 2760, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
