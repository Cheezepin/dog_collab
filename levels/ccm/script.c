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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_MAGMA_THWOMP, magma_thwomp_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SWING_BOARD, swing_board_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PROPANE_THROWER, propane_thrower_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LAVA_GRATE, lava_grate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_RAFT, castle_raft_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ASHPILE, ashpile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ASHPILE2, ashpile2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ROVERT_ELEVATOR, rovert_elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ROVERT_FLING, rovert_fling_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOAD_CAGE, toad_cage_1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOAD_CAGE_2, toad_cage_2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOAD_CAGE_3, toad_cage_3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOAD_CAGE_4, toad_cage_4_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TANK_BASE, tank_base_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TANK_HEAD, tank_head_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RMINE, rmine_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MISSILE, missile_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x33, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x65, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_1UP, 4321, 2844, 3986, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_ASHPILE, -1, 842, -287, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 3700, 891, -7130, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 4391, 891, -6866, 0, 0, 0, 0x00010000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 5817, 891, -8018, 0, 0, 0, 0x02020000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 5148, 891, -7534, 0, 0, 0, 0x00010000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 4891, 891, -8185, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 5265, 891, -8774, 0, 0, 0, 0x00030000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 5162, 891, -6754, 0, 0, 0, 0x00030000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 3917, 891, -7743, 0, 0, 0, 0x00030000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 3464, 891, -8032, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 3809, 891, -8592, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 4515, 891, -9122, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 6048, 891, -6982, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 6153, 891, -7303, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -993, 842, 2039, 0, 0, 0, 0x00010000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -81, 842, 4058, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 939, 655, 10465, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -3598, 3205, 5526, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -5641, 4161, 5222, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -6103, 4161, 5941, 0, 0, 0, 0x00010000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 7029, 2348, 6134, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 425, 842, 6213, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -1330, 842, 5246, 0, 0, 0, 0x00010000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -1779, 842, 5601, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -2862, 1098, 7207, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 1955, 1098, 6385, 0, 0, 0, 0x00010000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 708, 1807, 7768, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -3064, 2259, 6438, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 7044, 883, 11146, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, 8229, 883, 10848, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -3968, 883, -12491, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -3968, 883, -13994, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_ASHPILE, -4648, 883, -13223, 0, 0, 0, 0x00000000, bhvAshpile),
		OBJECT(MODEL_BLUE_COIN, -2946, 1186, -5187, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4146, 1186, -6387, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2946, 1453, -6387, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4146, 1453, -5187, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -672, 1304, -4827, 0, 0, 0, 0x000F0000, bhvBlueCoinSwitch),
		OBJECT(MODEL_YELLOW_COIN_NO_SHADOW, 54, 1522, 6779, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN_NO_SHADOW, -872, 1522, 6779, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN_NO_SHADOW, 204, 1522, 6779, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN_NO_SHADOW, -1022, 1522, 6779, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 3000, 1807, 8145, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 718, 623, -3567, 0, -12, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -409, 1807, 7280, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2120, 623, -6078, 0, -45, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 10426, 6447, 4447, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2811, 7803, 2559, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2811, 11298, -2806, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_CASTLE_RAFT, 0, 1, 13574, 0, 0, 0, 0x00000000, bhvCastleRaft),
		OBJECT_WITH_ACTS(MODEL_ROVERT_ELEVATOR, 11449, 3247, 4447, 0, 0, 0, 0x00000000, bhvRovertElevator, ACT_6),
		OBJECT(MODEL_ROVERT_FLING, 2811, 11998, -5443, 0, 0, 0, 0x00000000, bhvRovertFling),
		OBJECT(MODEL_BLUE_FLAME, -3632, 3848, 4161, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, -4798, 4098, 3743, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, -1855, 1251, 6711, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 936, 1251, 6705, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 1114, 12406, -9256, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 3526, 12406, -8238, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 4544, 12406, -10656, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 2132, 12406, -11674, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 2829, 12728, -9962, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_PROPANE_THROWER, 6017, 2348, 7943, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 6776, 2348, 7189, 0, 0, 0, 0x00010000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, -2946, 1186, -6387, 0, 0, 0, 0x00010000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, -4146, 1186, -5187, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 3373, 6769, 4447, 0, 0, 0, 0x00000000, bhvPropaneThrower),
		OBJECT(MODEL_PROPANE_THROWER, 4373, 6769, 4447, 0, 0, 0, 0x00010000, bhvPropaneThrower),
		OBJECT(MODEL_LAVA_GRATE, -1746, 886, -5187, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -4291, 601, 6852, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -2946, 886, -5187, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -4146, 886, -5187, 0, 0, 0, 0x00010000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -4146, 886, -6387, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -2946, 886, -6387, 0, 0, 0, 0x00010000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, 1369, 525, -1557, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, 2569, 525, -1557, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, 3969, 525, -1557, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, 5569, 525, -1557, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, 1047, 655, 11861, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -2946, 438, -4491, 0, 0, 0, 0x00000000, bhvLavaGrate),
		OBJECT(MODEL_LAVA_GRATE, -2539, 295, -13184, 0, 0, 0, 0x00000000, bhvLavaGrate),
		MARIO_POS(0x01, 0, -550, 913, -571),
		OBJECT(MODEL_RMINE, 2076, 1098, 7242, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, -752, 1052, 3182, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, -568, 1335, 6686, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 2811, 6769, 3882, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 2811, 6769, 3295, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, -58, 1304, -4063, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 2219, 623, -6530, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 1028, 623, -3548, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 6919, 1502, 453, -46, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, -117, 1095, 6544, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, -2338, 1998, 7957, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_RMINE, 1164, 1807, 8752, 0, 0, 0, 0x00000000, bhv_rmine),
		OBJECT(MODEL_MOTOS, -1600, 842, 6306, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, -4435, 3593, 4415, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, -5247, 3947, 4530, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, 1823, 1807, 7861, 0, 129, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, 7625, 883, 11599, 0, -87, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_MOTOS, 7625, 883, 10487, 0, -19, 0, 0x00000000, bhvMotos),
		OBJECT(MODEL_PODOBOO, -941, 1379, 1280, 0, -180, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 33, 1629, 3188, 0, -180, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, -5876, 4391, 7884, 0, -180, 0, 0x00050000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, -5876, 4391, 9347, 0, -180, 0, 0x00050000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, -5876, 4649, 10708, 0, -180, 0, 0x00060000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 1309, 941, -4869, 0, -32, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 1016, 1107, -5016, 0, -24, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, -376, 774, 3424, 0, -180, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 2569, 1237, -1557, 0, -90, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 3969, 1237, -1557, 0, -90, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 12147, 1209, 5423, 0, -180, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 12685, 1209, 6356, 0, -84, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 13002, 1209, 5616, 0, -46, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 12601, 1209, 4698, 0, 19, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 13596, 1209, 5286, 0, 29, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 11356, 1209, -5923, 0, -125, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 12428, 1209, -5820, 0, -30, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 12010, 1209, -6508, 0, 9, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 11030, 1209, -6713, 0, 74, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_PODOBOO, 12086, 1209, -7183, 0, 83, 0, 0x00000000, bhvPodoboo),
		OBJECT(MODEL_RED_COIN, -377, 661, 3679, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5876, 3732, 6603, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2607, 845, 7184, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4146, 463, -6387, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4646, 1061, -7544, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4718, 845, 6113, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6918, 655, -732, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6776, 2572, 7189, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -409, 1098, 5702, 0, 0, 0, 0x03000000, bhvHiddenRedCoinStar),
		OBJECT_WITH_ACTS(MODEL_WOODEN_SIGNPOST, 11073, 3247, 4447, 0, -90, 0, 0x00050000, bhvMessagePanel, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(MODEL_WOODEN_SIGNPOST, 11073, 3247, 4447, 0, -90, 0, 0x00050000, bhvMessagePanel, ACT_4 | ACT_5),
		OBJECT(MODEL_WOODEN_SIGNPOST, 2692, 623, -6212, 0, -90, 0, 0x00040000, bhvMessagePanel),
		OBJECT(MODEL_NONE, -502, 1165, -571, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, -5876, 4493, 11353, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -3968, 1173, -13261, 0, 0, 0, 0x01000000, bhvStar),
		OBJECT(MODEL_MOTOS, 3199, 2354, 9906, 0, -180, 0, 0x00000000, bhvStaticMotos),
		OBJECT(MODEL_MOTOS, -1049, 2354, -3107, 0, 93, 0, 0x00000000, bhvStaticMotos),
		OBJECT(MODEL_MOTOS, 10250, 1301, -5010, 0, 127, 0, 0x00010000, bhvStaticMotos),
		OBJECT(MODEL_MOTOS, 12110, 1301, -9061, 0, -25, 0, 0x00010000, bhvStaticMotos),
		OBJECT(MODEL_SWING_BOARD, -5676, 4126, 6586, 13, 0, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -5676, 3983, 7433, 13, 0, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -5676, 3907, 8085, 0, 0, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -5676, 3907, 8572, 0, 0, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -6076, 3907, 8327, 0, -180, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -6076, 3929, 9554, 8, -180, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -6076, 3998, 10026, 8, -180, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -6076, 4072, 10535, 8, -180, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -5676, 4051, 10266, -8, 0, 0, 0x00000000, bhvSwingBoard),
		OBJECT(MODEL_SWING_BOARD, -5676, 3970, 9782, -8, 0, 0, 0x00000000, bhvSwingBoard),
		OBJECT_WITH_ACTS(MODEL_TANK_BASE, 2829, 11997, -9962, 0, 0, 0, 0x05000000, bhvTankBase, ACT_6),
		OBJECT(MODEL_MAGMA_THWOMP, -3427, 3072, 7293, 0, 0, 0, 0x00000000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, -3427, 3072, 6452, 0, 0, 0, 0x00010000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, 6918, 2080, 4914, 0, 0, 0, 0x00000000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, 6918, 2080, 4456, 0, 0, 0, 0x00010000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, 6918, 2080, 3999, 0, 0, 0, 0x00020000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, 6918, 2080, 3541, 0, 0, 0, 0x00030000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, 6918, 2080, 3083, 0, 0, 0, 0x00040000, bhvMagmaThwomp),
		OBJECT(MODEL_MAGMA_THWOMP, 7198, 6769, 4447, 0, 90, 0, 0x00040000, bhvMagmaThwomp),
		OBJECT_WITH_ACTS(MODEL_TOAD, -918, 842, -384, 0, 0, 0, 0x04000000, bhvRovertToad, ACT_5),
		OBJECT_WITH_ACTS(MODEL_TOAD_CAGE, -1818, 2148, 8476, 0, 0, 0, 0x00000000, bhvToadCage, ACT_5),
		OBJECT_WITH_ACTS(MODEL_TOAD_CAGE, -487, 992, 1932, 0, 0, 0, 0x00000000, bhvToadCage, ACT_5),
		OBJECT_WITH_ACTS(MODEL_TOAD_CAGE, 5759, 1041, -7561, 0, 0, 0, 0x00000000, bhvToadCage, ACT_5),
		OBJECT_WITH_ACTS(MODEL_TOAD_CAGE, 6930, 2498, 1644, 0, 0, 0, 0x00000000, bhvToadCage, ACT_5),
		OBJECT_WITH_ACTS(MODEL_TOAD_CAGE, -108, 1454, -4448, 0, 0, 0, 0x00000000, bhvToadCage, ACT_5),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_PEACH_RUINS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -550, 913, -571),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
