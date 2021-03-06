#include "src/game/envfx_snow.h"

const GeoLayout bitdw_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4695, 1864, -10724, 0, 90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 346403),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 9697, -1652, 7909),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_final_platforms_right_side_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 13462, -3139, 7299),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_final_platforms_right_side_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8248, 1961, -10689),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_final_ring_inner_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8248, 1954, -10689),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_final_ring_outer_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8238, -186, -10701),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_final_warp_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8232, 2625, -12071),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8238, -289, -10701),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(10000, 30000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_FinalTorusLowPoly_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 10963, -5680, 11286, 0, 0, -90, bitdw_dl_first_walljumps_right_side_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9145, -7743, 7691, bitdw_dl_gateway_cube_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 8433, -6788, 9549, bitdw_dl_mid_platform_mesh_layer_5),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 5134, -3168, 8119),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5641, -4330, -65, 0, 45, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_001_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5105, -3674, 3762, 0, 45, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_002_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1949, -1287, -994, 0, 0, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_003_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -900, -452, -926, -45, 90, 90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_004_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1635, -841, -1523, 45, 90, -90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_005_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1486, -452, -926, -45, 90, 90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_006_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1083, -283, -1523, -45, -90, 90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_007_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 424, -1134, -1282, 45, 47, -90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_008_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 897, -997, -362, 0, 45, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_009_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -246, -892, -1619, 0, 45, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_010_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 548, -838, 580, 0, 45, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_011_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 6686, -1445, 2161, 0, 45, 180),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_012_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1356, -1159, 2023, -135, -38, -90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_013_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -2088, -1874, 2402, -45, 90, 90),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Cone_014_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9558, -8525, 8620, bitdw_dl_start_platform_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 6814, 1817, -9008, 0, 59, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_steppingstones_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 914, 779, 1949, bitdw_dl_Torus_023_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_Torus_023_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 8156, -4301, 8580),
		GEO_OPEN_NODE(),
			GEO_ROTATION_NODE(LAYER_OPAQUE, 51, 0, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-4096, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_first_torus_mesh_layer_1),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_first_torus_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_ROTATION_NODE(LAYER_OPAQUE, 48, 0, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(10000, 30000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Torus_009_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 5173, -1410, 6282),
		GEO_OPEN_NODE(),
			GEO_ROTATION_NODE(LAYER_OPAQUE, 0, 0, -37),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-4096, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_second_torus_mesh_layer_1),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_second_torus_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, -193, 0, 0, 0, -37),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(10000, 30000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Torus_011_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 3965, 1777, -3455),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 324, -38, 197),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-4096, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_area_2_torus_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_area_2_torus_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_RENDER_RANGE(10000, 30000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_Torus_015_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 2586, -4649, 9409),
		GEO_OPEN_NODE(),
			GEO_ROTATION_NODE(LAYER_OPAQUE, 0, 23, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-4096, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_TOWER_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 916, -2248, 32, 0, 23, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_TOWER_panel_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 3076, -2687, 47, 0, 0, 18),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_TOWER_002_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 280, -274, -1447, 0, 0, 18, bitdw_dl_TOWER_003_mesh_layer_5),
			GEO_RENDER_RANGE(10000, 30000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_TOWERLOD_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 8040, -3871, 8324),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 3855, -441, 527, 51, 0, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_first_torus_001_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1554, 1415, -1154, 51, 0, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-4096, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_first_torus_002_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 770, -3157, 2441, 51, 0, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_first_torus_003_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -4983, 4042, -2787, 0, 0, -37),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_second_torus_001_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9287, -6548, 8620, bitdw_dl_walljumps_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_walljumps_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5080, -1998, 6321, 0, 0, -37),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_water_bottom_002_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5691, -1154, 6331, 0, 0, -37),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 10000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_water_top_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bitdw_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_GREEN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bitdw_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitdw_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bitdw_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
