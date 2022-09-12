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
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_PALM_TREE, wf_palm_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_KOKO, koko_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_JETSKI, jetski_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_CRATE, crate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SANDPILE, sandpile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAND_PILLAR, sand_pillar_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_WF, 0x02, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -6743, 1404, 1534, 180, 0, 90, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -6743, 1404, 1534),
		OBJECT(MODEL_NONE, 6215, 3194, -5966, 0, 0, 0, (50 << 24) | (0x0D << 16), bhvWarp),
		OBJECT(MODEL_WF_CRATE, -6669, 845, -789, 0, 10, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, -6549, 845, -724, 0, -25, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, -6669, 845, -789, 0, 10, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 559, 785, 8643, 1, 10, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 585, 781, 8872, 1, 1, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 538, 984, 8774, 1, 10, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 614, 774, 9351, 1, 4, 2, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 628, 778, 9598, 1, -5, 5, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 3522, 1061, 7590, 0, -17, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 3741, 1061, 7655, 0, -21, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 3961, 1061, 7706, 0, -11, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 4423, 818, -5097, 0, 15, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 4421, 818, -4970, 0, 6, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 4429, 918, -5039, 0, 21, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 5904, 818, -3960, 0, 15, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 5902, 818, -3832, 0, 6, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_WF_CRATE, 5797, 813, -3923, 0, 21, 0, (BREAKABLE_BOX_BP_3_COINS << 16), bhvBreakableBox),
		OBJECT(MODEL_NONE, -6319, 861, 2561, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 3913, 861, -5927, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 6767, 861, -2212, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 9652, 861, 9434, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_NONE, 5207, 861, -4369, 0, 0, 0, 0x00000000, bhvKokoTripletSpawner),
		OBJECT(MODEL_SANDPILE, -4441, 787, 7891, 1, 27, 0, (8 << 8), bhvSandPile),
		OBJECT(MODEL_SANDPILE, -4943, 787, 7589, 1, 27, 0, (15 << 8), bhvSandPile),
		OBJECT(MODEL_SANDPILE, -4887, 787, 6946, 1, 27, 0, (20 << 8), bhvSandPile),
		OBJECT(MODEL_SANDPILE, -5292, 787, 6228, 1, 27, 0, (25 << 8), bhvSandPile),
		OBJECT(MODEL_EXCLAMATION_BOX, -4253, 1006, 609, 0, 0, 0, (1 << 24) | (0x0B << 16), bhvWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, 9482, 1583, 8705, 0, 0, 0, (EXCLAMATION_BOX_BP_JETSKI << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 7389, 1002, -7436, 0, 0, 0, (EXCLAMATION_BOX_BP_JETSKI << 16), bhvExclamationBox),
		OBJECT(MODEL_HOOT, 3453, 1326, -6383, 0, 0, 0, 0x00000000, bhvHoot),
		OBJECT(MODEL_WF_PALM_TREE, -7124, 846, -923, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -6430, 846, -320, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -6874, 846, 2911, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -6835, 846, 2245, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, -6033, 846, 2231, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 9272, 806, 9764, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 3453, 817, -6383, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 6255, 817, -3514, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 3825, 817, -5329, 0, 0, 0, 0x00000000, bhvPalmTree),
		OBJECT(MODEL_WF_PALM_TREE, 4743, 817, -4133, 0, 0, 0, 0x00000000, bhvPalmTree),
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
		OBJECT(MODEL_BULLY_BOSS, 590, -438, 0, 0, 0, 0, 0x000D0000, bhvBigBully),
		OBJECT(MODEL_EXCLAMATION_BOX, -5563, -2562, 0, 0, 0, 0, (EXCLAMATION_BOX_BP_JETSKI << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, -5942, -2697, -6, 0, 0, 0, 0x000D0000, bhvSpinAirborneWarp),
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
	MARIO_POS(0x01, 0, -6743, 1404, 1534),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
