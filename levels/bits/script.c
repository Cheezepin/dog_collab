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
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_WARP_BOX, warpbox_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ASHPILE, ashpile_geo), 
	/*LOAD_MODEL_FROM_GEO(MODEL_PROPANE_THROWER, propane_thrower_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RMINE, ashpile_geo), */

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BITS, 0x02, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_ASHPILE, 5107, -1291, 1541, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -351, 3079, 1488, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -1091, 3079, 1171, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -3147, 3779, 1549, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -3376, 3779, 1193, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -4810, 8302, 2420, 0, 0, 0, 0x00000000, bhvAshpile),
		/*OBJECT(MODEL_PROPANE_THROWER, 8462, -1553, 1995, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 3373, -1231, 4447, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 4373, -1231, 4447, 0, 0, 0, 0x00010000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 2953, -22, 5934, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 1369, 2045, 5934, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 314, 2045, 5934, 0, 0, 0, (1 << 16), bhvPropaneThrower),
		OBJECT(MODEL_RMINE, 2811, -1231, 3882, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 2811, -1231, 3295, 0, 0, 0, 0x00000000, bhv_rmine),*/
		OBJECT(MODEL_MOTOS, 1379, 1012, 2146, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, 3532, -22, 4860, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, -1282, 3079, 1389, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_PURPLE_SWITCH, 1897, 1012, 1302, 0, 0, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_RED_COIN, 1346, 1064, -308, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 10462, -1318, 2460, 0, 0, 0, (0xA << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_WARP_BOX, -8194, 8502, 2435, 0, 0, 0, (1 << 16), bhvWarpBox),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bits_area_2),
		WARP_NODE(0x0A, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BITS, 0x02, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(0x1F6, -1303, 0, 0, 0, 0, 0, (0 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, -7177, 0, 0, 0, 0, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, 4, 0, -1428, 0, 90, 0, 0x00000000, bhvLaserRingSpawner),
		OBJECT(0x1F6, -4858, 0, -1086, 0, 0, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, 1379, 0, 3, 0, -180, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, -4824, 0, 555, 0, 0, 0, (1 << 16), bhvLaserRingSpawner),
		OBJECT(0x1F6, -3, 0, 1417, 0, -90, 0, 0x00000000, bhvLaserRingSpawner),
		OBJECT(MODEL_BITS_WARP_PIPE, 6246, 518, -729, 0, 0, 0, (0xB << 16), bhvWarpPipe),
		OBJECT(MODEL_RED_COIN, 4, 904, 3, 0, -180, 0, (1 << 16), bhvRedCoin),
		OBJECT(MODEL_WARP_BOX, -9853, 177, 10, 0, 0, 0, (1 << 24) | (2 << 16), bhvWarpBox),
		TERRAIN(bits_area_2_collision),
		MACRO_OBJECTS(bits_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
