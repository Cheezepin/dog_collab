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
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_CLOWN_CLOCK, b3_clown_clock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BALLOON_PLATFORM, b3_balloon_platform_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CAROUSEL, b3_carousel_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLOWN_DOOR_TOP, b3_clown_door_top_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLOWN_DOOR_BOTTOM, b3_clown_door_bottom_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PINWHEEL, b3_pinwheel_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TRAPEZE, b3_trapeze_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CIRCUS_BALLOON, b3_balloon_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BALLOON_PLATFORM, 8899, -1279, -4849, 0, 18, 0, 0x00000000, bhvB3BalloonPlatform),
		OBJECT(MODEL_BALLOON_PLATFORM, 9763, -878, -4849, 0, -22, 0, 0x00000000, bhvB3BalloonPlatform),
		OBJECT(MODEL_BALLOON_PLATFORM, 9321, -1100, -4605, 0, 65, 0, 0x00000000, bhvB3BalloonPlatform),
		OBJECT(MODEL_PINWHEEL, 10682, -743, -5588, -90, 0, 0, 0x00030000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 10914, 390, -6297, -90, 0, 0, 0x00030000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 11448, 1211, -5200, -90, 0, 0, 0x00030000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 11712, -1111, -6394, -90, 0, 0, 0x00030000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 12277, -1170, -4999, -90, 0, 0, 0x00030000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 10952, -1248, -4475, -90, 0, 0, 0x00030000, bhvPinwheel),
		OBJECT(MODEL_CAROUSEL, 3322, 130, 179, 0, 68, 0, 0x00000000, bhvB3Carousel),
		OBJECT(MODEL_CAROUSEL, 4058, 61, 565, 0, 132, 0, 0x00000000, bhvB3Carousel),
		OBJECT(MODEL_CAROUSEL, 4764, -57, 36, 0, -158, 0, 0x00000000, bhvB3Carousel),
		OBJECT(MODEL_CIRCUS_BALLOON, 10976, -13, 1314, 0, 0, 0, 0x00000000, bhvCircusBalloon),
		OBJECT(MODEL_CIRCUS_BALLOON, 5924, 506, -7354, 0, 0, 0, 0x00000000, bhvCircusBalloon),
		OBJECT(MODEL_CIRCUS_BALLOON, 14311, 2451, -7278, 0, 0, 0, 0x00000000, bhvCircusBalloon),
		OBJECT(MODEL_NONE, -243, 846, 136, 0, -180, 0, 0x00000000, bhvClownDoorSpawner),
		OBJECT(MODEL_NONE, 796, 407, 165, 0, -180, 0, 0x00000000, bhvClownDoorSpawner),
		OBJECT(MODEL_NONE, 1732, 215, 196, 0, -180, 0, 0x00000000, bhvClownDoorSpawner),
		OBJECT(MODEL_CLOWN_CLOCK, 6964, -893, -2763, 0, 0, -90, 0x00010000, bhvB3ClownClock),
		OBJECT(MODEL_PINWHEEL, 9633, 2016, -5040, 0, 90, 0, 0x00020000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 13029, 2028, -4977, 0, -90, 0, 0x00020000, bhvPinwheel),
		OBJECT(MODEL_CIRCUS_BALLOON, 9972, 1679, -5040, 0, 0, 0, 0x00010000, bhvCircusBalloon),
		OBJECT(MODEL_PINWHEEL, 11419, 2109, -7112, 0, 0, 0, 0x00020000, bhvPinwheel),
		OBJECT(MODEL_PINWHEEL, 11443, 2059, -3533, 0, -180, 0, 0x00020000, bhvPinwheel),
		OBJECT(MODEL_CIRCUS_BALLOON, 11460, 1772, -3691, 0, 0, 0, 0x00020000, bhvCircusBalloon),
		MARIO_POS(0x01, 0, -5744, 4573, 10),
		OBJECT(MODEL_TRAPEZE, 15585, 2962, -2173, 0, -180, 0, 0x00000000, bhvTrapeze),
		OBJECT(MODEL_TRAPEZE, 17764, 3132, -2173, 0, -180, 0, 0x00000000, bhvTrapeze),
		OBJECT(MODEL_NONE, -5740, 4669, 10, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bits_area_1_collision),
		ROOMS(bits_area_1_collision_rooms),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -5744, 4573, 10),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
