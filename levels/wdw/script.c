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
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
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
	LOAD_MODEL_FROM_GEO(MODEL_BARON, baron_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GODDARD_FIST, gfist_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BARON_PANCAKE, kpancake_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUE_COIN, -1622, 2176, 4137, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -378, 2270, 3726, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 581, 2504, 4654, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1374, 2957, 5456, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -59, 2730, 5792, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -2460, 1929, 3037, 0, 0, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BLOOPER, 539, 1236, -631, 0, -42, 0, 0x00000000, bhvBlooper),
		OBJECT_WITH_ACTS(MODEL_BARON, 2447, 7092, -4813, 0, 0, 0, 0x00000000, bhvKingBobomb, ACT_1),
		OBJECT(MODEL_BOBOMB_BUDDY, -755, 4352, -5920, 0, 0, 0, 0x00000000, bhvBobombBuddyOpensCannon),
		OBJECT(MODEL_BOBOMB_BUDDY, -4746, 1897, 4374, 0, 0, 0, (114 << 16), bhvBobombBuddy),
		OBJECT(MODEL_DL_CANNON_LID, -3968, 4912, -6122, 0, 0, 0, 0x00000000, bhvCannonClosed),
		OBJECT(MODEL_YELLOW_COIN, 2823, 2357, -2802, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3387, 2708, -2924, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3783, 2753, -3137, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4180, 2938, -3520, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4476, 3250, -4028, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4570, 3553, -4559, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4520, 3763, -5068, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4417, 3962, -5638, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 1529, 712, -3131, 0, 66, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6060, 1612, -3009, 0, -47, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1097, 1689, 175, 0, -60, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1634, 3326, -1880, 0, -67, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4688, 3326, -6299, 0, -70, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3240, 2089, 941, 0, -19, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5101, 1729, 2016, 0, -115, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5080, 1947, 3302, 0, -141, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1095, 1152, -6410, 0, 127, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1897, 546, 510, 0, -102, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -640, 3186, 4790, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7050, 3451, -1903, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1652, 2121, -610, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4038, 4529, -4123, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5231, 3813, -1859, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3087, 2089, -1487, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4514, 3970, -3096, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5790, 3326, -5253, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6403, 506, -5104, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3077, 2089, -1714, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1652, 827, -610, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_DIRT_PILE, -4978, 1897, 4694, 0, 0, 0, (4 << 16), bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, -3201, 3326, -6972, 0, 0, 0, (4 << 16), bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, -3365, 4928, -2918, 0, 0, 0, (4 << 16), bhvDirtPile),
		OBJECT(MODEL_GALOOMBA, -2972, 2089, -1468, 0, -42, 0, 0x00000000, bhvGaloomba),
		OBJECT(MODEL_GALOOMBA, -1121, 2089, -3940, 0, 68, 0, 0x00000000, bhvGaloomba),
		OBJECT(MODEL_GALOOMBA, 2329, 1689, -196, 0, -42, 0, 0x00000000, bhvGaloomba),
		OBJECT(MODEL_NONE, -2970, 2089, -1485, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -2294, 3326, -2800, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -4760, 4150, -3549, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 6408, 726, -5273, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		MARIO_POS(0x01, -160, -4256, 1893, 4788),
		OBJECT(MODEL_NIPPER, -3691, 4932, -5633, 0, 0, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -3284, 3326, -6187, 0, 0, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 3662, 3616, -6195, 0, 93, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -4626, 3640, -5225, 0, 0, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 2603, 1650, -5314, 0, 93, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 299, 982, -4475, 0, 146, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, 2909, 1492, -6254, 0, 116, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -226, 2275, 3733, 0, -97, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_NIPPER, -1529, 2956, 5373, 0, 52, 0, 0x00000000, bhvNipper),
		OBJECT(MODEL_RED_COIN, 5662, 1173, -6433, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7051, 1729, 3073, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -553, 1863, -667, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1791, 3495, -2217, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -638, 3744, 4789, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7049, 4033, -1906, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5784, 3326, -5258, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2482, 1586, 1271, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -4256, 1893, 4788, 0, -160, 0, (0x0A << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 2264, 4509, -4815, 0, 0, 0, (1 << 24), bhvStarNoRoom),
		OBJECT(MODEL_NONE, -6252, 5291, -1876, 0, 0, 0, (2 << 24), bhvStarNoRoom),
		OBJECT(MODEL_NONE, -5096, 1921, 6724, 0, 0, 0, 0x03000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, -2127, 661, -570, 0, 0, 0, (5 << 24), bhvStarNoRoom),
		OBJECT(MODEL_MAPLETREE, -6727, 1729, 3081, 0, 0, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_TREE_NUT, -6060, 2052, 3139, 0, 0, 0, 0x00000000, bhvTreeNut),
		OBJECT(MODEL_TREE_NUT, -4238, 3987, -5733, 0, 0, 0, 0x00000000, bhvTreeNut),
		OBJECT(MODEL_TREE_NUT, -817, 4634, -6148, 0, 0, 0, 0x00000000, bhvTreeNut),
		OBJECT(MODEL_MAPLETREE, 1702, 2089, -1487, 0, -57, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_MAPLETREE, 401, 2089, -2454, 0, 93, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_MAPLETREE, 5012, 502, -7212, 0, -57, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -2941, 3058, -946, 0, 0, 0, (3 << 24) | (5 << 16), bhvAdjacentRoomInitializer),
		OBJECT(MODEL_NONE, 6014, 5494, -6068, 0, 0, 0, (1 << 24) | (3 << 16), bhvAdjacentRoomInitializer),
		OBJECT(MODEL_NONE, 3499, 1698, -5401, 0, 0, 0, (2 << 24), bhvAdjacentRoomInitializer),
		OBJECT(MODEL_NONE, -1088, 5494, -4603, 0, 0, 0, (1 << 24) | (6 << 16), bhvAdjacentRoomInitializer),
		OBJECT(MODEL_NONE, -4368, 5494, -4362, 0, 0, 0, (1 << 24) | (5 << 16), bhvAdjacentRoomInitializer),
		TERRAIN(wdw_area_1_collision),
		ROOMS(wdw_area_1_collision_rooms),
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
