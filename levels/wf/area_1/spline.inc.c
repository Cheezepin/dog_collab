#include "src/game/camera.h"

struct CutsceneSplinePoint wf_area_1_spline_focus[] = {
	{ 0, 1, { 1498, 1181, 6965 }},
	{ 1, 1, { -537, 1181, 8038 }},
	{ 2, 1, { -2194, 1181, 7402 }},
	{ 3, 1, { -3886, 1181, 5361 }},
	{ 4, 1, { -4699, 1181, 3027 }},
	{ -1, 1, { -5353, 1181, 1244 }},
};
const Trajectory wf_area_1_spline_mipsPath[] = {
	TRAJECTORY_POS( 0, -436, 688, 10085),
	TRAJECTORY_POS( 1, 5785, 688, 11385),
	TRAJECTORY_POS( 2, 9315, 806, 9495),
	TRAJECTORY_END(),
};
const Trajectory wf_area_1_spline_mipsPath_001[] = {
	TRAJECTORY_POS( 0, 9042, 688, 7249),
	TRAJECTORY_POS( 1, 4881, 688, 3688),
	TRAJECTORY_POS( 2, -1899, 754, 8815),
	TRAJECTORY_END(),
};
const Trajectory wf_area_1_spline_mipsPath_002[] = {
	TRAJECTORY_POS( 0, 7630, 688, 10026),
	TRAJECTORY_POS( 1, 2262, 688, 11988),
	TRAJECTORY_POS( 2, -1852, 806, 9210),
	TRAJECTORY_END(),
};
const Trajectory wf_area_1_spline_mipsPath_003[] = {
	TRAJECTORY_POS( 0, -415, 688, 7837),
	TRAJECTORY_POS( 1, 5004, 688, 4035),
	TRAJECTORY_POS( 2, 9639, 806, 8881),
	TRAJECTORY_END(),
};

const Trajectory *const wf_seg7_trajectory_mips[] = {
    wf_area_1_spline_mipsPath,     wf_area_1_spline_mipsPath_001,
	wf_area_1_spline_mipsPath_002, wf_area_1_spline_mipsPath_003,
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
