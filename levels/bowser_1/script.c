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
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/common1.h"
#include "actors/group12.h"

/* Fast64 begin persistent block [includes] */
#include "actors/common1.h"
#include "actors/group12.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bowser_1/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_1_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x7, _bowser_1_segment_7SegmentRomStart, _bowser_1_segment_7SegmentRomEnd), 
	LOAD_YAY0(/*seg*/ 0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd),
	/* Fast64 begin persistent block [level commands] */
    LOAD_YAY0(/*seg*/ 0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd),
    LOAD_RAW( /*seg*/ 0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_13),
	LOAD_MODEL_FROM_GEO(MODEL_GODDARD_CAGE, cage_geo), 
	//LOAD_MODEL_FROM_GEO(MODEL_BOWSER, bowser_geo),
	//LOAD_MODEL_FROM_GEO(MODEL_BOWSER_BOMB, bowser_bomb_geo),
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_1_area_1),
		OBJECT(MODEL_GODDARD_CAGE, 0, 403, 878, 0, 0, 0, 0x00000000, bhvGoddardCage),
		OBJECT(MODEL_BOWSER, 0, 403, -865, 0, 0, 0, 0x13001850, bhvBowser),
		OBJECT(MODEL_BOWSER_BOMB, 1024, 420, -875, 0, 0, 0, 0x00000000, bhvBowserBomb),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 451, 0),
		TERRAIN(bowser_1_area_1_collision),
		MACRO_OBJECTS(bowser_1_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0002, /*seq*/ SEQ_LEVEL_BOSS_KOOPA),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_BOWSER_1, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x24, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(/*area*/ 1, /*yaw*/ 180, /*pos*/ 0, 307, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
