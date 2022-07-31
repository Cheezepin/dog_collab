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
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 

	/* Fast64 begin persistent block [level commands] */
	LOAD_YAY0(0x05, _group2639_yay0SegmentRomStart, _group2639_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2639_geoSegmentRomStart, _group2639_geoSegmentRomEnd), 
	LOAD_MODEL_FROM_GEO(MODEL_2639COUCH, couch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ELEV2639, elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639SODA, soder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_2639TURNSTILE, turnstile_geo), 
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 2, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 2726, -2592, 4711, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		OBJECT(MODEL_NONE, -476, -2125, -3381, 0, 0, 0, (0x30 << 24) | (01 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -434, -1734, -406, 0, 0, 0, (1 << 16), bhv2639pc2_targetobj),
		OBJECT(MODEL_2639TURNSTILE, -404, -1727, -1747, 0, 0, 0, 0x00000000, bhvEntranceturnstile),
		OBJECT(MODEL_NONE, 1728, -2348, 4766, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 1728, -2348, 4766),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_MUSIC2639),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		// PUPPYVOLUME_COMPAT(0),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 3, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 4, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 5, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 6, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT_WITH_ACTS(MODEL_NONE, -1597, 117, -2849, 0, 0, 0, 0x00000000, bhv2639cane, ACT_1),
		OBJECT_WITH_ACTS(MODEL_NONE, 1558, 117, -2861, 0, 0, 0, 0x00000000, bhv2639glasses, ACT_1),
		OBJECT_WITH_ACTS(MODEL_TOAD, 1135, 1, 1058, 0, 0, 0, (_2639DIAG_A1LobbyToadGreeter << 24), bhvToadMessage, ACT_1),
		OBJECT(MODEL_DOG, -275, 0, 2726, 0, 0, 0, 0x00000000, bhvDoginlobby),
		OBJECT_WITH_ACTS(MODEL_TOAD, -134, 1, 1772, 0, 0, 0, (_2639DIAG_A1LobbyNPCSuggester << 24), bhvToadMessage, ACT_1),
		OBJECT(MODEL_NONE, -25, 1058, -280, 0, 0, 0, 0x00000000, bhv2639pc2_targetobj),
		OBJECT(MODEL_NONE, -8, 2, -1945, 0, 0, 0, (11 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_2639SODA, 1689, 0, -1375, 0, 0, 0, 0x00000000, bhv2639soda),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -5, 0, -2848, 0, 0, 0, 0x00000000, bhv2639elevator, ACT_2),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -5, 0, -2848, 0, 0, 0, (1 << 16), bhv2639elevator, ACT_3),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -5, 0, -2848, 0, 0, 0, (2 << 16), bhv2639elevator, ACT_4),
		OBJECT_WITH_ACTS(MODEL_ELEV2639, -5, 0, -2848, 0, 0, 0, (3 << 16), bhv2639elevator, ACT_6),
		OBJECT(MODEL_NONE, -489, 116, 2261, 0, 0, 0, (0xA << 16), bhvSpinAirborneWarp),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_MUSIC2639),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		// PUPPYVOLUME_COMPAT(1),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 2, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 2795, -229, 3759, 0, 0, 0, 0x00000000, bhvDogfloor1),
		OBJECT(MODEL_2639COUCH, -4462, -228, -742, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -2656, -228, -972, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -3734, -228, 1749, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -2026, -228, 789, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_2639COUCH, -3947, -228, 686, 0, 0, 0, 0x00000000, bhvA2pushablecouch),
		OBJECT(MODEL_NONE, -3528, 139, 195, 0, 0, 0, 0x00000000, bhv2639a2hiddenstar),
		OBJECT(MODEL_ELEV2639, 4383, -229, 535, 0, 0, 0, (1 << 24) | (10 << 16), bhv2639elevator),
		OBJECT(MODEL_NONE, 2475, 0, 3809, 0, 0, 0, (10 << 16), bhvSpinAirborneWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_MUSIC2639),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bob_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 2, 11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 1812, 956, 2277, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		OBJECT(MODEL_2639SODA, -2226, -2292, -1375, 0, 0, 0, 0x00000000, bhv2639soda),
		OBJECT(MODEL_TOAD, -3262, -218, -1309, 0, 0, 0, (_2639DIAG_A3RoomToadGibSoda << 24), bhvToadMessage),
		OBJECT(MODEL_ELEV2639, 3099, -229, 535, 0, 0, 0, (1 << 24) | (1 << 16), bhv2639elevator),
		OBJECT(MODEL_NONE, 663, 661, 0, 0, 0, 0, (10 << 16), bhvSpinAirborneWarp),
		TERRAIN(bob_area_4_collision),
		MACRO_OBJECTS(bob_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_MUSIC2639),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, bob_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 0x01, 11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 342, 956, 4711, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		OBJECT(MODEL_ELEV2639, 4830, -489, 535, 0, 0, 0, (1 << 24) | (0 << 16), bhv2639elevator),
		TERRAIN(bob_area_5_collision),
		MACRO_OBJECTS(bob_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_MUSIC2639),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, bob_area_6),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DOG, 1925, 956, 2889, 0, 0, 0, 0x00000000, bhvDogoutsidehotel),
		OBJECT(MODEL_NONE, 2126, 1258, 1956, 0, 0, 0, (10 << 16), bhvSpinAirborneWarp),
		TERRAIN(bob_area_6_collision),
		MACRO_OBJECTS(bob_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_MUSIC2639),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 1728, -2348, 4766),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
