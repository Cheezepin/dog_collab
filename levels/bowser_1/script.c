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
/* Fast64 begin persistent block [includes] */
#include "actors/common1.h"
#include "actors/group0.h"
#include "actors/group12.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bowser_1/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_1_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x7, _bowser_1_segment_7SegmentRomStart, _bowser_1_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_MIO0(0x7, _bowser_1_segment_7SegmentRomStart, _bowser_1_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 

	/* Fast64 begin persistent block [level commands] */
    LOAD_YAY0(/*seg*/ 0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd),
    LOAD_RAW( /*seg*/ 0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_13),
	LOAD_MODEL_FROM_GEO(MODEL_AMP,                     dAmpGeo),
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_ELECTRIC_RING,    electric_ring_geo),
	LOAD_MODEL_FROM_GEO(MODEL_GODDARD_CAGE, cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ASHPILE, emu_ashpile_geo), 
    LOAD_MODEL_FROM_GEO(MODEL_ASHPILE2, emu_ashpile2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_EMU_LASER_RING, laser_ring),
	LOAD_MODEL_FROM_GEO(MODEL_RED_CIRCLE, circle_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LIGHTNING, lightning_geo),
	LOAD_MODEL_FROM_GEO(MODEL_STAR,                    rainbow_star_geo),
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_1_area_1),
		OBJECT(MODEL_ASHPILE, 3633, 95, -105, 0, 0, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, 0, 95, -3737, 0, 90, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, -3632, 95, -105, 0, -180, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, 0, 95, 3528, 0, -90, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, 2569, 95, -2673, 0, 45, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, 2569, 95, 2464, 0, -45, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, -2568, 95, -2673, 0, 135, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_ASHPILE, -2568, 95, 2464, 0, -135, 0, (0 << 16), bhvAshpileEmu),
		OBJECT(MODEL_BOWSER, 0, 403, 649, 0, 0, 0, 0x13001850, bhvBowser),
		OBJECT(MODEL_GODDARD_CAGE, 0, 568, 3356, 0, 0, 0, 0x00000000, bhvGoddardCage),
		OBJECT(MODEL_NONE, 0, -421, 0, 0, 0, 0, 0x00000000, bhvPaletteSwap),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 451, 0),
		TERRAIN(bowser_1_area_1_collision),
		MACRO_OBJECTS(bowser_1_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BOWSER_GALAXY),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_BOWSER_1, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x24, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 451, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
