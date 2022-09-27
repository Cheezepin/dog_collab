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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ssl_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ssl_geo_0005D8), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_TOP, ssl_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_GRINDEL, ssl_geo_000734), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_SPINDEL, ssl_geo_000764), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_MOVING_PYRAMID_WALL, ssl_geo_000794), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_ELEVATOR, ssl_geo_0007AC), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_TOX_BOX, ssl_geo_000630), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x01, 0, 46, 0),
		INSTANT_WARP(0x01, 0x03, 0, 0, 0),
		INSTANT_WARP(0x02, 0x01, 0, 180, 0),
		INSTANT_WARP(0x03, 0x02, 0, 0, 0),
		OBJECT(MODEL_NONE, 2017, -2718, 2106, 0, 23, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2701, 485, -3187, 0, 72, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2710, 485, -5043, 0, 72, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4481, -2496, 6164, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -536, 772, 9268, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 28, -1699, -1723, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1119, -17, -5161, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5462, 3259, -2345, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -8139, 3067, 2727, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 289, 1401, 5407, 0, -59, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 634, -1419, 6006, 0, -86, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2992, 1401, 7380, 0, -59, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7847, 5409, -3171, 0, 16, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4772, 616, 3590, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6192, 485, -2055, 0, 72, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5483, 4146, 1460, 0, -62, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3075, -2718, 1654, 0, 23, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5296, 5334, 286, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7277, 4153, 427, 0, -62, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7867, 4675, 112, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_DOG, 3961, -2563, 6546, 0, 129, 0, 0x00000000, bhvSpiresDog),
		OBJECT(MODEL_DOG, -9408, 3023, 3022, 0, 129, 0, (1 << 16), bhvSpiresDog),
		OBJECT(MODEL_STAR, 2605, 7235, 1978, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15915, 3570, -2063, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, -8260, 2234, 12161, 0, -25, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_STAR, 5461, 510, 9621, 0, -25, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_NONE, -3, -7637, 6, 0, 30, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 30, -3, -7637, 6),
		TERRAIN(ssl_area_1_collision),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_METEOR_HERD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ssl_area_2),
		WARP_NODE(0x0A, LEVEL_SSL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x03, 0x01, 0, 0, 0),
		OBJECT(MODEL_YELLOW_COIN, -4979, 1010, 10935, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -8607, 1203, 8527, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -8166, 2044, 10899, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -6901, 2271, 7431, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -5396, 2271, 8995, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, -4979, 1010, 10935, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -8607, 1203, 8527, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -8166, 2044, 10899, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -4702, 1395, 8750, 0, 0, 0, (3 << 24), bhvHiddenStar),
		OBJECT(MODEL_NONE, -6901, 2271, 7431, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -5396, 2271, 8995, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -4835, 1119, 8453, 0, 30, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ssl_area_2_collision),
		ROOMS(ssl_area_2_collision_rooms),
		MACRO_OBJECTS(ssl_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_METEOR_HERD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ssl_area_3),
		WARP_NODE(0x0A, LEVEL_SSL, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x01, 0, 46, 0),
		INSTANT_WARP(0x01, 0x01, 0, 0, 0),
		INSTANT_WARP(0x02, 0x03, 0, 26, 0),
		INSTANT_WARP(0x03, 0x01, 0, 0, 0),
		OBJECT(MODEL_RED_COIN, 13180, -2261, 426, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 13180, 527, 426, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11925, 506, -2522, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12355, 2345, -2405, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11549, 2345, -2602, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11872, -3374, -2369, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8734, 4732, -886, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11530, 4355, -2430, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 11076, -1639, -656, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 9458, 443, -986, 0, 30, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 30, 9458, 443, -986),
		TERRAIN(ssl_area_3_collision),
		MACRO_OBJECTS(ssl_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_METEOR_HERD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 30, 9458, 443, -986),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
