#include "src/game/camera.h"

struct CutsceneSplinePoint wf_area_1_spline_focus[] = {
	{ 0, 1, { 1498, 1181, 6965 }},
	{ 1, 1, { -537, 1181, 8038 }},
	{ 2, 1, { -2194, 1181, 7402 }},
	{ 3, 1, { -3886, 1181, 5361 }},
	{ 4, 1, { -4699, 1181, 3027 }},
	{ -1, 1, { -5353, 1181, 1244 }},
};
struct CutsceneSplinePoint wf_area_1_spline_pos[] = {
	{ 0, 1, { 273, 1181, 8320 }},
	{ 1, 1, { -1427, 1181, 8294 }},
	{ 2, 1, { -3335, 1181, 7431 }},
	{ 3, 1, { -4332, 1181, 5294 }},
	{ 4, 1, { -4906, 1181, 3026 }},
	{ -1, 1, { -5260, 1181, 786 }},
};
const Trajectory wf_area_1_spline_ktq[] = {
	TRAJECTORY_POS( 0, -6370, 1006, 657),
	TRAJECTORY_POS( 1, -6381, 1006, 1380),
	TRAJECTORY_POS( 2, -5936, 846, 2807),
	TRAJECTORY_POS( 3, -5117, 755, 4562),
	TRAJECTORY_POS( 4, -4613, 735, 6108),
	TRAJECTORY_POS( 5, -4109, 710, 7156),
	TRAJECTORY_POS( 6, -2474, 726, 8155),
	TRAJECTORY_POS( 7, 535, 780, 7641),
	TRAJECTORY_POS( 8, 2125, 744, 6908),
	TRAJECTORY_POS( 9, 4049, 794, 4757),
	TRAJECTORY_POS( 10, 5517, 718, 4833),
	TRAJECTORY_POS( 11, 6170, 740, 5278),
	TRAJECTORY_POS( 12, 7277, 688, 7033),
	TRAJECTORY_POS( 13, 8524, 688, 8108),
	TRAJECTORY_POS( 14, 9438, 806, 9076),
	TRAJECTORY_END(),
};

// 0x07078EF8 - 0x07078F2C
static const Trajectory wf_mips_mips_0[] = {
    TRAJECTORY_POS(0, /*pos*/ -6713, 932, -1841),
    TRAJECTORY_POS(1, /*pos*/ -4713, 932, -1841),
    TRAJECTORY_END(),
};

// 0x07078F2C - 0x07078F68
static const Trajectory wf_mips_mips_1[] = {
    TRAJECTORY_POS(0, /*pos*/ -4713, 932, -2241),
    TRAJECTORY_POS(1, /*pos*/ -6713, 932, -2241),
    TRAJECTORY_END(),
};

// 0x07078F68 - 0x07078F7C
static const Trajectory wf_mips_mips_2[] = {
    TRAJECTORY_POS(0, /*pos*/ -6713, 932, -2641),
    TRAJECTORY_POS(1, /*pos*/ -4713, 932, -2641),
    TRAJECTORY_END(),
};

// 0x07078F7C - 0x07078FA8
static const Trajectory wf_mips_mips_3[] = {
    TRAJECTORY_POS(0, /*pos*/ -4713, 932, -3041),
    TRAJECTORY_POS(1, /*pos*/ -6713, 932, -3041),
    TRAJECTORY_END(),
};

// 0x07078FA8 - 0x07078FD4
static const Trajectory wf_mips_mips_4[] = {
    TRAJECTORY_POS(0, /*pos*/ -6713, 932, -3441),
    TRAJECTORY_POS(1, /*pos*/ -4713, 932, -3441),
    TRAJECTORY_END(),
};

// 0x07078FD4 - 0x07078FE8
static const Trajectory wf_mips_mips_5[] = {
    TRAJECTORY_POS(0, /*pos*/ -4713, 932, -3841),
    TRAJECTORY_POS(1, /*pos*/ -6713, 932, -3841),
    TRAJECTORY_END(),
};

// 0x07078FE8 - 0x07079004
static const Trajectory wf_mips_mips_6[] = {
    TRAJECTORY_POS(0, /*pos*/ -6713, 932, -4241),
    TRAJECTORY_POS(1, /*pos*/ -4713, 932, -4241),
    TRAJECTORY_END(),
};

// 0x07079004 - 0x07079020
static const Trajectory wf_mips_mips_7[] = {
    TRAJECTORY_POS(0, /*pos*/ -4713, 932, -4641),
    TRAJECTORY_POS(1, /*pos*/ -6713, 932, -4641),
    TRAJECTORY_END(),
};

// 0x07079020 - 0x07079044
static const Trajectory wf_mips_mips_8[] = {
    TRAJECTORY_POS(0, /*pos*/ -6713, 932, -5041),
    TRAJECTORY_POS(1, /*pos*/ -4713, 932, -5041),
    TRAJECTORY_END(),
};

// 0x07079044 - 0x07079068
static const Trajectory wf_mips_mips_9[] = {
    TRAJECTORY_POS(0, /*pos*/ -4713, 932, -5441),
    TRAJECTORY_POS(1, /*pos*/ -6713, 932, -5441),
    TRAJECTORY_END(),
};

// 0x07079068 - 0x07079090
const Trajectory *const wf_seg7_trajectory_mips[] = {
    wf_mips_mips_0, wf_mips_mips_1,
	wf_mips_mips_2, wf_mips_mips_3,
	wf_mips_mips_4, wf_mips_mips_5,
	wf_mips_mips_6, wf_mips_mips_7,
	wf_mips_mips_8, wf_mips_mips_9,
};