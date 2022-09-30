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
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _wdw_skybox_yay0SegmentRomStart, _wdw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM, wdw_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT, wdw_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM, wdw_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_EXPRESS_ELEVATOR, wdw_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, wdw_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ROTATING_PLATFORM, wdw_geo_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_MAPLETREE, mapletree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAKSEED, sakseed_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHERRY_TREE, cherry_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TREE_NUT, tree_seed_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DIRT_PILE, dirt_patch_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUE_COIN, 7576, 674, -5418, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 7174, 674, -5786, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6718, 674, -6126, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6237, 674, -6437, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 5664, 869, -6437, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 7688, 502, -4600, 0, 0, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BLOOPER, 539, 1236, -631, 0, -42, 0, 0x00000000, bhvBlooper),
		OBJECT(MODEL_NONE, 5210, 622, -4530, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6060, 1612, -3009, 0, -47, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1097, 1689, 175, 0, -60, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1634, 3326, -1880, 0, -67, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4688, 3326, -6299, 0, -70, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3240, 2089, 941, 0, -19, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5101, 1729, 2016, 0, -115, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5080, 1893, 3302, 0, -147, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1634, 2159, 4113, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -86, 2708, 5765, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1652, 1986, -610, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4038, 4529, -4123, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5600, 3813, -1585, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3087, 2089, -1487, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4514, 3970, -3096, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5790, 3326, -5253, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5916, 506, -4760, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3587, 2089, -1472, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1652, 827, -610, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_DIRT_PILE, -3066, 2089, -881, 0, 0, 0, (4 << 16), bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, 369, 2089, -2182, 0, 0, 0, (4 << 16), bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, 4610, 2089, -1982, 0, 0, 0, (4 << 16), bhvDirtPile),
		OBJECT(MODEL_GALOOMBA, -2972, 2089, -1468, 0, -42, 0, 0x00000000, bhvGaloomba),
		OBJECT(MODEL_GALOOMBA, -1121, 2089, -3940, 0, 68, 0, 0x00000000, bhvGaloomba),
		OBJECT(MODEL_GALOOMBA, 2329, 1689, -196, 0, -42, 0, 0x00000000, bhvGaloomba),
		OBJECT(MODEL_NONE, -2970, 2089, -1485, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -2294, 3326, -2800, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -4955, 4150, -4359, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 6408, 726, -5273, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		MARIO_POS(0x01, -160, -4256, 1893, 4788),
		OBJECT(MODEL_NIPPER, -3862, 4932, -5875, 0, 0, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -3263, 3326, -6519, 0, 0, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 4476, 520, -5345, 0, 93, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 4476, 520, -4095, 0, 146, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 3478, 520, -6356, 0, 116, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -226, 2275, 3733, 0, -97, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -1529, 2956, 5373, 0, 52, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_TREE_NUT, -2705, 2296, -1056, 0, 0, 0, 0x00000000, bhvTreeNut),
		OBJECT(MODEL_TREE_NUT, -838, 2089, -4859, 0, 0, 0, 0x00000000, bhvTreeNut),
		OBJECT(MODEL_TREE_NUT, 1960, 1689, 135, 0, 0, 0, 0x00000000, bhvTreeNut),
		OBJECT(MODEL_RED_COIN, -5568, 1570, 6367, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7051, 1729, 3073, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -553, 1669, -667, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1791, 3495, -2217, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1017, 4294, -5934, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2421, 4007, -5790, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -6461, 3326, -4845, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2482, 1586, 1271, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -4256, 1893, 4788, 0, -160, 0, (0x0A << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -637, 3446, 4795, 0, 0, 0, (2 << 16), bhvStar),
		OBJECT(MODEL_NONE, -3161, 5284, -2729, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -6599, 5291, -1847, 0, 0, 0, (2 << 16), bhvStar),
		OBJECT(MODEL_NONE, -5096, 1921, 6724, 0, 0, 0, (3 << 16), bhvHiddenRedCoinStar),
		TERRAIN(wdw_area_1_collision),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_ROUTE_47),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -160, -4256, 1893, 4788),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
