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
#include "actors/group2639.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, -4023, -4142, 186, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		MARIO_POS(0x01, 0, -4066, -4007, 0),
		OBJECT(MODEL_NONE, -2780, -4157, -2592, 0, 0, 0, 0x10010000, bhvWarp),
		OBJECT(MODEL_NONE, -4089, -3991, 30, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 3, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -2375, 77, 687, 0, 0, 0, 1 << 16, bhv2639elevator, ACT_2),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -2375, 77, 687, 0, 0, 0, 2 << 16, bhv2639elevator, ACT_3),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -2375, 77, 687, 0, 0, 0, 1 << 16, bhv2639elevator, ACT_4),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -2375, 77, 687, 0, 0, 0, 1 << 16, bhv2639elevator, ACT_5),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -2375, 77, 687, 0, 0, 0, 1 << 16, bhv2639elevator, ACT_6),
		OBJECT(MODEL_1UP, -406, 77, 381, 0, 0, 0, 0x00000000, bhv2639cane),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT_WITH_ACTS(MODEL_TOAD, 1158, 76, 1107, 0, 51, 0, _2639DIAG_A1LobbyNPCSuggester << 24, bhvToadMessage, ACT_1),
		OBJECT_WITH_ACTS(MODEL_TOAD, 2165, 376, -34, 0, 0, 0, _2639DIAG_A1LobbyToadGreeter << 24, bhvToadMessage, ACT_1),
		OBJECT_WITH_ACTS(MODEL_1UP, -1195, 77, -309, 0, 0, 0, 0x00000000, bhv2639glasses, ACT_1),
		OBJECT(MODEL_NONE, 1952, 211, 2906, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -521, 253, 62, 0, 0, 0, 0x01000000, bhv2639a2hiddenstar),
		OBJECT(MODEL_2639COUCH, -1458, -44, -2222, 0, -90, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -2084, -44, -1222, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -2071, -44, 761, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -777, -44, 2389, 0, 90, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -234, -44, 44, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_DOG, 226, -47, 1163, 0, 0, 0, 0x00000000, bhvDogfloor1),
		MARIO_POS(0x01, 0, -999, 10, 0),
		OBJECT(MODEL_NONE, 1649, 101, 1927, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -999, 10, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
