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
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_WATER_TOP, water_top_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_WATER_SPOUT, water_spout_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RAIN_CLOUD, cloud_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ddd_area_1),
		WARP_NODE(0x0A, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DDD_WATER_TOP, 0, 6550, 0, 0, 0, 0, 0x00000000, bhvWaterTop),
		OBJECT(MODEL_DDD_WATER_SPOUT, 4435, 6707, -4106, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_DDD_WATER_SPOUT, 3852, 6710, -4897, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_NONE, 0, 6760, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 6760, 0),
		OBJECT(MODEL_RAIN_CLOUD, -460, 7042, -796, 0, 0, 0, 0x000A0000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 842, 7018, 1573, 0, 0, 0, 0x000A0000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -2451, 7106, 1263, 0, 0, 0, 0x000A0000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, -1528, 7638, 437, 0, 0, 0, 0x000A0000, bhvRainCloud),
		OBJECT(MODEL_RAIN_CLOUD, 2212, 7056, -1424, 0, 0, 0, 0x000A0000, bhvRainCloud),
		OBJECT(MODEL_DDD_WATER_SPOUT, 4968, 6718, -3429, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		OBJECT(MODEL_DDD_WATER_SPOUT, 3070, 6728, -5411, 0, 0, 0, 0x000A0000, bhvWaterSpout),
		TERRAIN(ddd_area_1_collision),
		MACRO_OBJECTS(ddd_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 6760, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
