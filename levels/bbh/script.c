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
#include "levels/bbh/header.h"

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _spooky_yay0SegmentRomStart, _spooky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BOUNCE_CLOUD, bounce_cloud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STRETCH_CLOUD, stretch_cloud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RAINBOW_CLOUD, rainbow_cloud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLOUD_RAINBOW, cloud_rainbow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RAIN_CLOUD, rain_cloud_geo), 

	AREA(1, bbh_area_1),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 100, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 50, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -15722, 176, 17790, 0, 130, 0, 0x000B0000, bhvAirborneDeathWarp),
		MARIO_POS(0x01, 130, -15722, 176, 17790),
		OBJECT(MODEL_NONE, -15722, 176, 17790, 0, 130, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_BOUNCE_CLOUD, -13182, 2710, -8158, 0, 16, 0, 0x00000000, bhvBounceCloud),
		OBJECT(MODEL_BOUNCE_CLOUD, -13763, 2710, -12009, 0, 9, 0, 0x00000000, bhvBounceCloud),
		OBJECT(MODEL_BOUNCE_CLOUD, -2766, 3013, -19512, 0, -90, 0, 0x00000000, bhvBounceCloud),
		OBJECT(MODEL_BOUNCE_CLOUD, -12998, 2710, -14613, 0, -38, 0, 0x00000000, bhvBounceCloud),
		OBJECT(MODEL_NONE, -2534, 169, 8678, 0, 0, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_NONE, -3009, 169, 11026, 0, 0, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_RAINBOW_CLOUD, 99, 169, 16179, 0, -180, 0, 0x00000000, bhvRainbowCloud),
		OBJECT(MODEL_RAINBOW_CLOUD, 1548, 169, 16477, 0, -60, 0, 0x00000000, bhvRainbowCloud),
		OBJECT(MODEL_RAIN_CLOUD, -12252, 1418, -2414, 0, 0, 0, 0x00000000, bhvRainCloud),
		OBJECT(MODEL_STAR, 3172, 4060, -19513, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STRETCH_CLOUD, 1206, 3394, -19505, 0, 0, 0, 0x00000000, bhvStretchCloud),
		OBJECT(MODEL_STRETCH_CLOUD, -4771, 3013, -17579, 0, 90, 0, 0x00000000, bhvStretchCloud),
		OBJECT(MODEL_STRETCH_CLOUD, -3671, 3013, -18779, 0, 90, 0, 0x00000000, bhvStretchCloud),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 130, -15722, 176, 17790),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
