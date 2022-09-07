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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_PALM_TREE, wf_palm_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_KOKO, koko_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_JETSKI, jetski_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_CRATE, crate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SANDPILE, sandpile_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_WF, 0x02, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -13552, 2083, 3010, 180, 0, 90, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -13552, 2083, 3010),
		OBJECT(MODEL_NONE, 12394, 3275, -11997, 0, 0, 0, (100 << 24) | (0x0D << 16), bhvWarp),
		OBJECT(MODEL_WF_CRATE, -13339, 1003, -1579, 0, 10, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, -13099, 1003, -1448, 0, -25, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, -13339, 1003, -1579, 0, 10, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 1197, 881, 17434, 1, 10, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 1172, 875, 17689, 1, 1, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 1199, 1080, 17551, 1, 10, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 1325, 861, 18749, 1, 4, 2, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 1336, 867, 18968, 1, -5, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 7262, 1433, 15162, 0, -17, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 7521, 1433, 15250, 0, -21, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 7765, 1433, 15327, 0, -11, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 8846, 948, -10195, 0, 15, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 8843, 948, -9939, 0, 6, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 8858, 1148, -10078, 0, 21, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 11808, 948, -7919, 0, 15, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 11804, 948, -7663, 0, 6, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 11594, 937, -7846, 0, 21, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_NONE, -12638, 1035, 5123, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 7826, 1035, -11854, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 13533, 1035, -4423, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 19305, 1035, 18867, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 10414, 1035, -8738, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_SANDPILE, -11532, 887, 9872, 1, 27, 0, 0x00000000, bhvSandPile),
		OBJECT(MODEL_EXCLAMATION_BOX, -8506, 1324, 1218, 0, 0, 0, (1 << 24) | (0x0B << 16), bhvWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, 18964, 2479, 17409, 0, 0, 0, (EXCLAMATION_BOX_BP_JETSKI << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 14778, 1316, -14873, 0, 0, 0, (EXCLAMATION_BOX_BP_JETSKI << 16), bhvExclamationBox),
		OBJECT(MODEL_HOOT, 6906, 1965, -12767, 0, 0, 0, 0x00000000, bhvHoot),
		OBJECT(MODEL_WF_PALM_TREE, -14248, 1004, -1846, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -12859, 1004, -640, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -13749, 1004, 5822, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -13670, 1004, 4489, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -12066, 1004, 4463, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 18543, 923, 19528, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 6906, 947, -12767, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 12511, 947, -7028, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 7650, 947, -10659, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 9485, 947, -8267, 0, 0, 0, 0x00000000, bhvPalmTree),
		TERRAIN(wf_area_1_collision),
		ROOMS(wf_area_1_collision_rooms),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(0x0D, LEVEL_WF, 0x02, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, -11125, -5623, 0, 0, 0, 0, (EXCLAMATION_BOX_BP_JETSKI << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, -11883, -5894, -13, 0, 0, 0, 0x000D0000, bhvSpinAirborneWarp),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_HOT),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, wf_area_3),
		WARP_NODE(0x0B, LEVEL_WF, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 1696, 0, 0, 0, 0, 0x000B0000, bhvSpinAirborneWarp),
		TERRAIN(wf_area_3_collision),
		MACRO_OBJECTS(wf_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -13552, 2083, 3010),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
