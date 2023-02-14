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
#include "levels/bitfs/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitfs_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bitfs_geo_0004B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, bitfs_geo_0004C8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, bitfs_geo_0004E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, bitfs_geo_0004F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, bitfs_geo_000510), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, bitfs_geo_000528), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, bitfs_geo_000540), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, bitfs_geo_000558), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, bitfs_geo_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, bitfs_geo_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, bitfs_geo_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, bitfs_geo_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, bitfs_geo_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, bitfs_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, bitfs_geo_000600), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, bitfs_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13, bitfs_geo_000630), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14, bitfs_geo_000648), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_15, bitfs_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_PLATFORM_ON_TRACK, bitfs_geo_000758), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TILTING_SQUARE_PLATFORM, bitfs_geo_0006C0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SINKING_PLATFORMS, bitfs_geo_000770), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_BLUE_POLE, bitfs_geo_0006A8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SINKING_CAGE_PLATFORM, bitfs_geo_000690), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_ELEVATOR, bitfs_geo_000678), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_STRETCHING_PLATFORMS, bitfs_geo_000708), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SEESAW_PLATFORM, bitfs_geo_000788), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_MOVING_SQUARE_PLATFORM, bitfs_geo_000728), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SLIDING_PLATFORM, bitfs_geo_000740), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TUMBLING_PLATFORM_PART, bitfs_geo_0006D8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TUMBLING_PLATFORM, bitfs_geo_0006F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CHEEZE_PLAT, cheezeplat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHEEZE_BOMB_WALL, cheezebombwall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHEEZE_BOMB_WALL2, cheeze_bombwall2_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitfs_area_1),
		WARP_NODE(0x0A, LEVEL_BITFS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BOWSER_2, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BITFS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, -14456, 0),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_NONE, 8247, 5617, -1943, 0, 0, 0, (0 << 16), bhvBowserCourseRedCoinStar),
		OBJECT(MODEL_NONE, 8247, 5617, -1943, 0, 0, 0, (0xA << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_CANNON_BASE, -1323, -15150, 0, 0, 0, 0, 0x00000000, bhvCannon),
		OBJECT(MODEL_NONE, 0, -14456, 0, 0, 0, 0, 0x000A0000, bhvWindSoundLoop),
		OBJECT(MODEL_GOOMBA, 9054, -4891, -329, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 9517, -4891, -936, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8630, -4891, -1693, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 9070, -4891, -1674, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8210, -4891, -59, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_CHEEZE_PLAT, 8504, -4579, -2214, 0, 0, 0, 0x00000000, bhvCheezePlat),
		OBJECT(MODEL_1UP, 15401, 3207, -4300, 0, 0, 0, (0 << 16), bhv1Up),
		OBJECT(MODEL_CHEEZE_BOMB_WALL, 4263, 3104, -6259, 0, 0, 0, 0x00000000, bhvCheezeBombWall),
		OBJECT(MODEL_DOG, 3479, 3106, -6537, 0, 0, 0, 0x00000000, bhvCheezeDog),
		OBJECT(MODEL_NONE, 5738, 3429, -8528, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 12111, 3429, -8574, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 12111, 3665, -8574, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_YELLOW_COIN, 4601, 2979, -5581, 0, 0, 0, (0 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4896, 2979, -5170, 0, 0, 0, (0 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5354, 2979, -4825, 0, 0, 0, (0 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 6125, 2979, -4557, 0, 0, 0, (0 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 6955, 2979, -4356, 0, 0, 0, (0 << 16), bhvYellowCoin),
		OBJECT(MODEL_BLUE_FLAME, 9885, 3648, -4568, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 9885, 3648, -3068, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 8747, 3648, -5204, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 7604, 3648, -2874, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 7604, 3648, -1170, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 11247, 3648, -2208, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 11247, 3648, -428, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13386, 3648, -1318, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13997, 3648, -1930, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 14610, 3648, -1318, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13997, 3648, -791, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13997, 3648, -2706, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13997, 3648, 71, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 16634, 3648, -818, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 15859, 3648, 182, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 16635, 3648, 1182, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 14247, 3648, 791, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 12247, 3648, 794, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 10247, 3648, 792, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 9360, 3648, 1682, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 9364, 3648, 3682, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 8122, 3648, 4792, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 5872, 3648, 4795, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 5872, 3648, 6567, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 8122, 3648, 6571, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 10247, 3648, 6570, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 11130, 3648, 5682, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 11130, 3648, 3682, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 12247, 3648, 2573, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 14247, 3648, 2573, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_KOOPATROL, 9880, 2867, -1396, 0, 0, 0, 0x00000000, bhvKoopatrol),
		OBJECT(MODEL_KOOPATROL, 12273, 2867, 1464, 0, 0, 0, 0x00000000, bhvKoopatrol),
		OBJECT(MODEL_KOOPATROL, 6728, 2867, 5668, 0, 0, 0, 0x00000000, bhvKoopatrol),
		OBJECT(MODEL_NONE, 10997, 2867, -1318, 0, 90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 8747, 2867, -2818, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 16247, 2867, 182, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13094, 2867, 1764, 0, 90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7321, 2867, 5690, 0, 90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10247, 2867, 3765, 0, -180, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_KOOPATROL, 14036, 2867, -240, 0, 0, 0, 0x00000000, bhvKoopatrol),
		OBJECT(MODEL_CHUCKYA, 13053, 5367, 9438, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 15732, 5367, 7633, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_FLYGUY, 12417, 6163, 8863, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 15033, 6163, 7016, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_GOOMBA, 11277, 5367, 10194, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 14231, 5367, 8914, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 16406, 5367, 6515, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 16637, 5367, 5316, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 15852, 5367, 4593, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 15418, 5492, 7350, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 12800, 5492, 9241, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 16443, 5492, 7200, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 14529, 5492, 9096, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, 4786, 5367, 6366, 0, 58, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7295, 5367, 7272, 0, 82, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 10513, 5367, 8991, 0, -173, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 14225, 5367, 8808, 0, 127, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 15884, 5367, 4802, 0, 58, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_GOOMBA, 10559, 5367, 8979, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BLUE_FLAME, 6032, 5860, 1333, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 6023, 5860, 1987, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 6621, 5860, 2326, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 7193, 5860, 1992, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 7189, 5860, 1327, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 6611, 5860, 990, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13749, 6023, 1206, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 12858, 6023, 2130, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 13636, 6023, 3629, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 11746, 6023, 3741, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 12748, 6023, 4519, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 10749, 6023, 4516, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 9746, 6023, 3743, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 8744, 6023, 4521, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 7862, 6023, 3631, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 8634, 6023, -1068, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 7858, 6023, -1068, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_FLYGUY, 7693, 5860, 2478, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 5689, 5860, 1226, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_GOOMBA, 7215, 5531, 2895, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 5642, 5531, 2540, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 5377, 5531, 1594, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 6757, 5531, 688, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8152, 5531, 471, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, 7258, 2867, 637, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 6394, 2867, 2188, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 8247, 5367, -1056, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 13310, 5367, 2548, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9950, 5367, 4172, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_KOOPATROL, 13196, 5367, 2855, 0, 0, 0, 0x00000000, bhvKoopatrol),
		OBJECT(MODEL_KOOPATROL, 11094, 5367, 4246, 0, 0, 0, 0x00000000, bhvKoopatrol),
		OBJECT(MODEL_CHEEZE_BOMB_WALL2, 8262, 7867, -2253, 0, 0, 0, (1 << 16), bhvCheezeBombWall),
		TERRAIN(bitfs_area_1_collision),
		ROOMS(bitfs_area_1_collision_rooms),
		MACRO_OBJECTS(bitfs_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SOUND_PLAYER),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, -14456, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
