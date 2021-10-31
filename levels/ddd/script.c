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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ddd_area_1),
		WARP_NODE(0x0A, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x02, 0x02, 0, 10000, 0),
		OBJECT(MODEL_RAIN_CLOUD, -168, 8926, 2024, 0, 54, 0, 0x00040000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 1317, 9228, -447, 0, 71, 0, 0x00060000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 0, 8611, 0, 0, 16, 0, 0x00FF0000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -636, 8955, -1292, 0, 59, 0, 0x00040000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -218, 8354, 2574, 0, 144, 0, 0x00000000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 139, 9233, -1958, 0, 61, 0, 0x00A00000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 1317, 9928, -447, 0, 33, 0, 0x00030000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 1317, 10628, -447, 0, 57, 0, 0x00000000, bhvRainCloud),
		OBJECT(MODEL_RED_COIN, 137, 9957, -1954, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1317, 9520, -447, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1317, 10215, -447, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1317, 11478, -447, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -218, 8696, 2574, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -167, 9742, 1518, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -637, 9501, -1288, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 0, 3910, 0, 0, 0, 0, 0x01000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, 9363, 0, 0, 0, 0, 0x01000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_RAIN_CLOUD, -107, 8946, 1032, 0, 63, 0, 0x00040000, bhvRainCloud),
		OBJECT(MODEL_DDD_WATER_TOP, 0, 2550, 0, 0, 0, 0, 0x00000000, bhvWaterTop),
		OBJECT(MODEL_DDD_WATER_SPOUT, 4435, 2707, -4106, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_DDD_WATER_SPOUT, 3852, 2710, -4897, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_NONE, 0, 2760, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 2760, 0),
		OBJECT(MODEL_DDD_WATER_SPOUT, 4968, 2718, -3429, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_DDD_WATER_SPOUT, 3070, 2728, -5411, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_NONE, 0, -4000, 0, 0, 0, 0, 0x00020000, bhvVerticalInstantWarp),
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
		OBJECT(MODEL_DDD_APERATURE_DOOR, 0, 4965, 0, 0, 0, 0, 0x00000000, bhvAperatureDoor),
		OBJECT(MODEL_NONE, 0, 6000, 0, 0, 0, 0, 0x01010000, bhvVerticalInstantWarp),
		OBJECT(MODEL_NONE, 3873, -116, -3227, 0, 0, 0, 0x00020000, bhvVerticalInstantWarp),
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
