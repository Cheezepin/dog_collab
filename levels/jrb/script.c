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

#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CIRCUS_WHEEL, 4138, 3548, -9205, 0, 0, 0, 0x00000000, bhvCircusWheel),
		OBJECT(MODEL_NONE, 6119, 4306, -9546, 0, 0, 0, 0x00000000, bhvWheelWind),
		OBJECT(MODEL_NONE, 2894, 5178, -9546, 0, 0, 0, 0x00000000, bhvWheelWind),
		MARIO_POS(0x01, 0, 6554, 100, -982),
		OBJECT(MODEL_STAR, 2284, 3341, -8754, 0, 0, 0, 0x00010000, bhvStar),
		OBJECT(MODEL_NONE, 6530, 100, -1006, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_CAROUSEL, 10529, 90, -790, 0, 0, 0, 0x00000000, bhvCarousel),
		OBJECT(MODEL_CAROUSEL, 13302, 375, -1656, 0, 68, 0, 0x00000000, bhvCarousel),
		OBJECT(MODEL_CAROUSEL, 13235, 954, 317, 0, 160, 0, 0x00000000, bhvCarousel),
		OBJECT(MODEL_CAROUSEL, 11998, 1327, -415, 0, -153, 0, 0x00000000, bhvCarousel),
		OBJECT(MODEL_NONE, 8432, 100, -773, 0, 0, 0, 0x00000000, bhvClownDoorSpawner),
		OBJECT(MODEL_STAR, 12007, 1765, -1450, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_CLOWN_CLOCK, 11319, 737, -1860, 0, 44, 0, 0x00000000, bhvClownClock),
		OBJECT(MODEL_CLOWN_CLOCK, 13671, 635, -37, 0, 49, 0, 0x00000000, bhvClownClock),
		OBJECT(MODEL_CLOWN_CLOCK, 11288, 239, -3267, 0, 0, -90, 0x00010000, bhvClownClock),
		OBJECT(MODEL_NONE, 10073, 100, -4096, 0, 90, 0, 0x00000000, bhvClownDoorSpawner),
		OBJECT(MODEL_PINWHEEL, 10356, -770, -6412, -90, 0, 0, 0x00010000, bhvPinwheel),
		OBJECT(MODEL_CIRCUS_POLE, 11062, 108, -5617, 0, 0, 0, 0x00360000, bhvPoleGrabbing),
		OBJECT(MODEL_PINWHEEL, 11062, 607, -5617, 0, 0, 0, 0x00000000, bhvPinwheel),
		OBJECT(MODEL_CIRCUS_POLE, 9162, 533, -7512, 0, 70, 0, 0x00360000, bhvPoleGrabbing),
		OBJECT(MODEL_PINWHEEL, 9162, 1032, -7512, 0, 38, 0, 0x00000000, bhvPinwheel),
		TERRAIN(jrb_area_1_collision),
		ROOMS(jrb_area_1_collision_rooms),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 6554, 100, -982),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
