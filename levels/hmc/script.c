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
#include "levels/hmc/header.h"

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_WOODEN_DOOR, wooden_door_geo), 

	AREA(1, hmc_area_1),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 341, 1491, -732, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_NONE, 583, -85, -859, 0, 0, 0, 0x00000000, bhvFazAmbient),
		TERRAIN(hmc_area_1_collision),
		ROOMS(hmc_area_1_collision_rooms),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SNOW),
	END_AREA(),

	AREA(2, hmc_area_2),
		OBJECT(MODEL_HMC_METAL_DOOR, -1031, 5889, -3768, 0, 0, 0, 0x00000000, bhvDoor),
		MARIO_POS(0x02, 0, -179, 4215, -946),
		OBJECT(MODEL_RED_COIN, -3238, 4730, -1577, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_TRANSPARENT_STAR, -4315, 4208, -2658, 0, 0, 0, 0x00000000, bhvRedCoinStarMarker),
		OBJECT(MODEL_RED_COIN, -3352, 5373, -1309, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4016, 4701, 905, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2374, 4215, 1168, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3701, 5739, -288, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3685, 4683, -3357, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2390, 5889, 1113, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3763, 5819, -2304, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -4315, 4543, -2658, 0, 0, 0, 0x02000000, bhvHiddenRedCoinStar),
		TERRAIN(hmc_area_2_collision),
		ROOMS(hmc_area_2_collision_rooms),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x02, 0, -179, 4215, -946),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
