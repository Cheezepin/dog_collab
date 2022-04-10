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
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"
#include "actors/group2639.h"

/* Fast64 begin persistent block [includes] */
#include "actors/group2639.h"
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
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 

	/* Fast64 begin persistent block [level commands] */
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODER, soder_geo), 
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 2726, -2592, 4711, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		OBJECT(MODEL_NONE, 0, -2373, 5064, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, -2373, 5064),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 1021, -2592, 4711, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 73, -2592, 4711, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bob_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 342, -2592, 4711, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		TERRAIN(bob_area_4_collision),
		MACRO_OBJECTS(bob_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, -2373, 5064),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
